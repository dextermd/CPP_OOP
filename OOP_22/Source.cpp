//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>				// Для работы с файлами C++
#include <conio.h>
#include <iomanip>

#include "MyString.h"
#include "MyArray.h"
#include "ListOneType.h"
#include "StudentAgr.h"
#include "Coord.h"

using namespace std;


int main()
{

#if 0
	
	//========================================================================================================
	// Работа с файлами С++
	
	// Запись ------------------------------------------------------------------------------------------------
	// Последовательная запись в файл в текстовом формате


	int year = 2023;
	ofstream fout;			// int a
	// fout.open("text.txt");  // a = 10; ios::out - режим записи  ios::trunc - урезание файла до нулевого, если он существует
	fout.open("text.txt", ios::app); //  ios::app Добавление в конец файла.
	
	// ios::app Добавление в конец файла.
	// ios::out - режим записи
	// ios::trunc - урезание файла до нулевого, если он существует

	if (fout)
	{
		cout << "\nPosition in File: " << fout.tellp();
		fout << "\nHello, World! " << year << " !!!";
		fout << "\nHello, Friends! " << year << " !!!";
		fout << "\nHello, World! " << year << " !!!";
		fout << "\nHello, Friends! " << year << " !!!";
		cout << "\nFile created successfully!";
		fout.close();
	}
	else {
		cout << "\nError writing to file: " << errno;
		char buf[100];
		strerror_s(buf, sizeof(buf), errno);
		cout << "\nERROR: " << buf;
	}

#endif

#if 0

	// Чтение Посимвольное ------------------------------------------------------------------------------------------------
	
	ifstream fin("text.txt"); // ios::in - режим чтения

	// Посимвольноe чтение
	char symbol;

	if (fin)
	{
		//while (!fin.eof()) // Пока не конец файла  eof =  end of file
		//{
		//	// fin >> symbol; // без пробелов и пустых строк
		//	fin.get(symbol);
		//	cout << symbol;
		//}

		while (fin.get(symbol))
		{
			cout << symbol;
		}
		fin.close();
	}
	else {
		cout << "\nError reading file";
	}
	

#endif 

#if 0

	char buf[200];
	// Чтение Построчное ------------------------------------------------------------------------------------------------

	ifstream fin("text.txt"); // ios::in - режим чтения

	// Построчное чтение

	if (fin)
	{
		while (!fin.eof()) // Пока не конец файла  eof =  end of file
		{
			cout << "\nPosition reading: " << fin.tellg() << endl;
			fin.getline(buf, sizeof(buf));
			cout << buf << endl;
		}

		fin.close();
	}
	else {
		cout << "\nError reading file";
	}

#endif 

#if 0

	// Скопировать файл построчно в текстовом формате
	// Дополнительно ---> скопировать только не пустые файлы и пронумеровать строки.
	ifstream fin("text.txt");
	
	if (fin)
	{
		char buff[256];
		int i = 0;
		ofstream fout("copy_text.txt");
		if (fout)
		{
			while (!fin.eof())
			{
				fin.getline(buff, sizeof(buff));			// Чтение строки из файла
				// fout << buff << endl;					// Запись в новый файл содержимое старого файла ( вместе с пустыми строками )
				//fout << ++i << "). " << buff << endl;		// Запись c нумерацией строк в новый файл содержимое старого файла ( вместе с пустыми строками )
				
				if (strlen(buff))							// Запись c нумерацией строк в новый файл содержимое старого файла ( БЕЗ ПУСТЫХ СТРОК )
				{
					fout << ++i << "). " << buff << endl;	// Запись c нумерацией строк в новый файл содержимое старого файла ( БЕЗ ПУСТЫХ СТРОК )
				}
			}
			cout << "\nCopy File created successfully!";
			fout.close();
		}
		else {
			cout << "\nError writing file";
		}
		fin.close();
	}
	else {
		cout << "\nError reading file";
	}

#endif

#if 0
	
	// ---------------------------------------------------------------------------------------------------------------
	// Копия двоичного файла (img.jpg) ios::binary
	
	// Посимвольно

	ifstream fin("img.jpg", ios::binary); // Чтение

	if (fin)
	{
		char buff[256] = "";
		int i = 0;
		ofstream fout("copy_img.jpg", ios::binary);  // Запись
		if (fout)
		{
			char s;
			while (!fin.eof())
			{
				fin.get(s);			// Чтение символа 1 байт из файла
				fout.put(s);        // Запись 1 символа.
			}
			cout << "\nCopy File created successfully!";
			fout.close();
		}
		else {
			cout << "\nError writing file";
		}
		fin.close();
	}
	else {
		cout << "\nError reading file";
	}
#endif 

#if 0

	// Запись блоками ---------------------------------------------------------------------------------------------
	// coord, строка, double
	
	int a = 123456;
	double d = 3654.8774123456;
	int arr[5]{ 123, -65, 789, -48662, 45 };
	char str[50] = "Hello, files!";
	Coord c(25, -36);
	Coord arr_coord[3]{ {12, -5}, "129,9", Coord(100,5) };
	ofstream file_write("test_binary.txt", ios::binary);
	// MyString my_string_object("test MyString"); // Обьект с динамическим выделение памяти.

	if (file_write)
	{
		file_write.write((char*)&a, sizeof(int));									// Запись одного целого значения
		file_write.write((char*)&d, sizeof(double));								// Запись одного double значения
		file_write.write((char*)arr, sizeof(arr));									// Запись статического массива
		file_write.write(str, sizeof(str));											// Запись одной строки
		file_write.write((char*)&c, sizeof(c));										// Запись одного Обьета coord
		file_write.write((char*)arr_coord, sizeof(arr_coord));						// Запись статического массива Coord
		// file_write.write((char*)&my_string_object, sizeof(my_string_object));		// Запись MyString обьекта

 		cout << "\nOk!\n";
		file_write.close();
	}
	else {
		cout << "\nError writing file!";
	}


	// Чтение блоками ---------------------------------------------------------------------------------------------

	int a2;
	double d2;
	int arr2[5];
	char str2[50];
	Coord c2;
	Coord arr_coord2[3];
	ifstream file_read("test_binary.txt", ios::binary);
	// MyString my_string_object2;

	if (file_read)
	{
		file_read.read((char*)&a2, sizeof(int));									// Чтение одного целого значения
		file_read.read((char*)&d2, sizeof(double));									// Чтение одного double значения
		file_read.read((char*)arr2, sizeof(arr2));									// Чтение статического массива
		file_read.read(str2, sizeof(str2));											// Чтение одной строки
		file_read.read((char*)&c2, sizeof(c2));										// Чтение одного Обьета coord
		file_read.read((char*)arr_coord2, sizeof(arr_coord2));						// Чтение статического массива Coord
		// file_read.read((char*)&my_string_object2, sizeof(my_string_object2));		// Чтение статического массива Coord

		cout << "\nA2 = " << a2 << endl;
		cout << "\nD2 = " << setprecision(15)  << d2 << endl; 
		cout << "\nArr2 = ";
		for (int i = 0; i < 5; i++)
		{
			cout << arr2[i] << " ";
		}
		cout << "\n\nSTR2 = " << str2 << endl;
		cout << "\nCoord2 = " << c2 << endl;
		cout << "\nCoord arr_coord2 = ";
		for (Coord v : arr_coord2)
		{
			cout << v << " ";
		}

		// cout << my_string_object2 << endl;

		file_write.close();
	}
	else {
		cout << "\nError reading file!";
	}
#endif 

#if 1

	// ----------------------------------------------------------------------------------------------------------------------
	// Запись/чтение обьекта (MyString)
	MyString ms("testr MyString ");
	ofstream fout("strings.txt", ios::binary);
	
	if (fout)
	{
		//ms.save_to_binary_file_2(fout);
		fout << ms; // Перегрузка потока записи в файл <<
		fout.close();
	}
	else {
		cout << "\nError writing file!";
	}


	MyString ms2;
	ifstream fin("strings.txt", ios::binary);

	if (fin)
	{
		ms2.read_from_binary_file_2(fin);
		cout << "\nString from file: " << ms2;
		fin.close();
	}
	else {
		cout << "\nError reading file!";
	}

#endif


}