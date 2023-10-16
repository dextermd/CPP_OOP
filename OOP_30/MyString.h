#pragma once
#include <iostream>
#include <fstream>

class MyString
{
	char * str;
	int length;

	static int count;

public:
	MyString() : MyString("C++") { } // делегирующий конструктор
	/*explicit*/ MyString(const char* str);
	MyString(int len, char symbol = ' ');
	MyString(const MyString & obj); // !!! Конструктор копирования

	void init();
	void init(const char * str); // set
	void show()const;
	int getLength()const;

	void setLength(int length)  //***
	{
		delete [] this->str;
		this->length = length;
		this->str = new char[this->length + 1];
	}

	static int getCount();
	char* get_str()const { return str; }

	MyString add(const MyString& obj)const;

	MyString& operator=(const MyString& obj);//!!!

	const char operator[](const int index)const;
	char& operator[](const int index);

	bool operator==(const MyString& obj) const;
	bool operator!=(const MyString& obj) const;
	bool operator>(const MyString& obj) const;

	bool operator<(const MyString& other)const;
	bool operator>=(const MyString& other)const;
	bool operator<=(const MyString& other)const;

	MyString operator+(const MyString& obj)const;
	//MyString operator+(const char* obj)const;

	MyString& operator+=(const MyString& obj);

	// Перегрузка потока вывода на экран <<
	friend std::ostream& operator<<(std::ostream& out, const MyString& obj);

	// Перегрузка потока ввода (>>)
	friend std::istream& operator>>(std::istream& in, MyString& obj);

	// Перегрузка ()
	void operator()(const char* str = "Hello");

	//operator type : из MyString в char*
	operator char* () { return this->str; }

	void save_to_binary_file(FILE* f);
	void read_from_binary_file(FILE* f);

	void save_to_binary_file_2(std::ofstream& fout) const;
	void read_from_binary_file_2(std::ifstream& fin);

	// Перегрузка потока записи в файл <<
	friend std::ostream& operator<<(std::ofstream& out, const MyString& obj);

	~MyString();//!!!
};

