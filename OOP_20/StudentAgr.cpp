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

void StudentAgr::save_txt(FILE* f) const
{

		fprintf(f, "\n\nSurname		: %s \n", this->surname);
		fprintf(f, "Name		: %s \n", this->name);
		fprintf(f, "Age		: %d \n", this->age);
		fprintf(f, "Vuz		: %s \n", this->vuz);

		if (marks.avarage_array())
		{
			fprintf(f, "Count Marks	: %d\n", this->marks.get_size());
			fprintf(f, "Marks		: ");

			for (int i = 0; i < this->marks.get_size(); i++)
			{
				fprintf(f, "%d ", this->marks[i]);
			}

			fprintf(f, "\nAverage Marks	: %f \n", this->get_average());
		}

		fprintf(f, "Subjects	: ");

		for (int i = 1; i <= subjects.get_count(); i++)
		{
			fprintf(f, "%s ", this->subjects.get_by_pos(i).get_str());
		}

		//printf("\nOk\n\n");
}

bool StudentAgr::operator<(const StudentAgr& obj)
{
	return this->surname < obj.surname;
}

double StudentAgr::get_average() const
{
	return this->marks.avarage_array();
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
		out << "MarksAverage:	" << student.get_average() << endl;
	}
	else {
		out << "Empty Marks " << endl;
	}
	//out << "Subjects:		" << student.subjects << endl;
	out << "Subjects:	";
	student.subjects.show();

	return out;
}
