// ����������� ������������ � �������� ������� ��� ���������� �������� ������ ����� �������������� ���������� �� ��������� ������, 
//���� �������� ������ ���� ���������� � � ��������, � ����� �������, �����������, ����������� �� �������� ����� ���� ����������.
//������������ ����� ����� ������� ��� ��������.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <iostream>
using namespace std;
int AP(int f, int d, int n)//������� ��� ������ ����� ��
{
	int sum = f;
	for (int i = 1; i < n; i++)
	{
		sum += d;
	}
	return sum;
}
int AP_num(int n_r, int f, int d)//������� ��� ����������� ���. �� ����� ������ ��
{
	double n;
	n = ((double)(n_r - f + d) / d);
	if (n == round(n))//�������� ����� �� �����
	{
		return n;
	}
	else return n = -1;
}
int _tmain()
{
	setlocale(LC_ALL, "rus");
	int first;//������ ���� ��
	int diff;//�������� ��
	int num;//����� ����� ��
	cout << "������� ������ ���� �������������� ��������� -> ";
	cin >> first;
	cout << "������� �������� �.�. -> ";
	cin >> diff;
	do
	{
		cout << "������� ����� ����� �.�., ������� �� ������ ����� -> ";
		cin >> num;
		if (num < 0)
			cout << "\t����� ����� �.�. �� ����� ���� ������������� ��� ������ ����!\n";
	} while (num<0);
	int AriPro = AP(first, diff, num);//�������� �-��� ��� ������������ ����� ��
	cout << "�� �� [" << num << "] = " << AriPro << "\n\n\n";
	cout << "� ������ ������� ����� ����� -> ";
	int num_random = 0;//��������� ��� ��������� �� �������� �����
	cin >> num_random;
	int qwerty = AP_num(num_random, first, diff);//����� �-��� ��� ����������� �������� �� ����� ������ ��
	if (qwerty != -1)
	{
		cout << "����� " << num_random << " �������� " << qwerty << "-� ������ ������ �.�.\n\n";
	}
	else cout << "����� �� �������� ������ ������ �.�.\n\n";
	system("pause");
}
