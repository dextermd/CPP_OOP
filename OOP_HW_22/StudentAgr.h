#pragma once

#include "MyArray.h"
#include "ListOneT.h"
#include "MyString.h"
#include <fstream>

class StudentAgr {
	MyString surname;
	MyString name;
	int age;
	MyString vuz;
	MyArray marks;
	ListOneT<MyString> subjects;

public:
	StudentAgr();
	StudentAgr(const MyString& surname, const MyString& name, int age,
		const MyString &vuz, const MyArray & marks, const ListOneT<MyString> & subjects);
	
	void add_subject(const MyString& data);

	int get_age()const { return age; }
	
	double get_average()const;

	bool operator<(const StudentAgr& student);

	friend ostream & operator<<(ostream& out, const StudentAgr& student);

	void save_txt(FILE* f)const;

	void save_to_binary_file(FILE* f);
	void read_from_binary_file(FILE* f);

	void save_to_binary_file2(FILE* f);
	void read_from_binary_file2(FILE* f);

	void save_to_file_plus(std::ostream& fout) const;

	// Перегрузка потока записи в файл <<
	friend std::ostream& operator<<(std::ofstream& out, StudentAgr& obj);
	// Перегрузка потока чтении из файла >>
	friend std::istream& operator>>(std::ifstream& in, StudentAgr& obj);


};
