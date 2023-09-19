#include "Hamster.h"

Hamster::Hamster() : HomePet()
{
}

Hamster::Hamster(const MyString& Name, const MyString& Type) : HomePet(Name, Type)
{
}

void Hamster::sound() const
{
	cout << "\nChewing";
}

void Hamster::show() const
{
	cout << "\nName: " << this->Name;
}

void Hamster::show_type() const
{
	cout << "\Type: " << this->Type;
}

Hamster::~Hamster()
{
}
