// Разработать программу для заполнения двоичного файла случайными целыми числами в интервале [1; 500]. 
//Найти компоненты файла, являющимися двузначными числами, и переместить их в начало файла. Массив не использовать.
//

#include "stdafx.h"
#include <conio.h>
#include <locale.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;
int _tmain()
{
	setlocale(LC_ALL, "rus");
	int x, N;
	cout << "Введите кол-во чисел -> ";
	cin >> N;
	if (N > 0)
	{
		ofstream f_binary;
		f_binary.open("file_binary.dat", ios_base::binary);//открытие для записи
		srand(time(NULL));
		cout << "Исходный файл:"<<endl<<"\t";
		for (int i = 0; i < N; i++)//заполнение случайными числами
		{
			x = 1 + rand() % 500;
			cout << x << "  ";
			f_binary.write((char*)&x, sizeof(x));//запись в файл
		}
		f_binary.close();
		fstream file_b;//универсальное открытие
		file_b.open("file_binary.dat", ios_base::binary | ios_base::in | ios_base::out);
		int buff, pre_last, q = 0;
		bool yes_no = false;//проверка есть ли вообше в файле двузначные
		for (int l = 0; l < N; l++)//перепись
		{
			file_b.read((char*)&x, sizeof(x));//чтение элемента
			q++;
			if (x > 9 && x < 100)//попадение в диапазон
			{
				yes_no = true;
				buff = x;//хранение двузначного
				for (int j = l; j >= 0; j--)//цикл для сдвига
				{
					if (l == 0) break;//если первый элемент и есть двузначное
					if ((j - 1) != -1)//проверка чтобы не вылетело за границы файла
					{
						file_b.seekp((j - 1) * sizeof(x), file_b.beg);//сдвиг на элемент перед двузначным
						file_b.read((char*)&pre_last, sizeof(int));//считываение элемента
						file_b.seekp((j) * sizeof(x), file_b.beg);//сдвиг на двузначное
						file_b.write((char*)&pre_last, sizeof(x));//перезапись двузначного
					}
				}
				file_b.seekp(0 * sizeof(x), file_b.beg);//сдвиг в начало
				file_b.write((char*)&buff, sizeof(x));//запись двузначного в начало файла
			}
			file_b.seekp((q) * sizeof(x), file_b.beg);//возвращение на позицию
		}
		if (yes_no)
		{
			file_b.seekg(0, file_b.beg);
			cout << endl << "\nНовый файл (двузначные числа переставлены в начало): " << endl << "\t";
			for (int i = 0; i < N; i++)
			{
				file_b.read((char*)&x, sizeof(x));
				cout << x << "  ";
			}
			cout << endl;
		}
		else cout<<endl << endl << "Файл не содержит двузначных чисел!" << endl << endl;
		file_b.close();
	}
	else cout<<endl << "Неверный ввод кол-ва чисел!"<<endl<<endl;
	system("pause");
}


