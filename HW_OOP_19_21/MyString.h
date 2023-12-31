#pragma once

#include <iostream>
using namespace std;

class MyString
{
	char* str;
	int length;

	static int count;

public:
	MyString() : MyString("Hello") {} // Делегирующий конструктор
	MyString(const char* str);
	
	MyString(const MyString & obj); // Конструктор копирования
	MyString(MyString&& obj); // Конструктор перемещения

	void init();
	void init(const char * str); // set
	void show()const;
	int getLength()const;
	static int getCount();
	char* get_str() { return str; };
	void save_to_binary_file(FILE* file);
	void read_from_binary_file(FILE* file);

	MyString add(const MyString& obj);

	MyString& operator=(const MyString& obj); // Оператор = с глубоким копированием
	MyString& operator=(MyString&& obj); // Оператор = с перемещением без глубокого копирования

	const char operator[](const int idx) const;
	char& operator[](const int idx);

	bool operator==(const MyString& obj) const;
	bool operator!=(const MyString& obj) const;
	bool operator>(const MyString& obj) const;
	bool operator<(const MyString& obj) const;
	bool operator>=(const MyString& obj) const;
	bool operator<=(const MyString& obj) const;

	MyString operator+(const MyString& obj);
	MyString& operator+=(const MyString& obj);

	friend ostream& operator<<(ostream& out, const MyString& str);
	friend istream& operator>>(istream& in, MyString& str);

	void operator()(const char* str);

	// operator type
	operator char* () { return this->str;};

	~MyString();
};

