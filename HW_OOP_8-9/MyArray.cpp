#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include "MyArray.h"

using namespace std;

MyArray::MyArray()
{
	size = 5;
	arr = new int[size];
	if (arr)
	{
		for (int i = 0; i < size; i++)
		{
			arr[i] = 0;
		}
	}
}

MyArray::MyArray(const int num, const unsigned int size)
{
	this->size = size;
	this->arr = new int[this->size];
	if (this->arr)
	{
		for (int i = 0; i < this->size; i++)
		{
			this->arr[i] = num;
		}

	}
}

MyArray::MyArray(const int* arr, const unsigned int size)
{
	this->size = size;
	this->arr = new int[this->size];
	if (this->arr)
	{
		for (int i = 0; i < this->size; i++)
		{
			this->arr[i] = arr[i];
		}

	}
}

MyArray::MyArray(const unsigned int size, const int min, const int max)
{
	srand(time(0));
	this->size = size;
	this->arr = new int[this->size];

	if (this->arr)
	{
		for (int i = 0; i < this->size; i++)
		{
			int rnum = rand() % (min - max + 1) + max;
			this->arr[i] = rnum;
		}
	}

}

MyArray::MyArray(const MyArray& obj)
{
	this->size = obj.size;
	this->arr = new int[this->size];
	if (this->arr)
	{
		for (int i = 0; i < this->size; i++)
		{
			this->arr[i] = obj.arr[i];
		}
	}
}

const void MyArray::show() const
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
}

void MyArray::init()
{
	cout << "\nВведите размер массива: ";
	cin >> size;
	cout << "\nПроинициализируйте массив: \n";
	if (arr)
		delete[] arr;
	arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		cout << "Введите значение №" << i + 1 << " ";
		cin >> arr[i];
	}

}

const double MyArray::avarage_array() const
{
	double result = 0.0;

	for (int i = 0; i < size; i++)
	{
		result += arr[i];
	}

	return result / (double)size;
}

MyArray MyArray::add(const MyArray& obj) const
{
	MyArray result;
	bool bFirstIsMax;
	unsigned int t_size, t_size_min;

	this->size > obj.size ? bFirstIsMax = true : bFirstIsMax = false;
	bFirstIsMax ? t_size = this->size, t_size_min = obj.size : t_size = obj.size, t_size_min = this->size;

	result.arr = new int[t_size];
	result.size = t_size;

	for (int i = 0; i < t_size_min; i++)
	{
		if (result.arr)
		{
			result.arr[i] = arr[i] + obj.arr[i];
			
		}
	}
	for (int i = t_size_min; i < result.size; i++)
	{
		if (result.arr)
		{
			if (this->size > obj.size)
			{
				result.arr[i] = arr[i];
			}
			else {
				result.arr[i] = obj.arr[i];
			}
			

		}
	}

	return result;

}

MyArray::~MyArray()
{
	delete[] arr;
	arr = nullptr;
}


