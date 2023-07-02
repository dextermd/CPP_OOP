#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include "Rectangle.h"
#include "Fraction.h"
#include "Student.h"
#include "MyArray.h"


using namespace std;

int main()
{

#if 0

	/* 
	Задание 1. 
	В уже существующий класс “Прямоугольник” добавьте перегрузку оператора присваивания.
	Продемонстрируйте работу оператора на примере.
	*/

	class Rectangle a(10, 5, '*', "Blue", "GG"), b;
	a.show();
	cout << endl;
	b = a;
	b.show();
	cout << endl;

#endif

#if 0

	/*
	Задание 2. 
	В уже существующий класс “Студент” добавьте перегрузку оператора присваивания.
	Продемонстрируйте работу оператора на примере.
	*/

	const int I = 5;
	int grades[I]{ 6,5,7,3,8 };
	Student a("Dvornicov", "Ruslan", 2012, "060111222", "ITStep", 12222, grades), b;
	a.show();
	cout << endl;
	b = a;
	b.show();
	cout << endl;


#endif

#if 0

	/*
	Задание 3. 
	В уже существующий класс “Дробь” добавьте:
	перегрузку операторов для выполнения арифметических операций для работы с дробями (операции +, -, *, /)
	*/

	Fraction a(10,20), b(1,2), c;
	a.show();
	cout << endl;
	b.show();
	cout << endl;
	//c = a + b;
	//c = a - b;
	c = a * b;
	//c = a / b;
	c.show();
	cout << endl;


#endif

#if 1

	/*
	Задание 4. 
	Для уже существующего класса MyArray перегрузите:
	− оператор присваивания = ;
	− оператор [] - два варианта, с проверкой правильности индекса;
	− оператор MyArray + MyArray (создается новый объект, конкатенация двух массивов);
	− оператор MyArray + int (получить новый объект, у которого увеличен размер массива относительно левого операнда на величину целого и новые значения нулевые. Нулевые значения добавлены в конец массива);
	− оператор int + MyArray (получить новый объект, у которого увеличен размер массива относительно правого операнда на величину целого и новые значения нулевые. Нулевые значения добавлены в начало массива).
	Продемонстрируйте работу класса на примерах.
	*/
	
	MyArray a(10, -10, 20), b(10, 50, 100), c, d , e, g(5, 1, 2), m, w(5, 5, 6), o(5,1,1), p(5, 2, 2);
	a.show();
	cout << endl << endl;
	b.show();
	cout << endl << endl;
	c = a;
	c.show();
	cout << endl << endl;
	cout << endl << c[4] << endl;
	cout << endl << endl;
	c[4] = 666;
	c.show();
	cout << endl << endl;
	d = a + b;
	d.show();
	cout << endl << endl;
	g.show();
	cout << endl << endl;
	e = g + 10;
	e.show();
	cout << endl << endl;
	m = 10 + g;
	m.show();
	cout << endl << endl;
	w += 10;
	w.show();
	cout << endl << endl;
	o += p;
	o.show();
	cout << endl << endl;

#endif

}