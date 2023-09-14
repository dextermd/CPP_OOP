//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>				// Для работы с файлами C++
#include <conio.h>
#include <iomanip>
#include "MyString.h"
#include "MyArray.h"
#include "StudentAgr.h"
#include "Coord.h"
#include "ListOneT.h"

using namespace std;


int main()
{

#if 0

	/*
		Задание 1. 
			Для уже существующих классов(MyArray, ListOneType, StudentAgr) добавьте реализацию функционала для работы с файлами на языке С++:
				+ перегрузку потока для записи объекта класса в бинарный файл;
				+ перегрузку потока для чтения объекта класса из бинарного файла с инициализацией этого объекта;
				+ метод для записи объекта класса в текстовый файл.
			Продемонстрируйте добавленный функционал классов на примерах.
	*/

	cout << "\n------------------------ MyArray ---------------------------------\n";
	
	MyArray arr(10, 1, 99), arr2;

	ofstream f("arr.txt");
	if (f)
	{
		arr.save_to_file_plus(f);
		f.close();
	}
	else {
		cout << "\nError Writing File!";
	}


	ofstream fout("my_array.txt", ios::binary);
	if (fout)
	{
		//arr.save_to_binary_file_plus(fout);
		fout << arr;
		fout.close();
	}
	else {
		cout << "\nError Writing File!";
	}
	

	ifstream fin("my_array.txt", ios::binary);
	if (fin)
	{
		// arr2.read_from_binary_file_plus(fin);
		fin >> arr2;
		fin.close();
	}
	else {
		cout << "\nError Reading File!";
	}

	cout << arr << endl;
	cout << arr2 << endl;;

	cout << "\n------------------------ ListOneT ---------------------------------\n";

	ListOneT<int> list, list_copy;
	list.add_end(23);
	list.add_end(11);
	list.add_end(69);
	list.add_end(66);
	list.add_end(87);
	list.show();
	cout << "list cout = " << list.get_count() << endl;


	ofstream l("list.txt");
	if (l)
	{
		list.save_to_file_plus(l);
		l.close();
	}
	else {
		cout << "\nError Writing File!";
	}


	ofstream fout_list("list_one_type_b.txt", ios::binary);
	if (fout_list)
	{
		fout_list << list;
		fout_list.close();
	}
	else {
		cout << "\nError Writing File!";
	}


	ifstream fin_list("list_one_type_b.txt", ios::binary);
	if (fin_list)
	{
		// arr2.read_from_binary_file_plus(fin);
		fin_list >> list_copy;
		fin_list.close();
	}
	else {
		cout << "\nError Reading File!";
	}

	list_copy.show();
	cout << "list_copy cout = " << list_copy.get_count() << endl;


	cout << "\n------------------------ StudentAgr ---------------------------------\n";

	ListOneT<MyString> sub;
	sub.add_end("C++");
	sub.add_end("HTML & CSS");
	sub.add_end("Javascript");
	sub.add_end("C#");

	StudentAgr stud("Agapii", "Tanea", 22, "STEP", MyArray(15, 6, 12), sub), stud_copy;
	
	cout << stud;

	ofstream stud_txt("stud.txt");
	if (stud_txt)
	{
		stud.save_to_file_plus(stud_txt);
		stud_txt.close();
	}
	else {
		cout << "\nError Writing File!";
	}


	ofstream fout_stud("stud_b.txt", ios::binary);
	if (fout_stud)
	{
		fout_stud << stud;
		fout_stud.close();
	}
	else {
		cout << "\nError Writing File!";
	}


	ifstream fin_stud("stud_b.txt", ios::binary);
	if (fin_stud)
	{
		fin_stud >> stud_copy;
		fin_stud.close();
	}
	else {
		cout << "\nError Reading File!";
	}

	cout << stud_copy;


#endif

#if 0

	/*
		Задание 2. 
			Напишите программу для регистрации пользователей, создать класс «Пользователь».
			Характеристики «Пользователя» : 
				- логин(должен быть уникальным в списке пользователей),
				- пароль,
				- имя,
				- фамилия,
				- адрес,
				- телефон,
				- e - mail
			(можно добавить поля по желанию, например, список сообщений, даты просмотра аккаунта и т.д.).

			Для описания полей используйте уже существующий класс «Строка / MyString» и другие пользовательские классы по необходимости.
		
			Для хранения пользователей используйте класс «Список / ListOneType» либо «Бинарное дерево поиска / MyTree».

			Работу программы организуйте при помощи меню :
				- Регистрация
				− Вход в аккаунт
				− Список пользователей
				− Выход из программы

			При регистрации пользователя необходимо проверить, нет ли пользователя с таким
			логином, в противном случае вывести сообщение, что такой логин уже используется.

			При входе в аккаунт необходимо запросить логин.Если такой пользователь существует
			запросить пароль.В случае ввода верного пароля вывести данные пользователя на экран.

			В случае ввода неверного пароля можно предложить вариант ввести снова либо выйти отказаться от ввода.
		
			При выводе списка пользователей отображать только логины зарегистрированных
			пользователей.Данные считывать из двоичного файла, в котором записан список
			пользователей.Если список еще пуст, вывести сообщение.
		
			При запуске программы считывать данные из двоичного файла с инициализацией списка пользователей.

			При выходе из программы сохранять список пользователей в двоичный файл и в
			текстовый в формате, удобном для чтения.
		
			По желанию можно расширить функционал программы.
		*/

#endif

}