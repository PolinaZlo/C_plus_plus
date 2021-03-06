//Создать в редакторе текстовый файл, внести в него несколько строк произвольного текста. Разработать программу, 
//которая выводит на экран строки файла, в которых встречается заданный символ
//формирует другой файл, в который переписывает строки исходного файла, содержащие латинские буквы, и указывает после каждой 
//строки количество латинских букв в ней.

#include "stdafx.h"
#include <conio.h>
#include <locale.h>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <windows.h>
#include <string>
using namespace std;
bool check(ifstream &file)
{
	if (!file.is_open())
	{
		cout << "(=>T_T)=> Файл не найден" << endl;
		return false;
	}
	else if (file.peek() == EOF)
	{
		cout << "Файл пуст <=(T_T<=)" << endl;
		return false;
	}
	else
	{
		return true;
	}
}
void print_file(ifstream &file)//вывод файла
{
		string str;
		while (!file.eof()) //цикл выполняется пока не закончится файл
		{
			getline(file, str);//получение строки
			cout << "\t" << str << endl;//вывод	
		}
		file.seekg(0);//возвращение в начало файла
}
bool Simba(string str, char symbol)//проверка есть ли в считываемой строке нужный символ
{
	char *str_ykaz = &str[0];//указатель на строку
	while (*str_ykaz != '\0')
	{
		if (*str_ykaz == symbol)//c учетом регистра
		{
			return true;
		}
		str_ykaz++;
	}
	return false;
}
bool Latin(ifstream &file)//проверка принадлежит ли символ латнице и запись нового файла
{
	ofstream file_note("str_note.txt");
	file.seekg(0);//возвращение в начало файла
	string str;
	bool global = false;//проверка, запишется ли в файл хоть что либо
	while (!file.eof())
	{
		getline(file, str);//получение строки
		int num = 0;//счетчик кол-ва лат. букв
		char *str_ykaz = &str[0];//указатель на строку
		while (*str_ykaz != '\0')
		{
			if ((*str_ykaz >= 'A' && *str_ykaz <= 'Z') || (*str_ykaz >= 'a' && *str_ykaz <= 'z') || *str_ykaz == ' ')//c учетом регистра
			{
				file_note << *str_ykaz; //запись в файл
				if (*str_ykaz != ' ')
				{
					num++;//подсчет кол-ва символов
					global = true;
				}
			}
			str_ykaz++;
		}
		if (num != 0)//проверка чтобы не записывать пустую строку
		{
			file_note << "\t-> " << num << endl;//записывает в новый файл кол-во символов в строке
		}
	}
	if (!global) return global;
	else file_note.close(); return global;
}
int _tmain()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ifstream file("stroki.txt");
	if (check(file))
	{
		string str;
		int num_of_strok = 0;
		char symbol = ' ';
		cout << "Изначальный файл:" << endl;
		print_file(file);//Вывод на экран содержимого файла
		cout << endl << "Какой символ будем искать в файле? -> ";
		cin >> symbol;
		cout << endl << "Строки содержащие <" << symbol << "> символ:" << endl;
		while (!file.eof()) //цикл выполняется пока не закончится файл
		{
			getline(file, str);//получение строки
			if (Simba(str, symbol))//проверка есть ли в считываемой строке нужный символ - задание 5.1.
			{
				cout << "\t" << str << endl;//вывод
				num_of_strok++;
			}
		}
		if (num_of_strok == 0) cout << "Нет строк с введенным символом!" << endl;
		cout << endl << "Строки ТОЛЬКО с латинскими буквами и их количеством:" << endl;
		if (Latin(file))
		{
			ifstream file_2("str_note.txt");
			print_file(file_2);
			cout << "Запись файла произведена!" << endl;
			file_2.close();
		}
		else cout << "В файле нет латинских букв!"<<endl;
	}
	file.close();
	system("pause");
}

