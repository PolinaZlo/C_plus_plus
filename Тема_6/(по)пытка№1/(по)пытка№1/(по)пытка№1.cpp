//Составить программу обработки динамической структуры данных: поменять местами последний и предпоследний элементы стека Q, 
//состоящего не менее чем из двух элементов.
#include "stdafx.h"
#include <conio.h>
#include <locale.h>
#include <iostream>
#include <ctime>
using namespace std;
struct stek {
	int value;
	struct stek *next;// указатель на следующий элемент стека
};
void push(stek* &next, int N, int *last, int *pre_last)//заполнение стека
{
	srand(time(NULL));
	int x;
	for (int i = 0; i < N; i++)
	{
		x = 1 + rand() % 300;
		if (i == 0) *last = x;//нахождение последнего
		if (i == 1) *pre_last = x;//нахождение предпоследнего
		stek *t = new stek; // объявляем новую динамическую переменную типа stek
		t->value = x;// записываем значение, которое помещается в стек
		t->next = next; // связываем новый элемент стека с предыдущим
		next = t; // новый элемент стека становится его вершиной
	}
}
void View(stek *Q) //вывод стека на экран
{
	stek *t = Q;
	while (t != NULL) 
	{
		cout << t->value << " ";
		t = t->next;
	}
}
void Change(stek*Q, int N, int last, int pre_last)//меняем местами последний и предпоследн
{
	stek *t= Q;
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
void Del(stek* Q)
{
	stek *t = Q;
	while (t != NULL)
	{
		t = Q->next;
		delete Q;
		Q = t;
	}
}
int main()
{
	setlocale(LC_ALL, "rus");
	int N=0, last, pre_last;
	while (N < 2)
	{
		cout << "\tКол-во элементов стека -> ";
		cin >> N;
		if (N < 2) cout << "Кол-во элементов должно быть не менее 2-х" << endl;
	}
	stek *Q = NULL;//создание стека
	push(Q, N, &last, &pre_last);//заполнение стека
	cout << endl << "\tЭлементы стека:" << endl << "\t\t";
	View(Q);//вывод стека на экран
	cout << endl << endl << "\tПредпоследний элемент стека = " << pre_last << endl << "\tПоследний элемент стека = " << last   << endl;
	Change(Q,N, last, pre_last);//замена элементов
	cout << endl << "\tИзмененный стек:" << endl << "\t\t";
	View(Q);//вывод стека на экран
	Del(Q);//удаление стека
	cout << endl<<endl;
	system("pause");
}



