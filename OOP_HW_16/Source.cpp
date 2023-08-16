#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include "MyArrayTemplate.h"
#include "QueueT.h"
#include "MyString.h"
#include "Coord.h"

using namespace std;

int main()
{
	/*
		Задание 1.
		Напишите шаблоны для уже существующих классов :
		− Одномерный динамический массив(MyArray)
		− Очередь(Queue).
		Используйте версии классов с учетом домашних заданий.
		Продемонстрируйте работу шаблонов на примере типов :
		− целые числа(int)
		− класс Координата(coord)
		− класс Строка(MyString).
	*/

#if 0

	QueueT<int> a, b, c;

	for (int i = 0; i < 10; i++)
	{
		a.Add(i);
	}

	a.Show();

	cout << "\nCount = " << a.GetCount() << endl;

	b = a;

	b.Show();

	for (int i = 0; i < 10; i++)
	{
		b.Extract();
	}

	b.Show();

	cout << "___________________________________\n";

	QueueT<Coord> a2, b2, c2;

	for (int i = 0; i < 10; i++)
	{
		a2.Add(2);
	}

	a2.Show();

	cout << "\nCount = " << a2.GetCount() << endl;

	b2 = a2;

	b2.Show();

	for (int i = 0; i < 10; i++)
	{
		b2.Extract();
	}

	b2.Show();

	cout << "___________________________________\n";

	QueueT<MyString> a3, b3, c3;

	for (int i = 0; i < 10; i++)
	{
		a3.Add("Go! ");
	}

	a3.Show();

	cout << "\nCount = " << a3.GetCount() << endl;

	b3 = a3;

	b3.Show();

	for (int i = 0; i < 10; i++)
	{
		b3.Extract();
	}

	b3.Show();

	cout << "___________________________________\n";


#endif

#if 0



	MyArrayTemplate<double> d(5.2, 10), d1(2.2,2), d3(1.1, 1), d4;

	d.show();
	cout << endl << endl;

	d1 = d;

	d1 += d3;

	d1.show();
	cout << endl << endl;

	MyArrayTemplate<int> f(5,10), f1;

	f.show();
	cout << endl << endl;

	f1 = f;

	f1.show();
	cout << endl << endl;

	MyArrayTemplate<MyString> s("Go!", 3), s1, s3;

	s.show();
	cout << endl << endl;

	s1.show();
	cout << endl << endl;

	s1 = s;

	s1.show();

	cout << endl << endl;

	//s3.init();
	s3.show();
	cout << endl << endl;

	MyArrayTemplate<Coord> c({1, 3}, 2), c1, c3;

	c.show();
	cout << endl << endl;

	c1.show();
	cout << endl << endl;

	c1 = c;

	c1.show();

	cout << endl << endl;

#endif

}