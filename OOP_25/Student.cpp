#include "Student.h"

Student::Student() : Person()
{
	this->vuz = "No Vuz";
}

Student::Student(const MyString& name, const MyString surname, const int age, const float height, const float weigh, const MyString& vuz, const MyArray& grade)
		: Person(name, surname, age, height, weigh)
{
	this->vuz = vuz;
	this->grade = grade;
}

void Student::show() const
{
	Person::show();
	cout << "\nVuz:		" << this->vuz;
	cout << "\nGrade:		" << this->grade;
}

void Student::init()
{
	char buf[250];
	int size = 0;
	Person::init();

	cin.get();

	cout << "\nInput vuz: ";
	cin.getline(buf, sizeof(buf));
	this->vuz = buf;

	cout << "\nInput number of grades: ";
	cin >> size;

	if (size > 0)
	{
		int* arr_grades = new int[size];
		for (int i = 0; i < size; i++)
		{
			do
			{
				cout << "Input grade nr. " << i + 1 << " : ";
				cin >> arr_grades[i];
			} while (arr_grades[i] < 1 || arr_grades[i] > 12);
		}
		MyArray tmp(arr_grades, size);
		this->grade = tmp;
	
	}

}

float Student::get_average_grades()
{
	return this->grade.avarage_array();
}

Student::~Student()
{
}
