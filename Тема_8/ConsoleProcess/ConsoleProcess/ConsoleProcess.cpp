#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	//ДОЧЕРНЯЯ ПРОГРАММА
	setlocale(LC_ALL, "rus");
	ifstream file("D:\\file31.txt");//открытие файла
	if (!file.is_open()) cout << "Файла не существует" << endl << endl;

	else if (file.peek() == EOF) cout << "Файл пуст" << endl << endl;

	else
	{
		HANDLE  hMutex;
		// открываем мьютекс
		hMutex = OpenMutex(SYNCHRONIZE, FALSE, L"DemoMutex");
		if (hMutex == NULL)
		{
			cout << "Не открыть мьютекс. Нажмите любую клавишу чтобы выйти" << endl;
			cin.get();
			return GetLastError();
		}
		string str;
		while (!file.eof()) {
			WaitForSingleObject(hMutex, INFINITE);// захватываем мьютекс
			for (int i = 0; i < 5; i++)
			{
				if (file.eof()) break;
				getline(file, str);//получениестрокиизфайла
				cout << "Дочерний процесс: " << str << endl;
				Sleep(5);
			}
			cout << endl;
			ReleaseMutex(hMutex);// освобождаем мьютекс
		}
		CloseHandle(hMutex);// закрываем дескриптор объекта
	}
	file.close();
	return 0;
}


