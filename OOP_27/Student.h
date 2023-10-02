#pragma once
#include "Person.h"
#include "MyArray.h"

class Student : virtual public Person
{
private:

protected:
	MyString vuz;
	MyArray grade;

public:
	Student();
	Student(const MyString& name, const MyString surname, const int age, const float height, const float weigh, const MyString& vuz, const MyArray& grade);

	void show() const override;
	void init() override;
	float get_average_grades();

	~Student();
};

