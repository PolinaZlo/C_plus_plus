// ����������� ��������� ��� ���������� ��������� � �������� ��������� ������� �������� � ������� ��������, 
//������� ������ ������ � ���� ��������� �������. ������� �� ����� ���������� �������������� ������� �������� ��� ���������.
//��������������� ��������� �������� � ���� ��������� �������.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;
double function(double x)
{
	double I;
	I = ((double)(sin(x)*cos(x)) / (2 + pow(sin(x), 2) - pow(cos(x), 2)));
	return I;
}
//����� ��������
double trapeze(int defin, double a, double b)
{
	double eps = 1;
	double I = 0;
	double I_pred = 1;
	for (int i = 0; i < defin; i++)//��������
	{
		eps = (double)eps / 10;
	}
	
	int n = 10;//���-�� ����������
	while (abs(I_pred - I) > eps && n<10000000)//���� ����� ���������� ���� I �� ������ ������ eps
	{
		I_pred = I;
		double h = (double)(b - a) / n;
		I = (function(a) + function(b)) / 2;//������� ��������
		for (int w = 1; w < n; w++)
		{
			I += function(a + w*h);
		}
		I *= h;
		n *= 2;
	}
	return I;
}
//����� ��������
double LisaSimpson(int defin, double a, double b)
{
	double eps = 1;
	double I = 0;
	double I_pred = 1;
	for (int i = 0; i < defin; i++)//��������
	{
		eps = (double)eps / 10;
	}
	int n = 10;//���-�� ����������
	while (abs(I_pred - I) > eps && n<10000000)//���� ����� ���������� ���� I �� ������ ������ eps
	{
		I_pred = I;
		double h = (double)(b - a) / n;
		I = function(a) + function(b);//������� ��������
		int two_four;
		for (int w = 1; w < n; w++)
		{
			if (w%2==0)//�������� ��� ���� ����� ������ ����� � 4 �� 2, ��������� �� ������ �������
			{
				two_four = 2;
			}
			else two_four = 4;
			I += function(a + w*h)*two_four;
		}
		I *= h/3;
		n *= 2;
	}
	return I;

}
int _tmain()
{
	setlocale(LC_ALL, "rus");
	double a = 0;
	double b = (double)M_PI / 2;
	double I;
	bool prov=false;
	int defin;
	cout << "������� �������� (������� �����) -> ";
	cin >> defin;
	while (prov == false)//�������� �� ��������� �����
	{	
 if (defin < 0)
		{
			cout << "�������� �� ����� ���� ������������� ��� ������ 0!\n"; prov = false;
			cout << "\n������� �������� (���-�� ������ ����� �������) -> "; cin >> defin;
		}
		else prov = true;
	}
	I = trapeze(defin, a, b);
	cout << "\n������� ��������� ��������� (����� ��������) = " << I << "\n\n";
	I = LisaSimpson(defin,a,b);
	cout << "\n������� ��������� ��������� (����� ��������) = " << I << "\n\n";
	system("pause");
}

