//����������� �������, ������� ���������� ������ ��������, ������� �������� �� ������ S1 ���� �������� �������� � ������� N1 �� ������� N2.
//����������� �������, ������� ���������� ������ ��������, ������� �������� �� ������ S1 ���� �������� �������� � ������� N1 �� ������� N2 � ������� �� ��� ����� ������ S2.
//��� ������� ��������� � ��������� �����(����������).
//����������� ������, ������������ ����������� ����������, ��� �������� ����������� ������ �������.

#include "stdafx.h"
#include <conio.h>
#include <locale.h>
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include "MLi.h"//��� ����������
using namespace std;
int _tmain()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const int size = 1024;
	char str1[size] = { 0 };
	char str2[size] = { 0 };
	int N1, N2;//N1 - ��������� ������� ��������; N2 - ��������� ������� ��������
	cout << "������� ������ -> \n\t";
	cin.getline(str1, size);
	cout << "������� � ������ �� ����� ������ ������� -> ";
	cin >> N1 >> N2;
	if (Delete(str1, N1, N2))//�������� �������� �� �������� � N1 �� N2 � �������� �� ������������ �����
	{
		cout << endl << "����� ������: " << str1 << endl << endl;
		cin.ignore();/*��� ����� �� �������� ������ getline, �� �� ������� �� ��������� ������ enter � ������������*/
		cout << "������� ������ ������(�� ����������) -> \n\t";
		cin.getline(str2, size);
		Inception(str1, str2, N1);
		cout << "����� ������: " << str1 << endl << endl;
	}
	else { cout << "������ ����� ������� ��������!"<<endl; }
	system("pause");
}
