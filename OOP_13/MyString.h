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

	void init();
	void init(const char * str); // set
	void show()const;

	int getLength()const;
	static int getCount();

	MyString add(const MyString& obj);

	MyString& operator=(const MyString& obj);

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

