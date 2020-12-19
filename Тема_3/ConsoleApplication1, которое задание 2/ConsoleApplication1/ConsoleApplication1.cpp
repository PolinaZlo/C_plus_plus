// ����������� �������� ������ ��� N2 ��������� ������ ���� int. ����������� �������� � ��������� ��������� ���������� ������� 
//������� N: ����� � ������� ����� ������ k, ��� k ��� ������ ������� ��������� � k ��� ��������.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <iostream>
#include <malloc.h>
#include <stdlib.h>
#include <ctime>
using namespace std;
void Dora_the_Explorer(int **matrix, int *matches, int N)
{
	//mas[i, j] == *(*(mas+i)+j)
	int *p;
	p = matches;
	int flag;
	for (int i = 0; i < N; i++)
	{
		flag = 0;
		for (int j = 0; j < N; j++)
		{
			if (*(*(matrix + i) + j) == *(*(matrix + j) + i))
				flag++;
		}
		if (flag == N)
			*p = 1;
		else *p = 0;
		p++;
	}
}
int _tmain()
{
	setlocale(LC_ALL, "rus");
	int N = 0;
	while (N <= 1)
	{
		cout << "������� ����������� ��. ������� (N^2) - > ";
		cin >> N;
		if (N <= 1)
		{
			cout << "����������� ������� ������ ���� ������ ������!\n\n";
		}
	}
	//int **matrix = new int*[N];//��������� ��������� �������
	N = pow(N, 2);
	int  **matrix;
	matrix = new int*[N];
	for (int i = 0; i < N; i++)
	{
		matrix[i] = new int[N];
	}
	srand(time(NULL));
	cout << "�������: \n";
	for (int i = 0; i<N; i++)// ���� �� �������
	{
		for (int j = 0; j < N; j++)// ���� �� ��������
		{
			cout << "matrix[" << i + 1 << "," << j + 1 << "] = ";
			cin >> matrix[i][j];
		}
	}
	cout << "\n";
	for (int i = 0; i<N; i++)//����� ������� ��� �����������
	{
		for (int j = 0; j<N; j++)
		{
			cout << matrix[i][j] << "  ";
		}
		cout << "\n";
	}
	int *matches = new int [N];
	Dora_the_Explorer(matrix, matches, N);
	int prov = 0;
	for (int i = 0; i < N; i++)
	{
		if (matches[i])
		{
			cout << "\n��������� ������ � ������� ��� �������: " << i+1;
			prov = 1;
		}
	}
	if (prov == 0)
	{
		cout << "\n���������� �� �������! :(";
	}
	cout << "\n";
	delete[] matches;
	delete[] matrix;
	system("pause");
}

