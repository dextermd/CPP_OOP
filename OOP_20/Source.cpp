#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include <string.h>				// STL
#include <vector>				// STL
#include <array>				// STL
#include "ListOne.h"
#include "ListOneT.h"
#include "Coord.h"
#include "MyString.h"
#include <forward_list>
#include "ListTwo.h"
#include "ListTwoT.h"
#include "MyArray.h"
#include "StudentAgr.h"
#include <list>					// STL

using namespace std;

bool cmp_marks_incr(const StudentAgr& objLeft, const StudentAgr& objRight)
{ 
	return objLeft.get_average() > objRight.get_average();
}

int main()
{
#if 1
	// ===================================================================
	// Запись объектов с динамическим выделением памяти в бинарный файл---
	// Запись MyString в бинарный файл (на языке Си)

	MyString a("Hello, World!");

	FILE* file;
	errno_t err;
	

	// Write
	err = fopen_s(&file, "str.txt", "wb");
	if (!err)
	{
		a.save_to_binary_file(file);
		fclose(file);
		cout << endl;
	}
	else {
		cout << "\nFail write File!\n";
	}

	
	// Read 
	MyString tmp;
	err = fopen_s(&file, "str.txt", "rb");
	if (!err)
	{

		tmp.read_from_binary_file(file);
		printf("\nObject new: %s", tmp.get_str());
		cout << endl << tmp;
		fclose(file);
		cout << endl;
	}
	else {
		cout << "\nFail read file!\n";
	}

#endif

#if 0
		// Самостоятельно:  Записать объект типа StudentA текстовый в файл.
		// Написать метод: void save_txt(FILE* f)const;
		// Прочитать файл и вывести на экран
		/*
		Формат записи:
			Фамилия:           Иванов
			Имя:               Иван
			Возраст:           18
			Вуз:               ВУЗ
			Кол-во оценок:     5
			Оценки:            9 9 9 9 9
			Кол-во предметов:  2
			Предметы:          HTML/CSS JavaScript
		*/

		ListOneT<MyString> sub1;

		sub1.add_end("Javascript");
		sub1.add_end("C#");

		FILE* file;
		StudentAgr Stud("Dvornicov", "Ruslan", 12, "STEP", MyArray(5, 10, 12), sub1);
		StudentAgr Stud2("Agapii", "Tanea", 20, "STEP", MyArray(8, 6, 10), sub1);
		errno_t err;

		err = fopen_s(&file, "Student.txt", "w");
		if (!err)
		{
			Stud.save_txt(file);
			Stud2.save_txt(file);
			fclose(file);
		}
		else {
			cout << "\nFail write File!\n";
		}
		
		err = fopen_s(&file, "Student.txt", "r");
		if (!err)
		{
			while (!feof(file))
			{
				char buf[250] = "";
				fgets(buf, sizeof(buf), file);
				printf("%s", buf);
			}
			
			fclose(file);
			cout << endl;
		}
		else {
			cout << "\nFail read file!\n";
		}
		

#endif 

#if 0

	// Запись MyString в текстовый файл (на языке Си)
	MyString a("Hello, friends!");
	MyString b("Hello, NNN!");

	FILE* file;
	errno_t err;
	err = fopen_s(&file, "test.txt", "w");
	if (!err)
	{
		fprintf(file, "string: %s\n", a.get_str());
		fprintf(file, "string: %s", b.get_str());
		printf("\nOk\n");
		fclose(file);
	}
	else {
		cout << "\nРшибка записи в файл!\n";
	}

#endif

#if 0
	
	/*
		Написать класс StudentAgr, у которого в качестве полей для имени и фамилии
		будет использоваться тип MyString, а для оценок тип MyArray.
	
		Реализовать в классе Студент поле : Список предметов на основе шаблонаодносвязного списка.
	
		Создать объект, вывести на экран.
	*/

	ListOneT<MyString> sub1, sub2;
	sub1.add_end("C++");
	sub1.add_end("HTML & CSS");

	sub2.add_end("Javascript");
	sub2.add_end("C#");

	sub1.show();
	sub2.show();

		
	sub2 = sub1;

	sub2.show();

	StudentAgr s1;
	cout << s1 << endl;

	MyArray arr(4, 9);
	StudentAgr s2("Bogdan", "Vladimir", 30, "UTM", MyArray(5, 10, 12), ListOneT<MyString>());
	cout << s2 << endl;

	StudentAgr s3("Davnii", "Eugeniu", 32, "STEP", arr, sub1);
	cout << s3 << endl;

	StudentAgr s4("Agapii", "Tanea", 20, "STEP", arr, sub2);
	cout << s4 << endl;

	StudentAgr s5("Poplavets", "Maryna", 22, "STEP", MyArray(10,9,12), sub2);
	s5.add_subject("Java");
	cout << s5 << endl;

	/*
		Написать метод, позволяющий Студенту брать предмет для изучения.
	*/

	s3.add_subject("Python");
	cout << s3 << endl;


	// --------------------------- Список студентов ------------------------------------------
	/*
		На основе имеющегося шаблона содать
	*/

	cout << "\nSize of MyArray: " << sizeof(MyArray) << endl;
	cout << "\nSize of MyString: " << sizeof(MyString) << endl;
	cout << "\nSize of ListOneT<MyString>: " << sizeof(ListOneT<MyString>) << endl;
	cout << "\nSize of StudentArg: " << sizeof(StudentAgr) << endl;

	ListOneT<StudentAgr> list_of_students;
	list_of_students.add_end(s3);
	list_of_students.add_end(s2);
	list_of_students.add_end(s4);
	list_of_students.add_end(s5);

	list_of_students.show();

	list<StudentAgr> lst;

	lst.push_back(s2);
	lst.push_back(s4);
	lst.push_back(s5);
	lst.push_back(s3);

	// RangeBase цыкл
	for (const StudentAgr& value : lst)
	{
		cout << value;
	}

	lst.sort();

	cout << "\nSort Age ---------------------------------------: \n";

	// RangeBase цыкл
	for (const StudentAgr& v : lst)
	{
		cout << v;
	}

	cout << "\nSort Average -----------------------------------: \n";

	lst.sort(cmp_marks_incr);

	for (const StudentAgr& g : lst)
	{
		cout << g;
	}



#endif



}