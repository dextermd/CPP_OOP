#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include <string.h>
#include <vector>
#include <array>
#include "ListOne.h"
#include "ListOneT.h"
#include "Coord.h"
#include "MyString.h"
#include <forward_list>
#include "ListTwo.h"

using namespace std;

bool cmp_incr(const int & a, const int& b)
{
	return a > b;
}

int main()
{
#if 0

	/*
		Задание 1. 
		В уже существующий класс Односвязного списка(List_1) добавьте реализацию следующих методов :
		+ добавление элемента(значение передается вторым параметром) до элемента списка со значением первого параметра;
		+ добавление элемента по позиции(порядковому номеру), при этом элемент списка, занимавший эту позицию, становится следующим;
		+ удаление значения по позиции(порядковому номеру);
		+ перегрузку оператора >> для ввода данных одного элемента;
		+ конструктор с перемещением;
		+ перегрузку оператора присваивания(= ) с перемещением;

		Продемонстрируйте работу добавленных методов на примерах.
		Примечание: в методах, принимающих позицию элемента, осуществить проверку на существование переданной позиции в списке.
	*/

	ListOne list;
	list.add_end('!');
	list.add_end('@');
	list.add_end('#');
	list.add_end('$');
	list.add_end('%');
	list.show();

	list.add_do_element('%', '*');
	list.show();

	list.add_do_by_index(4, '-');
	list.show();
	list.pop_by_index(7);
	list.show();

	ListOne input;
	input.add_end('!');
	input.add_end('^');
	input.add_end('&');
	//cin >> input;
	input.show();
	cout << "\nCount: " << input.get_count() << endl;
	ListOne list2 = move(input);
	list2.show();

	ListOne a, b;
	a.add_end('1');
	a.add_end('2');
	a.add_end('3');
	a.add_end('4');
	a.add_end('5');
	a.show();

	b = move(a);
	b.show();


#endif

#if 1

	/*
		Задание 2. 
		В уже существующий класс Двунаправленного списка(ListTwo) добавьте реализацию
		следующих методов :
		+ добавление элемента в начало списка;
		+ добавление элемента(значение передается вторым параметром) после элемента списка со значением первого параметра;
		+ удаление первого элемента списка;
		+ удаление последнего элемента списка;
		+ удаление всех элементов списка;
		+ конструктор копирования;
		+ конструктор с перемещением;
		+ перегрузку оператора присваивания(= );
		+ перегрузку оператора присваивания(= ) с перемещением;
		+ перегрузку операторов << , >> ;
		− перегрузку оператора + для двух списков(конкатенация);
	*/

	ListTwo a;
	a.add_begin(250);
	a.add_begin(136);
	a.add_begin(50);
	a.add_begin(26);


	a.show();
	a.add_by_element(26, 33);
	a.show();
	a.add_by_element(33, 34);
	a.show();
	a.push_back(44);
	a.show();
	a.push_back(00);
	a.show();
	a.pop_front();
	a.show();
	a.add_begin(10);
	a.show();
	a.pop_front();
	a.show();
	a.pop_back();
	a.show();
	a.push_back(1111);
	a.show();
	a.pop_all();
	a.show();
	a.add_begin(10);
	a.add_begin(20);
	a.add_begin(30);
	a.add_begin(40);
	a.add_begin(50);
	a.show();
	ListTwo b=a;
	b.show();
	b.add_by_element(10, 34);
	b.show();
	ListTwo c = move(b);
	c.show();
	b.show();

	ListTwo g, h,m;
	g.push_back(11);
	g.push_back(12);
	g.push_back(13);
	g.push_back(14);
	g.show();
	h = g;
	h.show();
	h.add_begin(50);
	h.push_back(1111);
	h.show();
	m = move(h);
	m.show();

	cout << "\n M = " << m;

	//cin >> m;

	cout << "\n M = " << m;

	m.add_begin(1);
	m.push_back(1);
	cout << "\n M = " << m;
	h.push_back(55);
	h.push_back(56);
	h.push_back(57);

	ListTwo f;
	cout << "\n H = " << h;
	cout << "\n M = " << m;
	f = h + m;
	cout << "\n H + M = " << f;

	f.add_begin(66);
	f.push_back(66);	
	cout << "\n F = " << f;

#endif

#if 0

	/*
		Задание 3. 
		Реализуйте шаблон класса Двунаправленного списка.Продемонстрируйте работу
		шаблона на стандартных и пользовательских типах(например, класс Координата).
	*/

#endif

}