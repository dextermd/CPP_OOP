#pragma once
#include "MyString.h"
#include <iostream>

using namespace std;

class HomePet
{
private:

protected:
	MyString Name;
	MyString Type;
	
public:
	HomePet();
	HomePet(const MyString& Name, const MyString& Type);

	virtual void sound() const = 0;
	virtual void show() const = 0;
	virtual void show_type() const = 0;

	virtual ~HomePet() = 0 {};


};

