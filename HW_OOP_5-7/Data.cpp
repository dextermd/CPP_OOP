#include "Data.h"
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <ctime>
#include <Windows.h>
#include "Fraction.h"

using namespace std;


Data::Data()
{
	this->day = 12;
	this->month = 6;
	this->year = 2023;
}

Data::Data(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

Data::Data(const char* str)
{
	char* copy;
	copy = new char[strlen(str) + 1];
	strcpy_s(copy, strlen(str) + 1, str);
	char* t1;
	char* t2;

	t1 = strtok_s(copy, "/.", &t2);
	this->day = atoi(t1);
	t1 = strtok_s(nullptr, "/.", &t2);
	this->month = atoi(t1);
	t1 = strtok_s(nullptr, "/.", &t2);
	this->year = atoi(t1);

	delete[] copy;
	copy = nullptr;
}

void Data::show() const
{
	char* month_ptr = correct_month();
	cout << month_ptr << "," << day << "," << year << ".";
	delete[] month_ptr;
}

void Data::init()
{
	bool bIsCorrectData = false;
	do
	{
		cout << "Введите день: ";
		cin >> day;
		cout << "Введите месяц: ";
		cin >> month;
		cout << "Введите год: ";
		cin >> year;

		bIsCorrectData = is_date_valid(day, month, year);
		
	} while (!bIsCorrectData);

}

bool Data::is_date_valid(int day, int month, int year)
{
	int days_in_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (year < 0 || month < 1 || month > 12 || day < 1)
		return false;

	if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
		days_in_month[1] = 29;

	if (day > days_in_month[month - 1])
		return false;
	
	return true;
}

char* Data::correct_month() const
{
	char* month_s = new char[20];
	switch (this->month - 1)
	{
	case JANUARY:
		strcpy_s(month_s, 20, "Январь");
		break;
	case FEBRUARY:
		strcpy_s(month_s, 20, "Февраль");
		break;
	case MARCH:
		strcpy_s(month_s, 20, "Март");
		break;
	case APRIL:
		strcpy_s(month_s, 20, "Апрель");
		break;
	case MAY:
		strcpy_s(month_s, 20, "Май");
		break;
	case JUNE:
		strcpy_s(month_s, 20, "Июнь");
		break;
	case JULY:
		strcpy_s(month_s, 20, "Июль");
		break;
	case AUGUST:
		strcpy_s(month_s, 20, "Август");
		break;
	case SEPTEMBER:
		strcpy_s(month_s, 20, "Сентябрь");
		break;
	case OCTOBER:
		strcpy_s(month_s, 20, "Октябрь");
		break;
	case NOVEMBER:
		strcpy_s(month_s, 20, "Ноябрь");
		break;
	case DECEMBER:
		strcpy_s(month_s, 20, "Декабрь");
		break;
	}

	return month_s;

	delete[] month_s;
}



