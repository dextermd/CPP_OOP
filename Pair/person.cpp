
#include <iostream>
#include <conio.h>

#include "Person.h"

using namespace std;

////------------------------------------------------------
//Person::Person()
//{
//	name = "no name";
//	surname = "no surname";
//	age = 0;
//	rost = ves = 0.0;
//	cout << "\nКонструктор Человек\n";
//}

//------------------------------------------------------
Person::Person(string n, string sn, int a, float r, float v) {
	name = n;
	surname = sn;
	age = a;
	rost = r;
	ves = v;
	//cout << "\nКонструктор Person\n";

}
//------------------------------------------------------
void Person::set_name(char *n)
{
	name = n;
}
//------------------------------------------------------
void Person::set_age(int a)
{
	age = a;
}
//------------------------------------------------------
void Person::set_rv(float r, float v)
{
	rost = r;
	ves = v;
}
//------------------------------------------------------
void Person::init()
{
	cout << "\n\nВведите Имя:       ";
	cin >> name;
	cout << "Фамилию:           ";
	cin >> surname;
	cout << "Возраст:           ";
	cin >> age;
	cout << "Рост:              ";
	cin >> rost;
	cout << "Вес:               ";
	cin >> ves;
	
}

//------------------------------------------------------
Person::~Person() { 
	//cout << "\nДеструктор Человек\n";
	//_getch();
}
//------------------------------------------------------
void Person::show()const {
	cout << "\n\nФамилия:      " << surname
		<< "\nИмя:          " << name
		<< "\nВозраст:      " << age
		<< "\nРост:         " << rost
		<< "\nВес:          " << ves;

}


bool Person::operator<(const Person& p1)const
{
	return this->surname < p1.surname;
}

bool Person::operator>(const Person& p1)const
{
	return this->surname > p1.surname;
}