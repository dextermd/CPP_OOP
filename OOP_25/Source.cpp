#include <iostream>
#include <iomanip>
#include <Windows.h>
#include "MyString.h"
#include "Person.h"
#include "Student.h"
#include "Worker.h"
#include "Circle.h"
#include "Cylinder.h"
#include "WorkerStudent.h"
#include "Shape.h"
#include "Triangle.h"
#include "Crug.h"

using namespace std;

double division(int a, int b)
{
	if (b == 0)
	{
		throw exception("Division by zero");
	}
	return (double)a / b;
}

int main()
{

#if 0
	//-------------------------------------------------------------------------------------
// Обработка исключений

	int a = -1, b = 2;
	double d = 0.;
	// cout << a / b << endl; // Вылет
	// cout << a / d << endl;

	try
	{
		if (b == 0)
		{
			throw exception("Division by zero!");
		}
		if (b == 1) {
			throw "Division by 1!";
		}
		if (b < 0)
		{
			throw b;
		}
		if (a < 0 || b < 0)
		{
			throw out_of_range("Invalid range");
		}

		cout << a / b << endl;
	}
	catch (const exception& exp)
	{
		//cout << "Error: Division by zero";
		cout << "\nError: " << exp.what();
	}
	//catch (const char* exp)
	//{
	//	cout << "\nError: " << exp;
	//}
	catch (const int& exp)
	{
		cout << "\nError: " << exp;
	}
	catch (const out_of_range& exp)
	{
		cout << "\nError: " << exp.what();
	}
	catch (...)
	{
		cout << "\nSomething went wrong";
	}

	cout << "\nThe program continues to run";

#endif 
	

	try
	{
		cout << "Result division: " << division(5, 0); // Небезопасный код
	}
	catch (const std::exception& exp)
	{
		cout << exp.what();
	}

	try
	{
		Cylinder cyl(2, 3, 2.5, -10);
		cyl.show();
	}
	catch (const std::exception& exp)
	{
		cout << exp.what();
	}

	Cylinder* ptr = nullptr;

	try
	{
		ptr = new Cylinder(2, 3, 2.5, -10);
		if (ptr)
		{

			ptr->show();
		}
	}
	catch (const std::exception& exp)
	{
		cout << exp.what();
		delete ptr;
	}



}


