// Динамически выделить память под N элементов вещественного типа float. Разработать алгоритм и программу обработки одномерного 
//динамического массива. Осуществить циклический сдвиг элементов одномерного массива на k позиций.
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
float *change_right(float *mas, int N, int k)
{
	float *mas_copy = new float[N];
	for (int i = k - 1; i < N; i++)//заполнение первых элементов mas - СДВИГАЕМЫМИ элементами КОНЦА mas_copy
	{
		mas_copy[i] = mas[i - k + 1];//ВПРАВО
	}
	for (int i = 0; i < k - 1; i++)//заполнение mas ОСТАВШИМИСЯ элементами mas_copy
	{
		mas_copy[i] = mas[N - k + i + 1];//ВПРАВО
	}
	return mas_copy;
}
 float *change_left(float *mas, int N, int k)
{
	float *mas_copy = new float[N];
	for (int i = k - 1; i < N; i++)//заполнение первых элементов mas - СДВИГАЕМЫМИ элементами КОНЦА mas_copy
	{
		mas_copy[i - k + 1] = mas[i]; // ВЛЕВО
	}
	for (int i = 0; i < k - 1; i++)//заполнение mas ОСТАВШИМИСЯ элементами mas_copy
	{
		mas_copy[N - k + i + 1] = mas[i]; //ВЛЕВО
	}
	return mas_copy;
}
int _tmain()
{
	setlocale(LC_ALL, "rus");
	int N = 0, k = 0;//N - кол-во элементов, k - позиции сдвига
	while (N <= 1)
	{
		cout << "Введите кол-во элементов массива - > ";
		cin >> N;
		if (N <= 1)
		{
			cout << "Количество эл. массива не может быть меньше двух!\n\n";
		}
	}
	float *mas_origin = new float[N];//инициализ массива c указателем
	srand(time(NULL));//чтобы в массиве были разные числа
	for (int i = 0; i < N; i++)
	{
		mas_origin[i] = (float)(rand()) / RAND_MAX * 500;// от -500 до 500
		cout << mas_origin[i] << "   ";
	}
	while (k <= 0 || k>N)
	{
		cout << "\n\nВведите число сдвига массива - > ";
		cin >> k;
		if (k <0 || k>N)
		{
			cout << "Сдвиг не может быть отрицательными или быть больше массива!";
		}
	}
	k += 1;//без добавления 1 к сдвигу, сдвигатся будет на 1 эл. меньше
	int choose = 0;
	while (choose != 1 && choose != 2)
	{
		cout << "\n\nВ какую сторону идет сдвиг? (1 - влево, 2 - вправо) -> ";
		cin >> choose;

		if (choose != 1 && choose != 2)
		{
			cout << "Введите 1 или 2!";
		}
	}
	float *mas_copy = new float[N];
	if (choose == 1)
	{
		cout << "\nСдвинутый массив влево:\n";
		mas_copy = change_left(mas_origin, N, k);
	}
	else
	{
		cout << "\nСдвинутый массив вправо:\n";
		mas_copy = change_right(mas_origin, N, k);
	}
	for (int e = 0; e < N; e++)
	{
		cout << mas_copy[e] << "   ";
	}
	cout << "\n\n";
	delete[] mas_origin;
	delete[] mas_copy;
	system("pause");
}

