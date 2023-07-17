#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include "BigNumber.h"

using namespace std;

BigNumber::BigNumber()
{
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = 0;
	}
}

BigNumber::BigNumber(int number)
{
	int count = 0;
	while (number)
	{
		this->arr[79 - count] = number % 10;
		number /= 10;
		count++;
	}

	for (int i = 79 - count; i >= 0; i--)
	{
		this->arr[i] = 0;
	}

}

BigNumber::BigNumber(const char* str)
{
	int count = 0, size = 80;
	for (const char* ptr = str; *ptr != '\0'; ++ptr) 
	{
		if (isdigit(*ptr))
		{
			count++;
		}
	}

	int value = size - count;

	for (const char* ptr = str; *ptr != '\0'; ++ptr) {
		
		if (isdigit(*ptr))
		{
			char digit[1] = { *ptr };
			this->arr[value++] = atoi(digit);
		}
	}


	for (int i = 79 - count; i >= 0; i--)
	{
		this->arr[i] = 0;
	}

}

BigNumber::BigNumber(const int* arr, const unsigned int size)
{
	for (int i = 0; i < 80; i++) 
	{
		this->arr[i] = 0;
	}

	for (int i = 80 - size, k = 0; i < 80; i++, k++) 
	{
		this->arr[i] = arr[k];
	}
}

const void BigNumber::show_default() const
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i] << " ";
	}
}

ostream& operator<<(std::ostream& out, const BigNumber& obj)
{

	cout << setw(80);

	for (int i = 0; i < 80; i++)
	{
		if (obj.arr[i] != 0)
		{
			out << obj.arr[i];
		}
	}
	return out;
}
