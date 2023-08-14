#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include <string.h> // STL
#include <vector> // STL
#include <array> // STL
#include "function.h"
#include "Stack.h"
#include "StackD.h"
#include "StackDTemplate.h"
#include "Queue.h"
#include "QueueRing.h"
#include "QueuePriority.h"
#include "MyString.h"
#include "Coord.h"
#include "StackDT.h"

using namespace std;

int main()
{
#if 1
	// ==================================================================================================
	// Шаблон класса Стек и аргкменты, не являющиеся типами (аргумент-выражение)

	/*
	- Недостаток: Каждое значение размера массива генерирует собственный шаблон.
	  Два отдельных класса.

	- Достоинство: Использует стек памяти, поддерживаемый для автоматических переменныъ(быстрое выполнение).

	- Приоритетней его использовать при большом кол-ве маленьких массивов
	*/

	StackDT<int, 5> s;
	s.push(100);
	s.push(-25);
	s.push(3);
	s.push(-9);
	s.push(123);

	s.show();

	StackDT<int, 5> s2 = s;

	s2.show();


	// ==================================================================================================

	string test = "Hello World", t;
	test += "!!! !!!";

	cout << test << endl;
	cout << "\nsize = " << test.size() << endl;
	cout << "\ncapacity = " << test.capacity() << endl;

	cout << "\nsize = " << t.size() << endl;
	cout << "\ncapacity = " << t.capacity() << endl;

	vector<float> v;
	v.push_back(12.5f);
	v.push_back(1.5f);
	v.push_back(-12.5f);
	v.push_back(12.5f);

	for (float value : v)
	{
		cout << value << "  ";
	}
	cout << endl;

	array<int, 5> ar{12, -6, 3, 45, 6};

	for (int i = 0; i < ar.size(); i++)
	{
		cout << ar[i] << "  ";
	}

	cout << endl << ar.size() << endl;

#endif 


#if 0

	// Шаблон класса 

	StackDTemplate<double> s(20);
	s.push(5.12);
	s.push(-125.25);
	s.push(7.456);
	s.push(896.12);

	s.show();

	StackDTemplate<double> s1 = s; // Копирование

	s1.show();

	StackDTemplate<double> s3;

	s3 = s1; // Тестирование оператор  = 

	s3.show();

	double t;

	cout << "\nИзвлечение элементов: \n";

	while (!s.isempty())
	{
		s.pop(t);
		cout << t << "   ";

	}

	s.show();
	cout << s << endl;

	StackDTemplate<MyString> sm(10);

	sm.push("Hello");
	sm.push("C++");
	sm.push("Summer");

	cout << sm << endl;

	StackDTemplate<MyString> sm2 = sm;

	cout << sm2 << endl;

	StackDTemplate<Coord> sc(10);
	sc.push({ 25,-6 });
	sc.push({ 25,-6 });
	sc.push({ 25,-6 });
	
	cout << sc << endl;

	StackDTemplate<Coord> sc2 = sc;

	cout << sc2 << endl;

	StackDTemplate<Coord> sc3(100);

#endif 


#if 0

	StackD sd(6);
	sd.push(25);
	sd.push(-2);
	sd.push(30);
	sd.push(15);
	sd.show();
	cout << endl;

	// StackD a(sd); // Конструктор копирования
	StackD a = sd;	 // Конструктор копирования

	a.show();
	cout << endl;

	StackD b(10);
	b.push(100);
	b = a;
	b.show();

	
#endif

}