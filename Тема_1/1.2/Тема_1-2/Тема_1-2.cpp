// ��������� ���������, ������� ��������� ������ �����������. ������������ ������ ���������� ����� � ������, ����� ��������� 
//���������� �������� ������ ������� �� ������ ������ �� ������, �� ��������� ������� ����� ��������� ������ �������!�, � 
//������������ � ����� �����. ����� �� ��������� ��� ������� ������� Esc.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <iostream>
#include <windows.h>
using namespace std;
void gotoXY(int X, int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
int _tmain()
{
	setlocale(LC_ALL, "rus");
	while (1)
	{
		system("cls");
		int min = 0, sec = 0;//min - ���������� ��� �������� ����� sec - ���������� ��� �������� ������
		int prov = 1;//���������� ��� �������� ������������ �����
		do//���� ��� �������� �����
		{
			prov = 1;
			cout << "\n������� �����\n������ -> ";
			cin >> min;
			cout << "������� -> ";
			cin >> sec;
			if (min<0 || sec<0)//�������� �����
			{
				prov = 0;
				cout << "������������ ���� ������! ������� ��������!";
			}
		} while (prov == 0);
		if ((sec / 60) > 0)//�������� ���� ������ ������� ������ ��� 60
		{
			min += sec / 60;//����������� 60 ������ � �������
			sec -= (sec / 60) * 60;//����� �� ������ ������
		}
		sec = sec + (min * 60);//������� ����� � ������� � ����������� �� � ������ ��������
		int time = sec;//���������� time ������ �������� sec ��� �����, �� sec �������� � ����� 
		for (int i = 0; i <= time; i++)
		{
			system("cls");
			gotoXY(23, 11);//������� ������ � �����
			cout << "���������� �����: ";
			if (min / 10 == 0)//���������� ���� ����� ��������, ���� �� ������ 10
			{
				cout << "0";
			}
			cout << min << " ���. ";
			if ((sec - (min * 60)) / 10 == 0)//���������� ���� ����� ���������, ���� �� ������ 10
			{
				cout << "0";
			}
			cout << sec - (min * 60) << " ���.";
			if (sec - (min * 60) == 0)//�������� ����� � �������
				{
					min -= 1;
				}
			sec -= 1;
			Sleep(980);//��������� ���������

		}
		cout << "\n����� �������!\n������� Enter ��� ����������� ��� Esc ��� ������";
		if (_getch() == 27)//�������� ����� �� ������������ �����
		{
			exit(0);
		}
	}
}

