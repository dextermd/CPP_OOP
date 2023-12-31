//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <assert.h>
#include "MyString.h"

using namespace std;


// #define DEBUG

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

MyString::MyString(MyString&& obj)
{
	/*
	  Копия данных не производится, задача -
	  переместить ресурсы с одного объекта на другой,
	  а не копировать их.
  */

#ifdef DEBUG
	cout << "\nКонструктор перемещения\n";
#endif // DEBUG
	this->length = obj.length;
	this->str = obj.str; // копия адреса

	obj.str = nullptr;
	obj.length = 0;
	
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

void MyString::save_to_binary_file(FILE* file)
{
	// Запись длины строки
	fwrite(&this->length, sizeof(this->length), 1, file);
	// Запись содержимого строки
	fwrite(this->str, this->length + 1, 1, file);
}

void MyString::read_from_binary_file(FILE* file)
{
	delete[] str;
	// Чтение длины строки
	fread(&this->length, sizeof(this->length), 1, file);

	// Выделяем новую память 
	this->str = new char[this->length + 1];

	// Чтение содержимого строки
	fread(this->str, this->length + 1, 1, file);
}

MyString MyString::add(const MyString& obj)
{
	MyString result;

	if (result.str)
	{
		delete[] result.str;
	}

	result.length = obj.length + this->length + 1;
	result.str = new char[result.length + 1];

	if (result.str)
	{
		strcpy_s(result.str, result.length + 1 + 2, this->str);
		strcat_s(result.str, result.length + 1 + 2, obj.str);
	}

	return result;
}


void MyString::show()const
{
	/*std::*/cout << str;

#ifdef DEBUG
	cout << endl;
#endif // DEBUG
}

MyString& MyString::operator=(const MyString& obj)
{
	if (this == &obj)
		return *this;


	if (this->length != obj.length)
	{
		this->length = obj.length;
		delete[] this->str;
		this->str = new char[this->length + 1];
	}

	strcpy_s(this->str, this->length + 1, obj.str);

	return *this;
}

MyString& MyString::operator=(MyString&& obj) // operator= с перемещением без глубокого копирования
{
	if (this == &obj)
		return *this;

	if (this->str)
		delete[] this->str;

	this->length = obj.length;
	this->str = obj.str;

	obj.length = 0;
	obj.str = nullptr;

	return *this;
}

const char MyString::operator[](const int idx) const
{
	if (idx < 0 || idx > this->length)
	{
		cout << "\nНеверный индекс\n";
		return '\0';
	}
	// assert(idx >= 0 && idx < this->length);
	return this->str[idx];
}

char& MyString::operator[](const int idx)
{
	if (idx < 0 || idx > this->length)
	{
		cout << "\nНеверный индекс\n";
	}
	// assert(idx >= 0 && idx < this->length);
	return this->str[idx];
}

bool MyString::operator==(const MyString& obj) const
{
	// return strcmp(this->str, obj.str) == 0;
	return !strcmp(this->str, obj.str);
}

bool MyString::operator!=(const MyString& obj) const
{
	// return strcmp(this->str, obj.str) != 0;
	//return strcmp(this->str, obj.str);
	return !(*this == obj);
}

bool MyString::operator>(const MyString& obj) const
{
	// return strcmp(this->str, obj.str) > 0;
	return _strcmpi(this->str, obj.str) > 0; // без учета регистра
}

bool MyString::operator<(const MyString& obj) const
{
	return _strcmpi(this->str, obj.str) < 0; // без учета регистра
}

bool MyString::operator>=(const MyString& obj) const
{
	return (*this > obj || *this == obj);
}

bool MyString::operator<=(const MyString& obj) const
{
	return (*this < obj || *this == obj);
}

MyString MyString::operator+(const MyString& obj)
{
	MyString result;

	if (result.str)
	{
		delete[] result.str;
	}

	result.length = obj.length + this->length + 1;
	result.str = new char[result.length + 1];

	if (result.str)
	{
		strcpy_s(result.str, result.length + 1 , this->str);
		strcat_s(result.str, result.length + 1 , obj.str);
	}

	return result;
}

MyString& MyString::operator+=(const MyString& obj)
{
	MyString temp = *this + obj;
	*this = temp;
	return *this;
}

void MyString::operator()(const char* str)
{
	if (strlen(this->str) != strlen(str))
	{
		delete[] this->str;
		this->length = strlen(str);
		this->str = new char[this->length + 1];
	}

	if (this->str)
		strcpy_s(this->str, this->length + 1, str);

}

ostream& operator<<(ostream& out, const MyString& str)
{
	out << str.str;
	return out;
}

istream& operator>>(istream& in, MyString& str)
{
	char buf[250];
	cin.getline(buf, sizeof(buf));

	if (strlen(str.str) != strlen(buf))
	{
		delete[] str.str;
		str.length = strlen(buf);
		str.str = new char[str.length + 1];
	}

	strcpy_s(str.str, str.length + 1, buf);

	return in;
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

