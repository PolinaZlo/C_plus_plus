#include"stdafx.h"
#include <windows.h>
#include <iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
	//ОСНОВНАЯ ПРОГРАММА
	setlocale(LC_ALL, "rus");
	ifstream file("D:\\file31.txt");//открытие файла
	if (!file.is_open()) cout << "Файла не существует"<<endl<<endl;

	else if (file.peek() == EOF) cout << "Файл пуст"<<endl<<endl;

	else
	{
		HANDLE  hMutex;
		STARTUPINFO  si;//основной
		PROCESS_INFORMATION  pi;//дочерний
		hMutex = CreateMutex(NULL, FALSE, L"DemoMutex");// создаем мьютекс
		if (hMutex == NULL)
		{
			cout << "Мьютекс не создан. Нажмите любую клавишу чтобы выйти" << endl;
			cin.get();
			return GetLastError();
		}
		ZeroMemory(&si, sizeof(STARTUPINFO));
		si.cb = sizeof(STARTUPINFO);
		// создаем новый консольный процесс
		if (!CreateProcess(L"D:\\ConsoleProcess.exe", NULL, NULL, NULL, FALSE,
			NULL, NULL, NULL, &si, &pi))
		{
			cout << "Процесс не создан. Нажмите любую клавишу чтобы выйти" << endl;
			cin.get();
			return GetLastError();
		}

		string str;
		while (!file.eof()) //выполняется пока файл не закрылся
		{
			WaitForSingleObject(hMutex, INFINITE);// захватываем мьютекс
			for (int i = 0; i < 3; i++)
			{
				if (file.eof()) break;
				getline(file, str);//получение строки из файла
				cout << "\tРодитель. процесс: " << str << endl;
				Sleep(100);
			}
			cout << endl;
			ReleaseMutex(hMutex);// освобождаем мьютекс
		}
		CloseHandle(hMutex);// закрываем дескриптор мьютекса
		WaitForSingleObject(pi.hProcess, INFINITE);// ждем пока дочерний процесс закончит работу
		CloseHandle(pi.hThread);// закрываем дескрипторы дочернего процесса в текущем процессе
		CloseHandle(pi.hProcess);
	}
	file.close();
	system("pause");
	return 0;
}


