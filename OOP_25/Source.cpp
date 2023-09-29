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
#include "StackD.h"
#include "123.h"
#include "SmartPointerT.h"

using namespace std;


class MyException : public exception {
	int data;

public:
	MyException(const char* msg, int data) : exception(msg){
		this->data = data;
	} 

	int get_data() const { return this->data; };

};

double division(int a, int b) throw(exception, MyException)
{
	if (b == 0)
	{
		throw exception("Division by zero");
	}
	if (b < 0)
	{
		throw MyException("Отрицательное число: ", b);
	}
	return (double)a / b;
}

int main()
{
	setlocale(LC_ALL, "Russian");

#if 1
	// Умные указатели STL
	/*
		auto_ptr;
		unique_ptr;
		shared_ptr;
	*/
	shared_ptr<int> p1(new int);
	*p1 = 789;
	cout << *p1 << "  " << p1.get() << endl;

	shared_ptr<int> p2(p1);

	cout << *p2 << "  " << p2.get() << endl;

	cout << *p1 << "  " << p1.get() << endl;
	*p1 = 800;
	cout << *p2 << "  " << p2.get() << endl;
	cout << *p2 << "  " << p2.get() << endl;
	*p2 = 900;
	cout << *p1 << "  " << p1.get() << endl;
	cout << *p1 << "  " << p1.get() << endl;
	cout << p1.use_count();
#endif 

#if 0
	// Умные указатели STL
	/*
		auto_ptr;
		unique_ptr;
		shared_ptr;
	*/
	unique_ptr<int> p1(new int);
	*p1 = 789;
	cout << *p1 << "  " << p1.get() << endl;

	// unique_ptr<int> p2(p1); Запрещенно
	unique_ptr<int> p2;

	// p2.swap(p1);
	// или 
	p2 = move(p1);
	cout << *p2 << "  " << p2.get() << endl;

	//cout << *p1 << "  " << p1.get() << endl;

#endif 

#if 0
	// Умные указатели STL
	/*
		auto_ptr;
		unique_ptr;
		shared_ptr;
	*/

	auto_ptr<int> p1(new int);
	*p1 = 789;
	cout << *p1 << "  " << p1.get() << endl;

	auto_ptr<int> p2(p1);
	cout << *p2 << "  " << p2.get() << endl;

	
#endif 


#if 0
	/*
		Умный указатель(англ.smart pointer) — класс, имитирующий
		интерфейс обычного указателя и добавляющий к нему некую новую
		функциональность, например проверку границ при доступе или очистку
		памяти.
	*/

	SmartPointerT<int> sp1 = new int; // 1 выриант инициализации
	*sp1 = 200;
	cout << *sp1 << endl;

	int* k = new int(25);
	SmartPointerT<int> sp2(k); // 2 выриант инициализации
	cout << *sp2 << endl;
	*sp2 = 321;
	cout << *sp2 << endl;

	SmartPointerT<int> sp3(sp1);
	cout << *sp3 << endl;

	SmartPointerT<Coord>spc = new Circle(5, 3, 6.5);
	cout << *spc << endl;

	spc->show();

#endif 

#if 0
	try
	{

	}
	catch (const std::exception&)
	{
		cout << "\nmain";
	}

#endif

#if 0

	// Свой класс Исключение  MyException.h
	// В функции деления генерируем MyException, 
	// например для значения второго параметра  < 0

	int a = 5, b = -5;
	try
	{
		cout << division(a, b) << endl;
	}
	catch (const MyException& exp)
	{
		cout << "Error MyExeption\n";
		cout << exp.what();
		cout << "\nСостояние данных: " << exp.get_data();
	}
	catch(const exception& exp) 
	{
		cout << "\nError: " << exp.what();
		
	}
	catch (...)
	{
		cout << "\nЧто то пошло не так";
	}

#endif

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
	
#if 0
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
			ptr->init();
			ptr->show();
			delete ptr;
		}
	}
	catch (const std::exception& exp)
	{
		cout << exp.what();
		delete ptr;
	}
#endif 

#if 0
	string s("messages");
	s.at(3) = 'x';
	cout << s << '\n';

	cout << "string size = " << s.size() << '\n';
	cout << "string copacity = " << s.capacity() << '\n';

	try
	{
		s.at(3) = 'x';
	}
	catch (const char* exp)
	{
		cout << exp;
	}
	catch (out_of_range const& exp)
	{

	}
#endif 

#if 0
	StackD st(3);

	try
	{
		st.push(25);
		st.push(2);
		st.push(3);
		st.push(45);
	}
	catch (const char* exp)
	{
		st.show();
		cout << exp << endl;
	}

	//cout << st.isempty() << endl;

	int r;
	try
	{
		st.pop(r);
		cout << r << endl;
	}
	catch (const char* exp)
	{
		cout << exp << endl;
	}


#endif

}


