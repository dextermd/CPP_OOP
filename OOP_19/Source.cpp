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

int main()
{
	// ---------------------------------------------------------------------------------
	// Агрегирование / композиция ======================================================
	// Агрегирование - обьект класса используется в качестве 

#if 1
	
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

	cout << "\nСписок студенетов после сортировки: \n";

	// RangeBase цыкл
	for (const StudentAgr& v : lst)
	{
		cout << v;
	}


#endif



}