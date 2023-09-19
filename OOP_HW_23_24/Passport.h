#pragma once
#include "MyString.h"
#include <iostream>

using namespace std;

class Passport
{
private:
	MyString SeriesAndNumber;

protected:
	MyString FirstName;
	MyString LastName;
	MyString DateOfBirth;
	MyString PlaceOfBirth;
	MyString Gender;
	MyString BloodGroup;
	MyString DateOfIssue;
	MyString IssuingDepartment;
	MyString ExpirationDate;
	MyString Citizenship;
	MyString IDNP;

public:
	Passport();
	Passport(const MyString first_name, const MyString last_name, const MyString date_of_birth, const MyString place_of_birth, const MyString gender,
		const MyString blood_group, const MyString date_of_issue, const MyString issuing_department, const MyString expiration_date, const MyString series_and_number,
		const MyString citizenship, const MyString idnp);

	virtual void show() const;
	virtual  void init();

	virtual  ~Passport();

};

