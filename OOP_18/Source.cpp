#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include <string.h>		// STL
#include <vector>		// STL
#include <array>		// STL
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
#if 1

	// Двухсвязный список ------------------------------------------------------------------------- //
	// Добавление в конец

	ListTwo a;
	a.push_back(345);
	a.push_back(145);
	a.push_back(45);
	a.show(false);
	a.show(true);

	cout << "\nCount: " << a.get_count();


#endif 


#if 0

	ListOneT<int> list;
	list.add_end(125);
	list.add_end(-2);
	list.add_end(17);

	list.show();

	ListOneT<double> listd;
	listd.add_end(125.3256);
	listd.add_end(-12.256);
	listd.add_end(0.1256);

	listd.show();

	ListOneT<MyString> listms;
	listms.add_end("!");
	listms.add_begin("Hello");
	listms.add_element("Hello", "Step");

	listms.show();
	cout << "\n--------------------- STL ----------------------\n";
	forward_list<int> fl;

	fl.push_front(256);
	fl.push_front(-12);
	fl.push_front(10);
	fl.push_front(600);
	fl.push_front(-300);

	for (int v: fl)
	{
		cout << v << "  ";
	}
	
	fl.sort();
	cout << endl;

	for (int v : fl)
	{
		cout << v << "  ";
	}


	fl.sort(cmp_incr);
	cout << endl;

	for (int v : fl)
	{
		cout << v << "  ";
	}

#endif 

#if 0

	/*
	Реализовать метод добавления элемента(второй параметр) после элемента списка  со значением первого параметра
	*/

	ListOne a;
	a.add_end('+');
	a.add_end('-');
	a.add_end('%');

	a.show();
	a.add_element('%', 'N');
	a.show();

#endif 

#if 0

	ListOne a;

	a.show();

	a.add_end('+');
	a.add_end('-');
	a.add_end('%');

	a.show();

	cout << "\nElement count: " << a.get_count() << endl;

	if (a.containe('!'))
		cout << "\nYes\n";
	else cout << "\nNo\n";

	// Написать метод добавления  элемента в начало списка

	a.add_begin('^');
	a.show();

	ListOne a1;
	a1.add_begin('k');
	a1.show();
	a1.add_end('l');
	a1.show();
	a1.add_begin('p');
	a1.show();

	a1.pop_front();
	a1.show();
	a1.add_begin('5');
	a1.show();

	// Написать методудаления первого элемента

	ListOne b = a;
	b.show();
	cout << "\nElement count: " << b.get_count() << endl;

#endif 



	

}