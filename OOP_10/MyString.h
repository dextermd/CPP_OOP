#pragma once

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

	~MyString();
};

