#include "ForeignPassport.h"

ForeignPassport::ForeignPassport() : Passport()
{
	this->PassportNumber = "No PassportNumber";
}

ForeignPassport::ForeignPassport(const MyString first_name, const MyString last_name, const MyString date_of_birth,
	const MyString place_of_birth, const MyString gender, const MyString blood_group, const MyString date_of_issue,
	const MyString issuing_department, const MyString expiration_date, const MyString series_and_number, const MyString citizenship,
	const MyString idnp, const MyString passport_number, const ListOneT<MyString> visa) : 
	Passport(first_name, last_name, date_of_birth, place_of_birth, gender, blood_group,
		date_of_issue, issuing_department, expiration_date, series_and_number, citizenship, idnp)
{
	this->PassportNumber = passport_number;
	this->Visa = visa;
}

void ForeignPassport::show() const
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
	cout << "\nCitizenship:		" << this->Citizenship;
	cout << "\nIDNP:			" << this->IDNP;
	cout << "\nPassportNumber:		" << this->PassportNumber;
	cout << "\nVisa:			";
	this->Visa.show();

}

void ForeignPassport::add_visa(MyString& visa)
{
	this->Visa.add_begin(visa);
}

void ForeignPassport::init()
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

	cout << "\nInput Citizenship: ";
	cin.getline(buf, sizeof(buf));
	this->Citizenship = buf;

	cout << "\nInput IDNP: ";
	cin.getline(buf, sizeof(buf));
	this->IDNP = buf;
}

ForeignPassport::~ForeignPassport()
{
}
