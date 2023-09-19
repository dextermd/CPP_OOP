#include "HomePet.h"

HomePet::HomePet()
{
	this->Name = "No Name";
	this->Type = "No Type";
}

HomePet::HomePet(const MyString& Name, const MyString& Type)
{
	this->Name = Name;
	this->Type = Type;
}
