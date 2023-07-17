#pragma once
#include <iostream>

using namespace std;

class BigNumber
{
	static const int SIZE = 80;
	int arr[SIZE];

public:

	BigNumber();
	BigNumber(int number);
	BigNumber(const char* str);
	BigNumber(const int* arr, const unsigned int size);

	const void show_default() const;

	friend ostream& operator<<(std::ostream& out, const BigNumber& obj);
};

