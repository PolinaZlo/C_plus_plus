//Составить программу по работе с файловой системой, которая позволяет узнать системное время, и, если время от 8.15 до 11.30– выводит 
//сообщение «Доброе утро!» и даёт звуковой сигнал, а также отыскивает в указанном каталоге файлы, созданные в это время.
#include "stdafx.h"
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <cstdlib>
#include <iostream>
#include <string>
#include <windows.h>
#include <iomanip>
#include <map>
#include <cstdio>
using namespace std;
/*Проект -> Свойства -> C/C++ -> Препроцессор -> Определения препроцессора -> <Изменить>
-> _CRT_SECURE_NO_WARNINGS*/
int main()
{
	setlocale(LC_ALL, "rus");
	SYSTEMTIME t;
	GetLocalTime(&t);
	int H = t.wHour, M = t.wMinute;
	int fix_H_F = 8, fix_M_F = 15;//час и время начала временых границ
	int fix_H_U = 11, fix_M_U = 30;//час и время конца временых границ
	//int H = 8, M = 50;
	cout << "Текущее системное время: "<< __TIME__<<endl;
	//cout << "Сейчас " << t.wHour << " ч. и " << t.wMinute << " мин." << endl;
	if ((H * 60 + M) >= (fix_H_F * 60 + fix_M_F) && (H * 60 + M) <= (fix_H_U * 60 + fix_M_U))
	{
		cout << "Доброе утро! ;)" << endl; 
		Beep(200, 1000);//звуковой сигнал
	}
	else cout << "Сейчас не утро :3" << endl;
	string way;//путь к файлам
	WIN32_FIND_DATAA findData;
	HANDLE hFind;
	cout << endl << "Путь к каталогу(например D:\task1): ";
	cin >> way;
	if ((hFind = FindFirstFileA(way.c_str(), &findData)) == INVALID_HANDLE_VALUE)//если каталога нет
	{
		cout<<endl<<endl << "\tКаталог не существует" << endl;
	}
	else
	{
		way += "\\*.*";//Путь и имена файлов с разным расширением
		hFind = FindFirstFileA(way.c_str(), &findData);
		SYSTEMTIME timeF, timeS;
		cout << endl << "Файлы в данном каталоге|Время создания" << endl << endl;
		int bro_bo = 0; bool bones = false;
		do
		{
			if (bro_bo > 2)//костыль чтобы не выводить "." и ".." каталоги
			{
				FileTimeToSystemTime(&findData.ftCreationTime, &timeF);
				GetLocalTime(&timeS);
				H = timeF.wHour + 3;//Тк. время выводится по UTC, до нашего часового пояса +3 (файлы созданы по UTC)
				M = timeF.wMinute;
				if ((H * 60 + M) >= (fix_H_F * 60 + fix_M_F) && (H * 60 + M) <= (fix_H_U * 60 + fix_M_U))
				{
					cout << "\t" << findData.cFileName << "\t-> " << H << ":" << M << endl;
					bones = true;
				}
			}
			bro_bo++;

		} while (FindNextFileA(hFind, &findData));
		if (bro_bo == 2) cout << endl << endl << "\tВ этом каталоге нет файлов!" << endl;
		if (!bones && bro_bo > 2) cout << endl << endl 
			<< "\tВ этом каталоге нет файлов созданных в промежуток времени от 8.15 до 11.30" << endl;
	}
	FindClose(hFind);
	cout << endl << endl << endl;
	system("pause");
}
