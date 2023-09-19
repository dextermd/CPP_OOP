#pragma once
#include "MyString.h"
#include <iostream>
#include "HomePet.h"

using namespace std;

class Cat : virtual public HomePet
{
private:

public:
	Cat();
	Cat(const MyString& Name, const MyString& Type);

	void sound() const override;
	void show() const override;
	void show_type() const override;

	~Cat();
};
