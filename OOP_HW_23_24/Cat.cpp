#include "Cat.h"

Cat::Cat() : HomePet()
{
}

Cat::Cat(const MyString& Name, const MyString& Type) : HomePet(Name, Type)
{
}

void Cat::sound() const
{
	cout << "\nMeow";
}

void Cat::show() const
{
	cout << "\nName: " << this->Name;
}

void Cat::show_type() const
{
	cout << "\Type: " << this->Type;
}

Cat::~Cat()
{
}
