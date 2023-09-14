#pragma once

#include "MyArray.h"
#include "ListOneT.h"
#include "MyString.h"
#include <fstream>

class User
{
	MyString login;
	MyString password;
	MyString name;
	MyString surname;
	MyString email;
	MyString phone;
	MyString address;

public:
	User();
	User(const MyString& login, const MyString& password, const MyString& name, const MyString& surname,
		const MyString& email,const MyString& phone,const MyString& address);

	

	~User();
};

