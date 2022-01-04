#include <iostream>
#include<windows.h> 
#include<mmsystem.h>
#pragma comment (lib,"WINMM.LIB") 
#include<fstream>
#include <iomanip>
#include<cmath>
#include<string>
using namespace std;
struct Singer
{
	int no;                      //选手编号
	char name[15];              //选手姓名
	char sex;                    //性别
	int age;                     //年龄
	int score[6];
	double sum;
}s[1000];
int shuliang = 0;
void menu(int &a);
void shuru(Singer sin[1000]);//输入
void chengji(Singer sin[1000]);//成绩
void chazhao(Singer s[1000]);//查找
void sort1(Singer s[1000]);
void sort2(Singer s[1000]);
void xiugai(Singer sin[998]);//修改
void shanchu(Singer sin[998]);//删除
void xianshi(Singer sin[998]);//显示
void write(Singer sin[998]);//写入文件
int main()
{
	system("color f1");//改变背景颜色
	cout << endl;
	cout << setw(63) << "歌手打分系统" << endl;
	cout << endl;
	cout << setw(120) << "设计者：任容 " << endl;
	cout << setw(60) << "主菜单" << endl;
	cout << endl;
	Singer *psinger = new Singer;
	mciSendString(TEXT("open  E:/Pity.mp3 "), 0, 0, 0);
	mciSendString(TEXT("play E:/Pity.mp3  repeat "), 0, 0, 0);
	int k = 1;
	while (k)
	{
		menu(k);
	}
	delete[]psinger;
	return 0;
}
void menu(int &a)
{
	int number;
	cout << setw(31) << "1" << " * * * * * * * * * * * * * * * * * * * * * * * * * * " << "选手信息输入" << endl;
	cout << setw(17) << "*******" << endl;
	cout << setw(18) << "*********" << setw(13) << "2" << " * * * * * * * * * * * * * * * * * * * * * * * * * * " << "评委成绩输入" << endl;
	cout << setw(19) << "***********" << endl;
	cout << setw(19) << "***********" << setw(12) << "3" << " * * * * * * * * * * * * * * * * * * * * * * * * * * " << "选手成绩按总分排序" << endl;
	cout << setw(18) << "*********" << endl;
	cout << setw(17) << "*******" << setw(14) << "4" << " * * * * * * * * * * * * * * * * * * * * * * * * * * " << "选手成绩按编号排序" << endl;
	cout << setw(15) << "***" << endl;
	cout << setw(15) << "***" << setw(16) << "5" << " * * * * * * * * * * * * * * * * * * * * * * * * * * " << "选手信息查询" << endl;
	cout << setw(15) << "***" << endl;
	cout << setw(15) << "***" << setw(16) << "6" << " * * * * * * * * * * * * * * * * * * * * * * * * * * " << "选手信息修改" << endl;
	cout << setw(15) << "***" << endl;
	cout << setw(15) << "***" << setw(16) << "7" << " * * * * * * * * * * * * * * * * * * * * * * * * * * " << "删除选手成绩" << endl;
	cout << setw(15) << "***" << endl;
	cout << setw(15) << "***" << setw(16) << "8" << " * * * * * * * * * * * * * * * * * * * * * * * * * * " << "显示选手信息及成绩" << endl;
	cout << setw(15) << "***" << endl;
	cout << setw(15) << "***" << setw(16) << "9" << " * * * * * * * * * * * * * * * * * * * * * * * * * * " << "保存选手信息于文件" << endl;
	cout << setw(15) << "***" << endl;
	cout << setw(15) << "***" << setw(17) << "10" << " * * * * * * * * * * * * * * * * * * * * * * * * * * " << "退出系统" << endl;
	cout << setw(15) << "***" << endl;
	cout << setw(15) << "***" << setw(30) << "请选择菜单编号:";
	cin >> number;
	switch (number)
	{
	case 1:system("cls");shuru(s);break;
	case 2:system("cls");chengji(s);break;
	case 3:system("cls");sort1(s);break;
	case 4:system("cls");sort2(s);break;
	case 5:system("cls");chazhao(s);break;
	case 6:system("cls");xiugai(s);break;
	case 7:system("cls");shanchu(s);break;
	case 8:system("cls");xianshi(s);break;
	case 9:system("cls");write(s);break;
	case 10:a = 0;cout << endl;cout << setw(60) << "欢迎下次使用(*^▽^*)" << endl;break;
	default:cout << "请在1-6之间选择" << endl;
	}
}
void shuru(Singer  sin[1000])
{
	int i, n;
	cout << "请输入参加此次比赛的选手人数(正整数)：";
	cin >> n;
	cout << endl;
	while (n <= 0)
	{
		cout << "输入有误!请重新输入!";
		cout << "\a" << endl;
		cin >> n;
	}
	cout << "请输入选手信息(〃'▽'〃)";
	cout << endl;
	//输入选手信息
	for (i = 0;i < n;i++)
	{
		cout << '\n';
		cout << "第" << i + 1 << "位选手编号：";
		cin >> sin[i].no;
		cout << '\n';
		for (int j = 0;j < i;j++)
		{
			while (sin[j].no == sin[i].no)
			{
				cout << "编号已存在！请重新输入!";
				cout << "\a" << endl;
				cout << endl;
				cout << "编号：";
				cin >> sin[i].no;
				cout << endl;
			}
		}
		cout << "姓名：";
		cin >> sin[i].name;
		cout << '\n';
		cout << "性别(女士-F、男士-M)：";
		cin >> sin[i].sex;
		while (sin[i].sex != 'F'&&sin[i].sex != 'M')
		{
			cout << '\n';
			cout << "输入有误！请重新输入！\n";
			cout << "\a" << endl;
			cout << "性别:";
			cin >> sin[i].sex;
		}
		cout << '\n';
		cout << "年龄：";
		cin >> sin[i].age;
		while ((sin[i].age < 10) || (sin[i].age > 40))
		{
			cout << endl;
			cout << "输入有误！请重新输入！\n";
			cout << "\a" << endl;
			cout << "年龄：";
			cin >> sin[i].age;
		}
		cout << '\n';
	}
	cout << setw(44) << "| 选 * 手 * 信 * 息 * 表 |" << endl;
	cout << endl;
	cout << "编号              姓名                 性别                 年龄\n";
	cout.precision(4);
	for (i = 0;i < n;i++)
	{
		cout << s[i].no;
		cout << setw(15) << "" << s[i].name;
		cout << setw(18) << s[i].sex;
		cout << setw(22) << s[i].age;
		cout << endl;
	}
	shuliang = shuliang + n;
}
void chengji(Singer  sin[1000])
{
	int i, n, N, j, k;
	cout << "您想输入几位选手的成绩：";
	cin >> N;
	cout << endl;
	while (N <= 0)
	{
		cout << "输入有误！请重新输入！";
		cout << "\a" << endl;
		cin >> N;
	}
	for (j = 0;j < N;j++)
	{
		cout << "请输入选手编号：";
		cin >> n;
	a1: {
		int k = shuliang;
		for (i = 0;i < shuliang;i++)
			if (sin[i].no == n)
			{
				k = i;
				break;
			}
		if (k < shuliang)
		{
			cout << endl;
			cout << "查找到此编号，请继续输入ヽ(￣▽￣)ヽ" << endl;
			cout << endl;
		}
		else
		{
			cout << endl;
			cout << "未找到此序号，请重新输入！" << endl;
			cout << "\a" << endl;
			cout << endl;
			cout << "请输入选手编号：";
			cin >> n;goto a1;
		}
		}
		k = i;
		for (i = 0;i < 6;i++)
		{
			cout << "请输入成绩" << i + 1 << ":";
			cin >> sin[k].score[i];
			cout << '\n';
			while (sin[k].score[i] < 40 || sin[k].score[i]>100)
			{
				cout << "输入错误！请重新输入！\n";
				cout << "\a" << endl;
				cout << endl;
				cout << "成绩" << i + 1 << ":";
				cin >> sin[k].score[i];
				cout << endl;
			}
		}
	}
}
void sort1(Singer s[1000])//计算总分，减去一个最大值，一个最小值
{
	double fmark, fmax, fmin;
	int i, k, j, m;
	for (int g = 0;g < shuliang;g++)
	{
		fmark = 0;
		fmax = fmin = s[g].score[0];
		for (int h = 0;h < 6;h++)
		{
			if (s[g].score[h] > fmax)
				fmax = s[g].score[h];
			if (s[g].score[h] < fmin)
				fmin = s[g].score[h];
			fmark += s[g].score[h];
			s[g].sum = fmark - fmax - fmin;
		}
	}
	cout << "请选择排序方式:" << endl;
	cout << endl;
	cout << "1.正序" << endl;
	cout << endl;
	cout << "2.倒序" << endl;
	cout << endl;
	cout << "您的选择是：";
	cin >> m;
	cout << endl;
	switch (m)
	{
	case 1:
		for (i = 0;i < shuliang - 1;i++)
		{
			Singer temp;
			k = i;
			for (j = i + 1;j < shuliang;j++)
			{
				if (s[k].sum < s[j].sum)
					k = j;
				if (k != i)
				{
					temp = s[i];
					s[i] = s[k];
					s[k] = temp;
				}
			}
		}
		break;
	case 2:
		for (i = 0;i < shuliang - 1;i++)
		{
			Singer temp;
			k = i;
			for (j = i + 1;j < shuliang;j++)
				if (s[k].sum > s[j].sum)
					k = j;
			if (k != i)
			{
				temp = s[i];
				s[i] = s[k];
				s[k] = temp;
			}
		}

		break;
	}
	cout << "排序后为:" << endl;
	cout << "编号              姓名                 性别                 年龄                 成绩\n";
	cout.precision(4);
	for (i = 0;i < shuliang;i++)
	{
		cout << s[i].no;
		cout << setw(15) << "" << s[i].name;
		cout << setw(18) << s[i].sex;
		cout << setw(22) << s[i].age;
		cout << setw(22) << s[i].sum;
		cout << endl;
	}
}
void sort2(Singer s[1000])//冒泡排序
{
	Singer temp;
	int i, j, flag, k, m;
	for (i = 0;i < shuliang - 1;i++)
	{
		Singer temp;
		k = i;
		for (j = i + 1;j < shuliang;j++)
		{
			if (s[k].no > s[j].no)
				k = j;
			if (k != i)
			{
				temp = s[i];
				s[i] = s[k];
				s[k] = temp;
			}
		}
	}
	cout << "请选择排序方式:" << endl;
	cout << endl;
	cout << "1.正序" << endl;
	cout << endl;
	cout << "2.倒序" << endl;
	cout << endl;
	cout << "您的选择是：";
	cin >> m;
	cout << endl;
	switch (m)
	{
	case 1:
		cout << "排序后为:" << endl;
		cout << "编号              姓名                 性别                 年龄                 成绩\n";
		cout.precision(4);
		for (i = 0;i < shuliang;i++)
		{
			cout << s[i].no;
			cout << setw(15) << "" << s[i].name;
			cout << setw(18) << s[i].sex;
			cout << setw(22) << s[i].age;
			cout << setw(22) << s[i].sum;
			cout << endl;
		}
		break;
	case 2:
		cout << "排序后为:" << endl;
		cout << "编号              姓名                 性别                 年龄                 成绩\n";
		cout.precision(4);
		for (i = shuliang;i > 0;i--)
		{
			cout << s[i - 1].no;
			cout << setw(15) << "" << s[i - 1].name;
			cout << setw(18) << s[i - 1].sex;
			cout << setw(22) << s[i - 1].age;
			cout << setw(22) << s[i - 1].sum;
			cout << endl;
		}
		break;
	}
}
void chazhao(Singer  s[1000])
{
	system("color f1");
	int q, h = 0;
	cout << "1.根据选手编号进行查找\n";
	cout << endl;
	cout << "2.根据选手姓名进行查找\n";
	cout << endl;
	cout << "您的选择是:";
	cin >> q;
	cout << endl;
	switch (q)
	{
	case 1:
	{
		int m, k = -1;
		cout << "请输入编号：";
		cin >> m;
		for (int j = 0;j < shuliang;j++)
		{
			if (s[j].no == m)
				k = j;
		}
		if (k == -1)
		{
			cout << "没有这位歌手，请重新检验。\n\n\n\n" << endl;
			break;
		}
		cout << "编号              姓名                 性别                 年龄                 成绩\n";
		cout.precision(4);
		cout << s[k].no;
		cout << setw(15) << "" << s[k].name;
		cout << setw(18) << s[k].sex;
		cout << setw(22) << s[k].age;
		cout << setw(22) << s[k].sum;
		cout << endl;
		break;
	}
	case 2:
	{
		int m;
		char b[1000];
		cout << "请输入名字：";
		cin >> b;
		int y = 0;
		for (int l = 0;l < shuliang;l++)
		{
			if (!(strcmp(s[l].name, b)))
			{
				h++;
				if (h == 1)
				{
					y = l;
				}
			}
		}
		if (h == 1)
		{
			cout << "编号              姓名                 性别                 年龄                 成绩\n";
			cout.precision(4);
			cout << s[y].no;
			cout << setw(15) << "" << s[y].name;
			cout << setw(18) << s[y].sex;
			cout << setw(22) << s[y].age;
			cout << setw(22) << s[y].sum;
			cout << endl;
		}
		else if (h > 1)
		{
			cout << "有重名哦！请输入歌手编号进行准确查询：";
			cout << "\a" << endl;
			int m, k = -1;
			cin >> m;
			for (int j = 0;j < shuliang;j++)
			{
				if (s[j].no == m)
					k = j;
			}
			if (k == -1)
			{
				cout << "没有这位歌手，请重新检验。\n\n\n\n" << endl;
				cout << "\a" << endl;
				break;
			}
			cout << "编号              姓名                 性别                 年龄                 成绩\n";
			cout.precision(4);
			cout << s[k].no;
			cout << setw(15) << "" << s[k].name;
			cout << setw(18) << s[k].sex;
			cout << setw(22) << s[k].age;
			cout << setw(22) << s[k].sum;
			cout << endl;
			break;
		}
		else
		{
			cout << "没有这位歌手，请重新检验。\n\n\n\n" << endl;
			cout << "\a" << endl;
		}
	}
	}
}
void xiugai(Singer sin[998])                                                  //修改选手信息 
{
	int ii, i, item;
	int L = shuliang;
	cout << "请输入要修改的选手的编号:";
	cin >> ii;
	cout << endl;
a1: {
	for (i = 0;i < shuliang;i++)
		if (sin[i].no == ii)
		{
			L = i;
			break;
		}
	if (L < shuliang)
	{
		cout << "查找到此编号，请继续ヽ(￣▽￣)ヽ" << endl;
		cout << endl;
	}
	else
	{
		cout << "未找到此序号，请重新输入！" << endl;
		cout << "\a" << endl;
		cout << endl;
		cout << "请输入选手编号：";
		cin >> ii;
		cout << endl;
		goto a1;
	}
	}
	L = i;
	cout << "------------------" << endl;
	cout << endl;
	cout << "1.修 改 姓 名" << endl;
	cout << endl;
	cout << "2.修 改 编 号" << endl;
	cout << endl;
	cout << "3.修 改 年 龄" << endl;
	cout << endl;
	cout << "4.修 改 性 别" << endl;
	cout << endl;
	cout << "5.退 出 本 菜 单" << endl;
	cout << endl;
	cout << "------------------" << endl;
	while (1)
	{
		cout << endl;
		cout << "请选择子菜单编号:" << endl;
		cin >> item;
		switch (item)
		{
		case 1:
			cout << endl;
			cout << "请输入新的姓名:" << endl;
			cin >> sin[L].name;
			break;
		case 2:
			cout << endl;
			cout << "请输入新的编号:" << endl;
			cin >> sin[L].no; break;
		case 3:
			cout << endl;
			cout << "请输入新的年龄:" << endl;
			cin >> sin[L].age;
			while ((sin[L].age < 10) || (sin[L].age > 40))
			{
				cout << "输入有误！请重新输入！\n";
				cout << "\a" << endl;
				cout << endl;
				cout << "年龄：";
				cin >> sin[L].age;
			}
			break;
		case 4:
			cout << endl;
			cout << "请输入新的性别:" << endl;
			cin >> sin[L].sex;
			while (sin[i].sex != 'F'&&sin[i].sex != 'M')
			{
				cout << "输入有误！请重新输入！\n";
				cout << "\a" << endl;
				cout << endl;
				cout << "性别:";
				cin >> sin[L].sex;
			}
			break;
		case 5:
			cout << endl;
			return;
		default:cout << "请在1-5之间选择" << endl;
			cout << endl;
		}
	}
}
void shanchu(Singer sin[998])                                                     //删除信息 
{
	int i, j, flag = 0, k = shuliang;
	int sin1;
	cout << "请输入要删除歌手的编号:";
	cin >> sin1;
	cout << endl;
a1: {
	for (i = 0;i < shuliang;i++)
		if (sin[i].no == sin1)
		{
			k = i;
			break;
		}
	if (k < shuliang)
	{
		flag = 1;
	}
	else
	{
		cout << "未找到此序号，请重新输入！" << endl;
		cout << "\a" << endl;
		cout << endl;
		cout << "请输入选手编号：";
		cin >> sin1;
		cout << endl;
		goto a1;
	}
	}
	k = i;
	if (flag == 1)
	{
		for (j = k;j < shuliang;j++)
		{
			sin[j] = sin[j + 1];
		}
		cout << "删除成功!(*￣︶￣)\n" << endl;
		shuliang = shuliang - 1;
	}
}
void xianshi(Singer sin[998])                                                    //显示所有人信息 
{
	int i;
	cout << "共有" << shuliang << "位选手的信息:\n";
	if (shuliang != 0)
	{
		cout << setw(44) << "| 选 * 手 * 信 * 息 * 表 |" << endl;
		cout << endl;
		cout << "编号              姓名                 性别                 年龄                 成绩\n";
		cout.precision(4);
		for (i = 0;i < shuliang;i++)
		{
			cout << sin[i].no;
			cout << setw(15) << "" << sin[i].name;
			cout << setw(18) << sin[i].sex;
			cout << setw(22) << sin[i].age;
			cout << setw(22) << sin[i].sum;
			cout << endl;
		}
	}
	else
		cout << "请先输入歌手信息(￣▽￣)~*" << endl;
	cout << "\a" << endl;
}
void write(Singer sin[998])                                                     //保存信息于文件中 
{
	char ch;
	ofstream fout;
	ofstream fcout("data.txt");
	fout.open("data.txt");
	int i;
	cout << "请输入Y使文件保存";
	cin >> ch;
	if (ch = 'Y')
	{
		cerr << "保存成功!(^_^)\n";
	}
	fcout << setw(44) << "| 选 * 手 * 信 * 息 * 表 |" << endl;
	fcout << endl;
	fcout << "编号              姓名                 性别                 年龄                 成绩\n";
	fcout.precision(4);
	for (i = 0;i < shuliang;i++)
	{
		fcout << sin[i].no;
		fcout << setw(15) << "" << sin[i].name;
		fcout << setw(18) << sin[i].sex;
		fcout << setw(22) << sin[i].age;
		fcout << setw(22) << sin[i].sum;
		fcout << endl;
	}
	fcout.close();
}

