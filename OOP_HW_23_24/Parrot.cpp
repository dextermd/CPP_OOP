#include "Parrot.h"

Parrot::Parrot() : HomePet()
{
}

Parrot::Parrot(const MyString& Name, const MyString& Type) : HomePet(Name, Type)
{
}

void Parrot::sound() const
{
	cout << "\nWhistle";
}

void Parrot::show() const
{
	cout << "\nName: " << this->Name;
}

void Parrot::show_type() const
{
	cout << "\Type: " << this->Type;
}

Parrot::~Parrot()
{
}
