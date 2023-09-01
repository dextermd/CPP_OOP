#pragma once
#include "MyString.h"
#include "MyArray.h"
#include "ListOneT.h"
#include <iostream>

using namespace std;

class StudentAgr
{
	MyString surname;
	MyString name;
	int age;
	MyString vuz;
	MyArray marks;
	ListOneT<MyString> subjects;

public:
	// Конструкторы
	StudentAgr();
	StudentAgr(const MyString& surname, const MyString& name, int age, const MyString& vuz, const MyArray& marks, const ListOneT<MyString>& subjects);

	// Методы
	void add_subject( const MyString& data);
	void save_txt(FILE* f) const;

	// Перегрузки
	friend ostream& operator<<(ostream& out, const StudentAgr& student);

	bool operator<(const StudentAgr& obj);

	double get_average()const;


	// Getter
	int get_age() const { return age; };

	

};

