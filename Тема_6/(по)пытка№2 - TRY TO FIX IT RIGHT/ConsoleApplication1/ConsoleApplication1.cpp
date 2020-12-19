//��������� ��������� ��������� ������������ ��������� ������: �������� ������� ��������� � ������������� �������� ����� Q, 
//���������� �� ����� ��� �� ���� ���������.
#include "stdafx.h"
#include <conio.h>
#include <locale.h>
#include <iostream>
#include <ctime>
using namespace std;
struct Single_List {
	int value;
	Single_List *next;// ��������� �� ��������� ������� �����
	Single_List *Head;
};


void push(int N, Single_List** Head)
{
	(*Head) = new Single_List();//�������� ������ ��� ����� �������
	cout << "������� �������� ";
	cin >> (*Head)->value;//������ �������� ��������������� ����
	(*Head)->next = NULL;//��������� ��������� ����
	push(N - 1, &((*Head)->next));

	
}

void View(Single_List **Q) //����� ����� �� �����
{
	Single_List *t = *Q;
	while (t != NULL)
	{
		cout << t->value << " ";
		t = t->next;
	}
}
void Change(Single_List **Q, int N, int last, int pre_last)//������ ������� ��������� � �����������
{
	Single_List *t = *Q;
	int d = 0;
	while (t != NULL)
	{
		if (N != 2)
		{
			t = t->next;
			d++;
			if (d == N - 2) t->value = last;
			if (d == N - 1) t->value = pre_last;
		}
		else break;
	}
	if (N == 2)
	{
		t->value = last;
		t = t->next;
		t->value = pre_last;
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	int N = 0, last, pre_last,x;
	while (N < 2)//�������� �� ����
	{
		cout << "\t���-�� ��������� ����������� �������-> ";
		cin >> N;
		if (N < 2) cout << "���-�� ��������� ������ ���� �� ����� 2-�" << endl;
	}
	Single_List **Q = NULL;//�������� ����������� �������
	cout << "������� �������� ����������� �������:"<<endl;
	for (int i = 0; i < N; i++)
	{
		cout << "������� [" << i + 1 << "] = ";
		cin >> x;
		push(N,Q);//���������� ����������� �������
		if (i == N-1) last = x;//���������� ����������
		if (i == N-2) pre_last = x;//���������� ��������������
	}
	cout << endl << "\t�������� �����:" << endl << "\t\t";
	View(Q);//����� ����������� ������� �� �����
	cout << endl << endl << "\t������������� ������� ����������� ������� = " 
		<< pre_last << endl << "\t��������� ������� ����������� ������� = " << last << endl;
	Change(Q, N, last, pre_last);//������ ���������
	cout << endl << "\t���������� ����������� �������:" << endl << "\t\t";
	View(Q);//����� ����������� ������� �� �����
	cout << endl << endl;
	system("pause");
}


