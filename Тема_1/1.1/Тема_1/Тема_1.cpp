// ��������� ���������, ������� �� ������ ��� � ���� ������� ����� � ����� � ������������ �����. ��������, 33-�� ���� � ���� � 2 �������.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <iostream>
using namespace std;
int _tmain()
{
	setlocale(LC_ALL, "rus");
	int day;//�������� ����
	char *month[] = { "������", "�������", "����", "������", "���",
					"����", "����", "������", "��������", "�������", "������", "�������" };//������ �������� �������
	int day_n[12] = { 31, 28, 31,30, 31, 30, 31, 31, 30, 31, 30, 31 };//������ ���-�� ���� � ������ ������
	int w = 0;//���������� ��� �������� ������ ������
	cout << "������� ����� ��� -> ";
	cin>>day;
	if ((day > 0) && (day <= 365))//�������� ������� ����� � ��������� ������ ����
	{
		cout<<"�� ���������, ���: ";
		while (day > 0)//���� ��������� ���� ������� �� ���������� ����� ��� ������� ������ ������
		{
			day -= day_n[w]; //������� ����
			w++;//���������� ������ ������
		}
		cout << month[w-1]<<", "<<(day_n[w-1]+day)<<"-� �����\n\n";
	}
	else
	{
		cout<<"������������ ���� ������!\n\n";
	}
	system("pause");
}

