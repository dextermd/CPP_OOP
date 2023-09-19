#include "Dog.h"

Dog::Dog() : HomePet()
{
}

Dog::Dog(const MyString& Name, const MyString& Type) : HomePet(Name, Type)
{
}

void Dog::sound() const
{
	cout << "\nWoof-woof";
}

void Dog::show() const
{
	cout << "\nName: " << this->Name;
}

void Dog::show_type() const
{
	cout << "\Type: " << this->Type;
}

Dog::~Dog()
{
}
