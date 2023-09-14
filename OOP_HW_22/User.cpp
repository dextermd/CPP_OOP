#include "User.h"

User::User()
{
	this->login = "No Login";
	this->password = "No Password";
	this->name		= "No Name";
	this->surname	= "No Surname";
	this->email		= "No Email";
	this->phone		= "No Phone";
	this->address	= "No Address";
}

User::User(const MyString& login, const MyString& password, const MyString& name, const MyString& surname,
	const MyString& email, const MyString& phone, const MyString& address)
{
	this->login = login;
	this->password = password;
	this->name = name;
	this->surname = surname;
	this->email = email;
	this->phone = phone;
	this->address = address;
}
