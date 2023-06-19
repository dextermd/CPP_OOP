//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <assert.h>
#include "MyString.h"
using namespace std;

#define DEBUG

int MyString::count = 0;

//MyString::MyString() // C++
//{
//#ifdef DEBUG
//	cout << "\nКонструткор по умолчанию\n";
//#endif // DEBUG
//
//	length = 3;
//	str = new char[length + 1];
//	strcpy_s(str, length + 1, "C++");
//	count++;
//}

MyString::MyString(const char* str)
{
#ifdef DEBUG
	cout << "\nКонструктор преобразования\n";
#endif // DEBUG
	this->length = strlen(str);
	this->str = new char[length + 1];
	strcpy_s(this->str, length + 1, str);
	count++;
}


MyString::MyString(const MyString & obj)
{
#ifdef DEBUG
	cout << "\nКонструктор копирования\n";
#endif // DEBUG

	this->length = obj.length;
	// Глубокое копирование
	this->str = new char[this->length + 1];
	strcpy_s(this->str, this->length + 1, obj.str);

	count++;
}

void MyString::init()
{
	char buf[500];
#ifdef DEBUG
	cout << "\nВведите строку: ";
#endif // DEBUG

	cin.getline(buf, sizeof(buf));
	if (strlen(str) != strlen(buf))
	{
		delete[] str; // освобождение старой памяти
		this->length = strlen(buf);// длина новой строки
		this->str = new char[length + 1];// выделение памяти под новое содержимое
	}
	strcpy_s(this->str, length + 1, buf);
}

void MyString::init(const char* str)
{
	if (strlen(this->str) != strlen(str))
	{
		delete[]this->str;
		length = strlen(str);
		this->str = new char[length + 1];
	}
	strcpy_s(this->str, length + 1, str);
}



int MyString::getLength()const
{
	return this->length;
}

/*static*/ int MyString::getCount() //статический метод
{
	return count; 
}

MyString MyString::add(const MyString& obj)
{
	MyString result;

	result.str = strcat_s(this->str, obj.str);

	return result;
}

void MyString::show()const
{
	/*std::*/cout << str;

#ifdef DEBUG
	cout << endl;
#endif // DEBUG
}

MyString::~MyString()
{
	count--;
#ifdef DEBUG
	cout << "\nДеструктор  "<< count << endl;
	_getch();
#endif // DEBUG
	
	delete[]str;
	str = nullptr;
}

