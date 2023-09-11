#pragma once

#include "MyString.h"
#include "MyArray.h"
#include "ListOneType.h"

class StudentAgr {
	MyString surname;
	MyString name;
	int age;
	MyString vuz;
	MyArray marks;
	ListOneType<MyString> subjects;

public:
	StudentAgr();
	StudentAgr(const MyString& surname, const MyString& name, int age,
		const MyString &vuz, const MyArray & marks, const ListOneType<MyString> & subjects);
	
	void add_subject(const MyString& data);

	int get_age()const { return age; }
	
	double get_average()const
	{
		return this->marks.average();
	}

	bool operator<(const StudentAgr& student);

	friend ostream & operator<<(ostream& out, const StudentAgr& student);

	void save_txt(FILE* f)const;

	void save_to_binary_file(FILE* f);
	void read_from_binary_file(FILE* f);

	void save_to_binary_file2(FILE* f);
	void read_from_binary_file2(FILE* f);
};
