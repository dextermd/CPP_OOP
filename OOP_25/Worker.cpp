#include "Worker.h"

Worker::Worker() : Person()
{
	this->company = "No Company";
	this->experience = 0.0;
	this->salary = 0.0;
}

Worker::Worker(const MyString& name, const MyString& surname, const int age, const float height, const float weight, const MyString company, const float experience, const float salary)
	: Person(name, surname, age, height, weight)
{
	this->company = company;
	this->experience = experience;
	this->salary = salary;
}

void Worker::show() const
{
	Person::show();
	cout << "\nCompany		" << this->company;
	cout << "\nExperience	" << this->experience;
	cout << "\nSalary		" << this->salary;
}

void Worker::init()
{
	char buf[250];
	Person::init();
	cin.get();
	cout << "\nInput company: ";
	cin.getline(buf, sizeof(buf));
	this->company = buf;

	cout << "\nInput experience: ";
	cin >> this->experience;

	cout << "\nInput salary: ";
	cin >> this->salary;
}

Worker::~Worker()
{
}
