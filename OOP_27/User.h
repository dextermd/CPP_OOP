#pragma once

#include "MyArray.h"
#include "MyString.h"
#include "ListOneT.h"
#include <iostream>
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

	void show() const;
	void init(ListOneT<User>& data);
	void signin(ListOneT<User>& data) const;
	void read_from_binary_file_plus(std::ifstream& in) const;

	MyString& get_login() { return this->login; };
	MyString& get_password() { return this->password; };

	// Перегрузка потока вывода <<
	friend ostream& operator<<(ostream& out, const User& user);
	// Перегрузка потока записи в файл <<
	friend std::ostream& operator<<(std::ofstream& out, User& obj);
	// Перегрузка потока чтении из файла >>
	friend std::istream& operator>>(std::ifstream& in, User& obj);

	~User();
};

