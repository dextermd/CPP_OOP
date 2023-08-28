#include <iostream>
#include "StudentAgr.h"

using namespace std;

StudentAgr::StudentAgr()
{
	this->surname = "No Surname";
	this->name = "No Name";
	this->age = 0;
	this->vuz = "No Vuz";
}

StudentAgr::StudentAgr(const MyString& surname, const MyString& name, int age, const MyString& vuz, const MyArray& marks, const ListOneT<MyString>& subjects)
{
	this->surname = surname;
	this->name = name;
	this->age = age;
	this->vuz = vuz;
	this->marks = marks;
	this->subjects = subjects;
}

void StudentAgr::add_subject(const MyString& data)
{
	this->subjects.add_begin(data);
}

bool StudentAgr::operator<(const StudentAgr& obj)
{
	return this->surname < obj.surname;
}

ostream& operator<<(ostream& out, const StudentAgr& student)
{
	out << "\nSurname:	" << student.surname << endl;
	out << "\Name:		" << student.name << endl;
	out << "\Age:		" << student.age << endl;
	out << "\Vuz:		" << student.vuz << endl;
	if (student.marks.avarage_array())
	{
		out << "Count Marks:	" << student.marks.get_size() << endl;
		out << "Marks:		" << student.marks;
	}
	else {
		out << "Empty Marks " << endl;
	}
	//out << "Subjects:		" << student.subjects << endl;
	out << "Subjects:	";
	student.subjects.show();

	return out;
}
