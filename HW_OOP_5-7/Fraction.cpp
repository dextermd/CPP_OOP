#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include "Fraction.h"

using namespace std;



Fraction::Fraction()
{
	this->numerator = 10;
	this->denominator = 10;

}

Fraction::Fraction(const int a, const int b)
{
	this->numerator = a;
	this->denominator = b;
}

void Fraction::correct()
{
	if (this->denominator == 0)
		denominator = 1;
}

void Fraction::show() const
{
	cout << "Numerator -> " << numerator << endl;
	cout << "Denominator -> " << denominator << endl;
}

void Fraction::show(const Fraction* arr, const int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i].show();
	}
}

void Fraction::init()
{
	cout << "Введите числитель: ";
	cin >> numerator;
	cout << "Введите знаменатель: ";
	cin >> denominator;
	correct();
}

int Fraction::get_numerator() const
{
	return numerator;
}

void Fraction::set_numerator(const int numerator)
{
	this->numerator = numerator;
}

int Fraction::get_denominator() const
{
	return denominator;
}

void Fraction::set_denominator(const int denominator)
{
	this->denominator = denominator;
	correct();
}

Fraction::Fraction(const char* str)
{
	char* copy;
	copy = new char[strlen(str) + 1];
	strcpy_s(copy, strlen(str) + 1, str);
	char* t1;
	char* t2;

	t1 = strtok_s(copy, ":, ./_-\\.|", &t2);
	this->numerator = atoi(t1);
	t1 = strtok_s(nullptr, ":, ./_-\\.", &t2); //this->denominator = atoi(t2);
	this->denominator = atoi(t1);
	correct();

	delete[] copy;
	copy = nullptr;
}

Fraction Fraction::arithmetic_operations(const Fraction& obj, char operation) const
{
	Fraction result;

	switch (operation)
	{
	case '+':
		cout << "Cложение: \n";
		result.numerator = this->numerator + obj.numerator;
		result.denominator = this->denominator + obj.denominator;
		//return result;
		break;
	case '-':
		cout << "Вычитание: \n";
		result.numerator = this->numerator - obj.numerator;
		result.denominator = this->denominator - obj.denominator;
		//return result;
		break;
	case '*':
		cout << "Умножение: \n";
		result.numerator = this->numerator * obj.numerator;
		result.denominator = this->denominator * obj.denominator;
		//return result;
		break;
	case '/':
		cout << "Деление: \n";
		result.numerator = this->numerator / obj.numerator;
		result.denominator = this->denominator / obj.denominator;
		//return result;
		break;
	}

	return result;
}







Fraction::~Fraction()
{
}
