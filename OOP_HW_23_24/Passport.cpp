#include "Passport.h"

Passport::Passport()
{
	this->FirstName = "No FirstName";
	this->LastName = "No LastName";
	this->DateOfBirth = "No DateOfBirth";
	this->PlaceOfBirth = "No PlaceOfBirth";
	this->Gender = "No Gender";
	this->BloodGroup = "No BloodGroup";
	this->DateOfIssue = "No DateOfIssue";
	this->IssuingDepartment = "No IssuingDepartment";
	this->ExpirationDate = "No ExpirationDate";
	this->SeriesAndNumber = "No SeriesAndNumber";
	this->Citizenship = "No Citizenship";
	this->IDNP = "No IDNP";
}

Passport::Passport(const MyString first_name, const MyString last_name, const MyString date_of_birth, const MyString place_of_birth,
	const MyString gender, const MyString blood_group, const MyString date_of_issue, const MyString issuing_department, const MyString expiration_date,
	const MyString series_and_number, const MyString citizenship, const MyString idnp)
{
	this->FirstName = first_name;
	this->LastName = last_name;
	this->DateOfBirth = date_of_birth;
	this->PlaceOfBirth = place_of_birth;
	this->Gender = gender;
	this->BloodGroup = blood_group;
	this->DateOfIssue = date_of_issue;
	this->IssuingDepartment = issuing_department;
	this->ExpirationDate = expiration_date;
	this->SeriesAndNumber = series_and_number;
	this->Citizenship = citizenship;
	this->IDNP = idnp;
}

void Passport::show() const
{
	cout << "\nFirstName:		" << this->FirstName;
	cout << "\nLastName:		" << this->LastName;
	cout << "\nDateOfBirth:		" << this->DateOfBirth;
	cout << "\nPlaceOfBirth:		" << this->PlaceOfBirth;
	cout << "\nGender:			" << this->Gender;
	cout << "\nBloodGroup:		" << this->BloodGroup;
	cout << "\nDateOfIssue:		" << this->DateOfIssue;
	cout << "\nIssuingDepartment:	" << this->IssuingDepartment;
	cout << "\nExpirationDate:		" << this->ExpirationDate;
	cout << "\nSeriesAndNumber:	" << this->SeriesAndNumber;
	cout << "\nCitizenship:		" << this->Citizenship;
	cout << "\nIDNP:			" << this->IDNP;
}

void Passport::init()
{
	char buf[250];

	cout << "\nInput FirstName: ";
	cin.getline(buf, sizeof(buf));
	this->FirstName = buf;

	cout << "\nInput LastName: ";
	cin.getline(buf, sizeof(buf));
	this->LastName = buf;

	cout << "\nInput DateOfBirth: ";
	cin.getline(buf, sizeof(buf));
	this->DateOfBirth = buf;

	cout << "\nInput PlaceOfBirth: ";
	cin.getline(buf, sizeof(buf));
	this->PlaceOfBirth = buf;

	cout << "\nInput Gender: ";
	cin.getline(buf, sizeof(buf));
	this->Gender = buf;

	cout << "\nInput BloodGroup: ";
	cin.getline(buf, sizeof(buf));
	this->BloodGroup = buf;

	cout << "\nInput DateOfIssue: ";
	cin.getline(buf, sizeof(buf));
	this->DateOfIssue = buf;

	cout << "\nInput IssuingDepartment: ";
	cin.getline(buf, sizeof(buf));
	this->IssuingDepartment = buf;

	cout << "\nInput ExpirationDate: ";
	cin.getline(buf, sizeof(buf));
	this->ExpirationDate = buf;

	cout << "\nInput SeriesAndNumber: ";
	cin.getline(buf, sizeof(buf));
	this->SeriesAndNumber = buf;

	cout << "\nInput Citizenship: ";
	cin.getline(buf, sizeof(buf));
	this->Citizenship = buf;

	cout << "\nInput IDNP: ";
	cin.getline(buf, sizeof(buf));
	this->IDNP = buf;
}

Passport::~Passport()
{
}
