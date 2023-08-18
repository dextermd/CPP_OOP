#include <iostream>
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

}