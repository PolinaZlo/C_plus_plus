// Разработать программу для вычисления интеграла с заданной точностью методом трапеций и методом Симпсона, 
//оформив каждый способ в виде отдельной функции. Вывести на экран результаты интегрирования разными методами для сравнения.
//Подынтегральное выражение оформить в виде отдельной функции.
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
//метод трапеций
double trapeze(int defin, double a, double b)
{
	double eps = 1;
	double I = 0;
	double I_pred = 1;
	for (int i = 0; i < defin; i++)//точность
	{
		eps = (double)eps / 10;
	}
	
	int n = 10;//кол-во повторений
	while (abs(I_pred - I) > eps && n<10000000)//цикл будет выполнятся пока I не станет меньше eps
	{
		I_pred = I;
		double h = (double)(b - a) / n;
		I = (function(a) + function(b)) / 2;//крайние значения
		for (int w = 1; w < n; w++)
		{
			I += function(a + w*h);
		}
		I *= h;
		n *= 2;
	}
	return I;
}
//метод Симпсона
double LisaSimpson(int defin, double a, double b)
{
	double eps = 1;
	double I = 0;
	double I_pred = 1;
	for (int i = 0; i < defin; i++)//точность
	{
		eps = (double)eps / 10;
	}
	int n = 10;//кол-во повторений
	while (abs(I_pred - I) > eps && n<10000000)//цикл будет выполнятся пока I не станет меньше eps
	{
		I_pred = I;
		double h = (double)(b - a) / n;
		I = function(a) + function(b);//крайние значения
		int two_four;
		for (int w = 1; w < n; w++)
		{
			if (w%2==0)//проверка для того чтобы менять число с 4 на 2, зависящее от номера прохода
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
	cout << "Введите точность (простое число) -> ";
	cin >> defin;
	while (prov == false)//проверка на введенное число
	{	
 if (defin < 0)
		{
			cout << "Точность не может быть отрицательной или равной 0!\n"; prov = false;
			cout << "\nВведите точность (кол-во знаков после запятой) -> "; cin >> defin;
		}
		else prov = true;
	}
	I = trapeze(defin, a, b);
	cout << "\nПлощадь заданного интеграла (метод трапеций) = " << I << "\n\n";
	I = LisaSimpson(defin,a,b);
	cout << "\nПлощадь заданного интеграла (метод Симпсона) = " << I << "\n\n";
	system("pause");
}

