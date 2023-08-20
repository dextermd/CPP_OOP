#include<iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include <string.h>		// STL
#include <vector>		// STL
#include <array>		// STL
#include "ListOne.h"

using namespace std;

int main()
{

#if 1
	/*
		Задание 1. В уже существующий класс Односвязного списка(List_1) добавьте реализацию следующих методов :
		+ метод удаления последнего элемента списка;
		+ метод удаления всех элементов списка;
		+ метод, возвращающий порядковый номер элемента по переданному значению(первое вхождение);
		+ метод, возвращающий значение элемента списка по позиции;
		+ перегрузку оператора << ;
		+ перегрузку оператора присваивания;
		+ перегрузку операторов сравнения == , != , >= , <= .Сравнение списков осуществляется по количеству элементов и по содержимому;
		+ перегрузку операторов сравнения > , < .Сравнение списков осуществляется по количеству элементов;
		+ перегрузку оператора + , который конкатенирует два списка и возвращает новый список;
		+ перегрузку оператора –(унарный минус).Метод возвращает новый список, который будет содержать элементы списка, вызвавшего метод, но расположенные в обратном порядке;
		
		
	*/

	ListOne a;

	a.show();

	a.add_end('+');
	a.add_end('-');
	a.add_end('%');

	cout << "\n -------------- pop_back ----------------------- \n";

	cout << a.containe('%');
	cout << "\nSizeof = " << sizeof(a) << endl;
	a.show();
	cout << "Element count: " << a.get_count() << endl;

	a.pop_back();

	cout << a.containe('%');
	cout << "\n Sizeof = " << sizeof(a) << endl;
	a.show();
	cout << "Element count: " << a.get_count() << endl;

	a.add_end('!');

	cout << a.containe('!');
	cout << "\nSizeof = " << sizeof(a) << endl;
	a.show();
	cout << "Element count: " << a.get_count() << endl;

	a.add_end('?');

	cout << a.containe('!');
	cout << "\nSizeof = " << sizeof(a) << endl;
	a.show();
	cout << "Element count: " << a.get_count() << endl;

	a.pop_back();

	cout << a.containe('?');
	cout << "\n Sizeof = " << sizeof(a) << endl;
	a.show();
	cout << "Element count: " << a.get_count() << endl;

	cout << "\n -------------- pop_all ----------------------- \n";
	a.show();

	a.pop_all();
	cout << "\nSizeof = " << sizeof(a) << endl;
	a.show();
	cout << "Element count: " << a.get_count() << endl;

	cout << "\n -------------- get_index_by_element ----------------------- \n";

	ListOne b;
	b.add_end('!');
	b.add_end('@');
	b.add_end('#');
	b.add_end('$');
	b.add_end('%');
	b.add_end('^');
	b.add_end('&');
	b.add_end('*');
	b.add_end('(');
	b.add_end(')');
	b.add_end('-');
	b.add_end('+');

	b.show();

	cout << b.get_index_by_element('^');

	cout << "\n -------------- get_element_by_index ----------------------- \n";

	b.show();
	char c = b.get_element_by_index(2);
	cout << "\nIndex 2 = " << c;

	cout << "\n -------------- operator << ----------------------- \n";

	ListOne y;
	cout << b;
	cout << y;

	cout << "\n -------------- operator = ----------------------- \n";

	y = b;

	y.show();
	cout << "Element count: " << y.get_count() << endl;

	cout << "\n -------------- bool operator == ----------------------- \n";
	ListOne d;
	d.add_end('!');
	d.add_end('@');
	d.add_end('#');
	d.add_end('$');
	d.add_end('%');
	d.add_end('^');	
	ListOne t;
	t.add_end('!');
	t.add_end('@');
	t.add_end('#');
	t.add_end('$');
	t.add_end('%');
	t.add_end('^');


	if (d == t)
	{
		cout << "\nObjects are equal\n";
	}
	else {
		cout << "\nObjects are not equal\n";
	}

	cout << "\n -------------- bool operator != ----------------------- \n";

	if (d != t)
	{
		cout << "\nObjects are not equal\n";
	}
	else {
		cout << "\nObjects are equal\n";
	}

	cout << "\n -------------- bool operator <= ----------------------- \n";

	if (d <= t)
	{
		cout << "\nYes\n";
	}
	else {
		cout << "\nNo\n";
	}

	cout << "\n -------------- bool operator >= ----------------------- \n";

	if (d >= t)
	{
		cout << "\nYes\n";
	}
	else {
		cout << "\nNo\n";
	}

	cout << "\n -------------- bool operator > ----------------------- \n";

	if (d > t)
	{
		cout << "\nYes\n";
	}
	else {
		cout << "\nNo\n";
	}

	cout << "\n -------------- bool operator < ----------------------- \n";

	if (d < t)
	{
		cout << "\nYes\n";
	}
	else {
		cout << "\nNo\n";
	}

	cout << "\n -------------- operator + ----------------------- \n";

	ListOne o;
	o.add_end('1');
	o.add_end('2');
	o.add_end('3');
	o.add_end('4');
	o.add_end('5');
	o.add_end('6');
	ListOne p;
	p.add_end('7');
	p.add_end('8');
	p.add_end('9');
	p.add_end('0');
	p.add_end('-');
	p.add_end('+');
	ListOne n;
	o.show();
	p.show();
	n = o + p;
	n.show();

	cout << "\n --------------  -(унарный минус) ----------------------- \n";
	ListOne f;
	f = -p;
	f.show();

#endif




}