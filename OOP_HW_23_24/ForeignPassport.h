#pragma once
#include "Passport.h"
#include "ListOneT.h"
#include <iostream>

using namespace std;

class ForeignPassport : public Passport
{
private:
	MyString PassportNumber;
	ListOneT<MyString> Visa;

public:
	ForeignPassport();
	ForeignPassport(const MyString first_name, const MyString last_name, const MyString date_of_birth, const MyString place_of_birth,
		const MyString gender, const MyString blood_group, const MyString date_of_issue, const MyString issuing_department, const MyString expiration_date,
		const MyString series_and_number, const MyString citizenship, const MyString idnp, const MyString passport_number, const ListOneT<MyString> visa);

	void show() const;
	void add_visa(MyString& visa);
	void init();

	~ForeignPassport();
};

