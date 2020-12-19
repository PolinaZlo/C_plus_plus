// Разработать спецификации и написать функцию для вычисления значения любого члена арифметической прогрессии по заданному номеру, 
//если известен первый член прогрессии и её разность, а также функцию, проверяющую, принадлежит ли заданное число этой прогрессии.
//Организовать вызов обеих функций для проверки.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <iostream>
using namespace std;
int AP(int f, int d, int n)//функция для поиска члена АП
{
	int sum = f;
	for (int i = 1; i < n; i++)
	{
		sum += d;
	}
	return sum;
}
int AP_num(int n_r, int f, int d)//функция для определения явл. ли число членом АП
{
	double n;
	n = ((double)(n_r - f + d) / d);
	if (n == round(n))//проверка целое ли число
	{
		return n;
	}
	else return n = -1;
}
int _tmain()
{
	setlocale(LC_ALL, "rus");
	int first;//Первый член АП
	int diff;//Разность АП
	int num;//номер члена АП
	cout << "Введите первый член арифметической прогресии -> ";
	cin >> first;
	cout << "Введите разность а.п. -> ";
	cin >> diff;
	do
	{
		cout << "Введите номер члена а.п., который вы хотите найти -> ";
		cin >> num;
		if (num < 0)
			cout << "\tНомер члена а.п. не может быть отрицательным или равным нулю!\n";
	} while (num<0);
	int AriPro = AP(first, diff, num);//вызываем ф-цию для высчитывания члена АП
	cout << "АП от [" << num << "] = " << AriPro << "\n\n\n";
	cout << "А теперь введите любое число -> ";
	int num_random = 0;//пременная для вводимого на проверку числа
	cin >> num_random;
	int qwerty = AP_num(num_random, first, diff);//вызов ф-ции для определения является ли число членом АП
	if (qwerty != -1)
	{
		cout << "Число " << num_random << " является " << qwerty << "-м членом данной а.п.\n\n";
	}
	else cout << "Число не является членом данной а.п.\n\n";
	system("pause");
}
