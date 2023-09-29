#pragma once

#include <iostream>
using namespace std;


// Демонстрация раскручивания стека

/*
	main() вызывает one();
	one() вызывает two();
	two() вызывает three();
	three() вызывает last();
	last() выбрасывает исключение.
*/

//------------------------------------------
void last() // вызывается функцией three()
{
	cout << "Start last\n";
	cout << "last throwing int exception\n";
	throw -1;
	cout << "End last\n";

}
//------------------------------------------
void three() // вызывается функцией two()
{
	cout << "Start three\n";
	last();
	cout << "End three\n";
}
//------------------------------------------
void two() // вызывается функцией one()
{
	cout << "Start two\n";
	try
	{
		three();
	}
	catch (double)
	{
		cout << "two caught double exception\n";
		
	}
	cout << "End two\n";
}
//------------------------------------------
void one() // вызывается функцией main()
{
	cout << "Start one\n";
	try
	{
		two();
	}
	catch (int)
	{
		cout << "one caught int exception\n";
		//throw;// повторная генерация исключения
	}
	catch (double)
	{
		cout << "one caught double exception\n";
	}
	cout << "End one\n";
}

