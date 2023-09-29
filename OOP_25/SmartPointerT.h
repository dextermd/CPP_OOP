#pragma once
#include <iostream>
#include <conio.h>
using namespace std;

//Шаблон класса, реализующий умный указатель

template <class T>
class SmartPointerT
{
	T* ptr;
	int count_copy;

public:
	SmartPointerT(T* p = nullptr);
	~SmartPointerT();

	//конструктор копирования
    SmartPointerT(const SmartPointerT& obj);
	// оператор =
	SmartPointerT & operator=(const SmartPointerT& obj);

	//перегрузка разименования указателя
	T & operator*() { return *ptr; }

	//перегрузка косвенного доступа 
	T* operator->() { return ptr; }

	// получение сырого указателя
	T* get_ptr() const { return ptr; }
};

//--------------------------------------------------------
template <class T>
SmartPointerT<T>::SmartPointerT(T* p) {
	cout << "\nКонструктор \n";
	ptr = p;
	count_copy = 0;
}

//---------------------------------------------------------
//уничтожение объекта
template <class T>
SmartPointerT<T>::~SmartPointerT() {
	/*cout << "\nДеструктор";
	delete ptr;*/
	
	cout << "\ncount_copy: " << count_copy;

	if (ptr != nullptr && count_copy == 0) {
		cout << "\nДеструктор объекта";
		delete ptr;
		ptr = nullptr;
	}
	else {
		
		count_copy--;
		cout << "\nДеструктор копии";
	}

	_getch();
}

//---------------------------------------------------------
template <class T>
SmartPointerT<T>::SmartPointerT(const SmartPointerT<T>& obj) {
	cout << "\nКонструктор копирования\n";
	ptr = obj.ptr;
	count_copy++;
}


//---------------------------------------------------------
//перегрузка оператора равно
template <class T>
SmartPointerT<T>& SmartPointerT<T>::operator=(const SmartPointerT<T>& obj) {

	ptr = obj.ptr;
	count_copy++;
	return *this;
}


//--------------------------------------------------------

/*
Умный указатель (англ. smart pointer) — класс, имитирующий
интерфейс обычного указателя и добавляющий к нему некую новую
функциональность, например проверку границ при доступе или очистку
памяти.

Иначе говоря, умные указатели — это объекты, в
которых хранится указатель на настоящий объект и, как
правило, счётчик числа обращений к объекту.

В классе также присутствует деструктор для настоящего объекта,
который не вызывается извне, а только
внутри smart pointer. Принцип таков, что, когда счётчик
обращений к объекту равен 0, вызовется деструктор.

*/





