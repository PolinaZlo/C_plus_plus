//Составить программу обработки динамической структуры данных: поменять местами последний и предпоследний элементы стека Q, 
//состоящего не менее чем из двух элементов.
#include "stdafx.h"
#include <conio.h>
#include <locale.h>
#include <iostream>
#include <ctime>
using namespace std;
struct Single_List {
	int value;
	Single_List *next;// указатель на следующий элемент стека
	Single_List *Head;
};


void push(int N, Single_List** Head)
{
	(*Head) = new Single_List();//выделяем память под новый элемент
	cout << "Введите значение ";
	cin >> (*Head)->value;//вводим значение информационного поля
	(*Head)->next = NULL;//обнуление адресного поля
	push(N - 1, &((*Head)->next));

	
}

void View(Single_List **Q) //вывод стека на экран
{
	Single_List *t = *Q;
	while (t != NULL)
	{
		cout << t->value << " ";
		t = t->next;
	}
}
void Change(Single_List **Q, int N, int last, int pre_last)//меняем местами последний и предпоследн
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
	while (N < 2)//проверка на ввод
	{
		cout << "\tКол-во элементов односвязной очереди-> ";
		cin >> N;
		if (N < 2) cout << "Кол-во элементов должно быть не менее 2-х" << endl;
	}
	Single_List **Q = NULL;//создание односвязной очереди
	cout << "Введите элементы односвязной очереди:"<<endl;
	for (int i = 0; i < N; i++)
	{
		cout << "Элемент [" << i + 1 << "] = ";
		cin >> x;
		push(N,Q);//заполнение односвязной очереди
		if (i == N-1) last = x;//нахождение последнего
		if (i == N-2) pre_last = x;//нахождение предпоследнего
	}
	cout << endl << "\tЭлементы стека:" << endl << "\t\t";
	View(Q);//вывод односвязной очереди на экран
	cout << endl << endl << "\tПредпоследний элемент односвязной очереди = " 
		<< pre_last << endl << "\tПоследний элемент односвязной очереди = " << last << endl;
	Change(Q, N, last, pre_last);//замена элементов
	cout << endl << "\tИзмененный односвязная очередь:" << endl << "\t\t";
	View(Q);//вывод односвязной очереди на экран
	cout << endl << endl;
	system("pause");
}


