#include "Person.h"

Person::Person()
{
	this->name = "No Name";
	this->surname = "No Surname";
	this->age = 0;
	this->height = 0.0;
	this->weight = 0.0;
}

Person::Person(const MyString& name, const MyString& surname, const int age, const float height, const float weight)
{
	this->name = name;
	this->surname = surname;
	this->age = age;
	this->height = height;
	this->weight = weight;
}

void Person::show() const
{
	cout << "\nName:		" << this->name;
	cout << "\nSurname:	" << this->surname;
	cout << "\nAge:		" << this->age;
	cout << "\nHeight:		" << this->height;
	cout << "\nWeight:		" << this->weight;
}


void Person::init()
{
	char buf[250];

	cout << "\nInput name: ";
	cin.getline(buf, sizeof(buf));
	this->name = buf;

	cout << "\nInput surname: ";
	cin.getline(buf, sizeof(buf));
	this->surname = buf;

	cout << "\nInput age: ";
	cin >> this->age;

	cout << "\nInput height: ";
	cin >> this->height;

	cout << "\nInput weight: ";
	cin >> this->weight;

}

Person::~Person()
{
}
