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
	int no;                      //ѡ�ֱ��
	char name[15];              //ѡ������
	char sex;                    //�Ա�
	int age;                     //����
	int score[6];
	double sum;
}s[1000];
int shuliang = 0;
void menu(int &a);
void shuru(Singer sin[1000]);//����
void chengji(Singer sin[1000]);//�ɼ�
void chazhao(Singer s[1000]);//����
void sort1(Singer s[1000]);
void sort2(Singer s[1000]);
void xiugai(Singer sin[998]);//�޸�
void shanchu(Singer sin[998]);//ɾ��
void xianshi(Singer sin[998]);//��ʾ
void write(Singer sin[998]);//д���ļ�
int main()
{
	system("color f1");//�ı䱳����ɫ
	cout << endl;
	cout << setw(63) << "���ִ��ϵͳ" << endl;
	cout << endl;
	cout << setw(120) << "����ߣ����� " << endl;
	cout << setw(60) << "���˵�" << endl;
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
	cout << setw(31) << "1" << " * * * * * * * * * * * * * * * * * * * * * * * * * * " << "ѡ����Ϣ����" << endl;
	cout << setw(17) << "*******" << endl;
	cout << setw(18) << "*********" << setw(13) << "2" << " * * * * * * * * * * * * * * * * * * * * * * * * * * " << "��ί�ɼ�����" << endl;
	cout << setw(19) << "***********" << endl;
	cout << setw(19) << "***********" << setw(12) << "3" << " * * * * * * * * * * * * * * * * * * * * * * * * * * " << "ѡ�ֳɼ����ܷ�����" << endl;
	cout << setw(18) << "*********" << endl;
	cout << setw(17) << "*******" << setw(14) << "4" << " * * * * * * * * * * * * * * * * * * * * * * * * * * " << "ѡ�ֳɼ����������" << endl;
	cout << setw(15) << "***" << endl;
	cout << setw(15) << "***" << setw(16) << "5" << " * * * * * * * * * * * * * * * * * * * * * * * * * * " << "ѡ����Ϣ��ѯ" << endl;
	cout << setw(15) << "***" << endl;
	cout << setw(15) << "***" << setw(16) << "6" << " * * * * * * * * * * * * * * * * * * * * * * * * * * " << "ѡ����Ϣ�޸�" << endl;
	cout << setw(15) << "***" << endl;
	cout << setw(15) << "***" << setw(16) << "7" << " * * * * * * * * * * * * * * * * * * * * * * * * * * " << "ɾ��ѡ�ֳɼ�" << endl;
	cout << setw(15) << "***" << endl;
	cout << setw(15) << "***" << setw(16) << "8" << " * * * * * * * * * * * * * * * * * * * * * * * * * * " << "��ʾѡ����Ϣ���ɼ�" << endl;
	cout << setw(15) << "***" << endl;
	cout << setw(15) << "***" << setw(16) << "9" << " * * * * * * * * * * * * * * * * * * * * * * * * * * " << "����ѡ����Ϣ���ļ�" << endl;
	cout << setw(15) << "***" << endl;
	cout << setw(15) << "***" << setw(17) << "10" << " * * * * * * * * * * * * * * * * * * * * * * * * * * " << "�˳�ϵͳ" << endl;
	cout << setw(15) << "***" << endl;
	cout << setw(15) << "***" << setw(30) << "��ѡ��˵����:";
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
	case 10:a = 0;cout << endl;cout << setw(60) << "��ӭ�´�ʹ��(*^��^*)" << endl;break;
	default:cout << "����1-6֮��ѡ��" << endl;
	}
}
void shuru(Singer  sin[1000])
{
	int i, n;
	cout << "������μӴ˴α�����ѡ������(������)��";
	cin >> n;
	cout << endl;
	while (n <= 0)
	{
		cout << "��������!����������!";
		cout << "\a" << endl;
		cin >> n;
	}
	cout << "������ѡ����Ϣ(��'��'��)";
	cout << endl;
	//����ѡ����Ϣ
	for (i = 0;i < n;i++)
	{
		cout << '\n';
		cout << "��" << i + 1 << "λѡ�ֱ�ţ�";
		cin >> sin[i].no;
		cout << '\n';
		for (int j = 0;j < i;j++)
		{
			while (sin[j].no == sin[i].no)
			{
				cout << "����Ѵ��ڣ�����������!";
				cout << "\a" << endl;
				cout << endl;
				cout << "��ţ�";
				cin >> sin[i].no;
				cout << endl;
			}
		}
		cout << "������";
		cin >> sin[i].name;
		cout << '\n';
		cout << "�Ա�(Ůʿ-F����ʿ-M)��";
		cin >> sin[i].sex;
		while (sin[i].sex != 'F'&&sin[i].sex != 'M')
		{
			cout << '\n';
			cout << "�����������������룡\n";
			cout << "\a" << endl;
			cout << "�Ա�:";
			cin >> sin[i].sex;
		}
		cout << '\n';
		cout << "���䣺";
		cin >> sin[i].age;
		while ((sin[i].age < 10) || (sin[i].age > 40))
		{
			cout << endl;
			cout << "�����������������룡\n";
			cout << "\a" << endl;
			cout << "���䣺";
			cin >> sin[i].age;
		}
		cout << '\n';
	}
	cout << setw(44) << "| ѡ * �� * �� * Ϣ * �� |" << endl;
	cout << endl;
	cout << "���              ����                 �Ա�                 ����\n";
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
	cout << "�������뼸λѡ�ֵĳɼ���";
	cin >> N;
	cout << endl;
	while (N <= 0)
	{
		cout << "�����������������룡";
		cout << "\a" << endl;
		cin >> N;
	}
	for (j = 0;j < N;j++)
	{
		cout << "������ѡ�ֱ�ţ�";
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
			cout << "���ҵ��˱�ţ����������c(������)�c" << endl;
			cout << endl;
		}
		else
		{
			cout << endl;
			cout << "δ�ҵ�����ţ����������룡" << endl;
			cout << "\a" << endl;
			cout << endl;
			cout << "������ѡ�ֱ�ţ�";
			cin >> n;goto a1;
		}
		}
		k = i;
		for (i = 0;i < 6;i++)
		{
			cout << "������ɼ�" << i + 1 << ":";
			cin >> sin[k].score[i];
			cout << '\n';
			while (sin[k].score[i] < 40 || sin[k].score[i]>100)
			{
				cout << "����������������룡\n";
				cout << "\a" << endl;
				cout << endl;
				cout << "�ɼ�" << i + 1 << ":";
				cin >> sin[k].score[i];
				cout << endl;
			}
		}
	}
}
void sort1(Singer s[1000])//�����ܷ֣���ȥһ�����ֵ��һ����Сֵ
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
	cout << "��ѡ������ʽ:" << endl;
	cout << endl;
	cout << "1.����" << endl;
	cout << endl;
	cout << "2.����" << endl;
	cout << endl;
	cout << "����ѡ���ǣ�";
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
	cout << "�����Ϊ:" << endl;
	cout << "���              ����                 �Ա�                 ����                 �ɼ�\n";
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
void sort2(Singer s[1000])//ð������
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
	cout << "��ѡ������ʽ:" << endl;
	cout << endl;
	cout << "1.����" << endl;
	cout << endl;
	cout << "2.����" << endl;
	cout << endl;
	cout << "����ѡ���ǣ�";
	cin >> m;
	cout << endl;
	switch (m)
	{
	case 1:
		cout << "�����Ϊ:" << endl;
		cout << "���              ����                 �Ա�                 ����                 �ɼ�\n";
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
		cout << "�����Ϊ:" << endl;
		cout << "���              ����                 �Ա�                 ����                 �ɼ�\n";
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
	cout << "1.����ѡ�ֱ�Ž��в���\n";
	cout << endl;
	cout << "2.����ѡ���������в���\n";
	cout << endl;
	cout << "����ѡ����:";
	cin >> q;
	cout << endl;
	switch (q)
	{
	case 1:
	{
		int m, k = -1;
		cout << "�������ţ�";
		cin >> m;
		for (int j = 0;j < shuliang;j++)
		{
			if (s[j].no == m)
				k = j;
		}
		if (k == -1)
		{
			cout << "û����λ���֣������¼��顣\n\n\n\n" << endl;
			break;
		}
		cout << "���              ����                 �Ա�                 ����                 �ɼ�\n";
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
		cout << "���������֣�";
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
			cout << "���              ����                 �Ա�                 ����                 �ɼ�\n";
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
			cout << "������Ŷ����������ֱ�Ž���׼ȷ��ѯ��";
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
				cout << "û����λ���֣������¼��顣\n\n\n\n" << endl;
				cout << "\a" << endl;
				break;
			}
			cout << "���              ����                 �Ա�                 ����                 �ɼ�\n";
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
			cout << "û����λ���֣������¼��顣\n\n\n\n" << endl;
			cout << "\a" << endl;
		}
	}
	}
}
void xiugai(Singer sin[998])                                                  //�޸�ѡ����Ϣ 
{
	int ii, i, item;
	int L = shuliang;
	cout << "������Ҫ�޸ĵ�ѡ�ֵı��:";
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
		cout << "���ҵ��˱�ţ�������c(������)�c" << endl;
		cout << endl;
	}
	else
	{
		cout << "δ�ҵ�����ţ����������룡" << endl;
		cout << "\a" << endl;
		cout << endl;
		cout << "������ѡ�ֱ�ţ�";
		cin >> ii;
		cout << endl;
		goto a1;
	}
	}
	L = i;
	cout << "------------------" << endl;
	cout << endl;
	cout << "1.�� �� �� ��" << endl;
	cout << endl;
	cout << "2.�� �� �� ��" << endl;
	cout << endl;
	cout << "3.�� �� �� ��" << endl;
	cout << endl;
	cout << "4.�� �� �� ��" << endl;
	cout << endl;
	cout << "5.�� �� �� �� ��" << endl;
	cout << endl;
	cout << "------------------" << endl;
	while (1)
	{
		cout << endl;
		cout << "��ѡ���Ӳ˵����:" << endl;
		cin >> item;
		switch (item)
		{
		case 1:
			cout << endl;
			cout << "�������µ�����:" << endl;
			cin >> sin[L].name;
			break;
		case 2:
			cout << endl;
			cout << "�������µı��:" << endl;
			cin >> sin[L].no; break;
		case 3:
			cout << endl;
			cout << "�������µ�����:" << endl;
			cin >> sin[L].age;
			while ((sin[L].age < 10) || (sin[L].age > 40))
			{
				cout << "�����������������룡\n";
				cout << "\a" << endl;
				cout << endl;
				cout << "���䣺";
				cin >> sin[L].age;
			}
			break;
		case 4:
			cout << endl;
			cout << "�������µ��Ա�:" << endl;
			cin >> sin[L].sex;
			while (sin[i].sex != 'F'&&sin[i].sex != 'M')
			{
				cout << "�����������������룡\n";
				cout << "\a" << endl;
				cout << endl;
				cout << "�Ա�:";
				cin >> sin[L].sex;
			}
			break;
		case 5:
			cout << endl;
			return;
		default:cout << "����1-5֮��ѡ��" << endl;
			cout << endl;
		}
	}
}
void shanchu(Singer sin[998])                                                     //ɾ����Ϣ 
{
	int i, j, flag = 0, k = shuliang;
	int sin1;
	cout << "������Ҫɾ�����ֵı��:";
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
		cout << "δ�ҵ�����ţ����������룡" << endl;
		cout << "\a" << endl;
		cout << endl;
		cout << "������ѡ�ֱ�ţ�";
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
		cout << "ɾ���ɹ�!(*�����)\n" << endl;
		shuliang = shuliang - 1;
	}
}
void xianshi(Singer sin[998])                                                    //��ʾ��������Ϣ 
{
	int i;
	cout << "����" << shuliang << "λѡ�ֵ���Ϣ:\n";
	if (shuliang != 0)
	{
		cout << setw(44) << "| ѡ * �� * �� * Ϣ * �� |" << endl;
		cout << endl;
		cout << "���              ����                 �Ա�                 ����                 �ɼ�\n";
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
		cout << "�������������Ϣ(������)~*" << endl;
	cout << "\a" << endl;
}
void write(Singer sin[998])                                                     //������Ϣ���ļ��� 
{
	char ch;
	ofstream fout;
	ofstream fcout("data.txt");
	fout.open("data.txt");
	int i;
	cout << "������Yʹ�ļ�����";
	cin >> ch;
	if (ch = 'Y')
	{
		cerr << "����ɹ�!(^_^)\n";
	}
	fcout << setw(44) << "| ѡ * �� * �� * Ϣ * �� |" << endl;
	fcout << endl;
	fcout << "���              ����                 �Ա�                 ����                 �ɼ�\n";
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

