#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	string str;
	string temp;
	int flag;
	int k=1;												//�鿴����
	vector<string>duanlian;								//���еĶ���

	fstream inf1("D://TCR//TCR+.txt", ios::in);			//����ά��
	fstream inf2("D://TCR//TCR+.txt", ios::in);			//����ά��
	fstream inf3("D://TCR//TCR-.txt", ios::in);			//������������
	fstream inf4("D://TCR//TCR-.txt", ios::in);			//������������
	fstream outf("D://TCR//matrix.txt", ios::out);
	if ((!inf1) || (!inf2))
	{
		cout << "TCR+��ʧ��" << endl;
	}
	if ((!inf3) || (!inf4))
	{
		cout << "TCR-��ʧ��" << endl;
	}
	if (!outf)
	{
		cout << "matrix��ʧ��" << endl;
	}
	//outf << "TCR" << ",";
	while (inf1 >> str)									//���TCR+����ά��xi
	{
		for (int i = 0; i < str.length() - 2; i++)
		{
			temp = str.substr(i, 3);
			flag = 0;			//flag=0��ʾstrû��duanlian��
			for (int i = 0; i < duanlian.size(); i++)		//����str�Ƿ��Ѿ���duanlian�У�����flag=1
			{
				if (temp == duanlian[i])
				{
					flag = 1;
					break;
				}
			}
			if (!flag)				//���flag=0��str����duanlian�У�����
			{
				duanlian.push_back(temp);
				//outf << temp << ",";
			}
		}
	}
	cout << "TCR+ά�������" << endl;
	while (inf3 >> str)									//���TCR-����ά��xi
	{
		for (int i = 0; i < str.length() - 2; i++)
		{
			temp = str.substr(i, 3);
			flag = 0;										//flag=0��ʾstrû��duanlian��
			for (int i = 0; i < duanlian.size(); i++)		//����str�Ƿ��Ѿ���duanlian�У�����flag=1
			{
				if (temp == duanlian[i])
				{
					flag = 1;
					break;
				}
			}
			if (!flag)				//���flag=0��str����duanlian�У�����
			{
				duanlian.push_back(temp);
				//outf << temp << ",";
			}
		}
	}
	//outf << "class" << endl;
	cout << "TCR-ά�������" << endl;
	
	while (inf2 >> str)									//���ÿ��TCR+����������
	{
		//outf << str << " ";
		for (int i = 0; i < duanlian.size(); i++)		//����str�Ƿ��Ѿ���duanlian�У�����flag=1
		{
			flag = 0;
			for (int j = 0; j < str.length() - 2; j++)
			{
				temp = str.substr(j, 3);
				if (temp == duanlian[i])
				{
					flag = 1;
					outf << "1" << " ";
					break;
				}
			}
			if (!flag)
				outf << "0" << " ";
		}
		outf << endl;
		//outf << "1" << endl;
		cout << k++ << endl;							//�鿴����
	}
	cout << "TCR+�������������" << endl;
	while (inf4 >> str)									//���ÿ��TCR-����������
	{
		//outf << str << " ";
		for (int i = 0; i < duanlian.size(); i++)		//����str�Ƿ��Ѿ���duanlian�У�����flag=1
		{
			flag = 0;
			for (int j = 0; j < str.length() - 2; j++)
			{
				temp = str.substr(j, 3);
				if (temp == duanlian[i])
				{
					flag = 1;
					outf << "1" << " ";
					break;
				}
			}
			if (!flag)
				outf << "0" << " ";
		}
		outf << endl;
		//outf << "0" << endl;
		cout << k++ << endl;
	}
	cout << "TCR-�������������" << endl;
	
	inf1.close();
	inf2.close();
	inf3.close();
	inf4.close();
	outf.close();
	system("pause");
	return 0;
}