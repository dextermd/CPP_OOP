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
			if (min < max)
			{
				int rnum = rand() % (max - min + 1) + min;
				this->arr[i] = rnum;
			}
			else {
				int rnum = rand() % (min - max + 1) + max;
				this->arr[i] = rnum;
			}
			
			
		}
	}

}

MyArray::MyArray(const MyArray& obj) // Конструктор копии
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

MyArray::MyArray(MyArray&& obj) // Конструктор перемещения
{
	this->size = obj.size;
	this->arr = obj.arr;

	obj.size = 0;
	obj.arr = nullptr;
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
	unsigned int t_size = this->size + obj.size;

	if (result.arr)
	{
		delete[] result.arr;
	}
	
	result.arr = new int[t_size];
	result.size = t_size;

	for (int i = 0; i < this->size; i++)
	{
		if (result.arr)
		{
			result.arr[i] = this->arr[i];
			
		}
	}
	
	for (int i = this->size; i < t_size; i++)
	{
		if (result.arr)
		{
			result.arr[i] = obj.arr[i - this->size];
		}
	}

	return result;

}


MyArray& MyArray::operator=(const MyArray& obj) // operator= без перемещения с глубоким копированием
{
	if (this == &obj)
		return *this;


	if (this->size != obj.size)
	{
		this->size = obj.size;
		delete[] this->arr;
		this->arr = new int[this->size];
	}

	for (int i = 0; i < this->size; i++)
	{
		this->arr[i] = obj.arr[i];
	}

	return *this;
}

MyArray& MyArray::operator=(MyArray&& obj)  // operator= с перемещением без глубокого копирования
{
	if (this == &obj)
		return *this;

	if (this->arr)
		delete[] this->arr;

	this->size = obj.size;
	this->arr = obj.arr;

	obj.size = 0;
	obj.arr = nullptr;

	return *this;
}



const int MyArray::operator[](const int idx) const
{
	if (idx < 0 || idx > this->size)
	{
		cout << "\nНеверный индекс\n";
		return '\0';
	}
	// assert(idx >= 0 && idx < this->length);
	return this->arr[idx];
}

int& MyArray::operator[](const int idx)
{
	if (idx < 0 || idx > this->size)
	{
		cout << "\nНеверный индекс\n";
	}

	return this->arr[idx];
}

MyArray& MyArray::operator+=(const int num)
{
	if (this->size != num && num > 0)
	{
		MyArray temp;

		if (temp.arr)
		{
			delete[] temp.arr;
			temp.size = this->size;
			temp.arr = new int[temp.size];
		}

		for (int i = 0; i < temp.size; i++)
		{
			temp.arr[i] = this->arr[i];
		}

		this->size += num;
		delete[] this->arr;
		this->arr = new int[this->size];

		for (int i = 0; i < temp.size; i++)
		{
			this->arr[i] = temp[i];
		}


		for (int i = temp.size; i < this->size; i++)
		{
			this->arr[i] = 0;
		}

		// delete[] temp.arr;  // По идее temp мне больше не нужен, но при добавлении этого кода вылетает программа.
	}

	return *this;
}

MyArray& MyArray::operator+=(const MyArray& obj)
{

		MyArray temp;

		if (temp.arr)
		{
			delete[] temp.arr;
			temp.size = this->size;
			temp.arr = new int[temp.size];
		}

		for (int i = 0; i < temp.size; i++)
		{
			temp.arr[i] = this->arr[i];
		}

		this->size += obj.size;
		delete[] this->arr;
		this->arr = new int[this->size];

		for (int i = 0; i < temp.size; i++)
		{
			this->arr[i] = temp[i];
		}

		for (int i = temp.size; i < this->size; i++)
		{
			this->arr[i] = obj.arr[i - temp.size];
		}

		// delete[] temp.arr;  // По идее temp мне больше не нужен, но при добавлении этого кода вылетает программа.
	
	return *this;
}

MyArray::operator int()
{
	int result = 0;
	
	for (int i = 0; i < this->size; i++)
	{
		result += this->arr[i];
	}
	return result;
}

MyArray::operator float()
{
	float result = 0;

	for (int i = 0; i < this->size; i++)
	{
		result += this->arr[i];
	}
	return result / this->size;
}

MyArray::operator char* ()
{
	int t_size = this->size + this->size;
	char* result = new char[t_size];
	char buf[200];

	if (result)
	{
		for (int i = 0; i < this->size; i++)
		{
			buf[i * 2] = char(this->arr[i]);
			buf[i * 2 + 1] = ' ';
		}
		

		buf[t_size - 1] = '\0';
		strcpy_s(result, t_size, buf);

	
	}

	return result;
}

MyArray::~MyArray()
{
	delete[] arr;
	arr = nullptr;
}

MyArray operator+(const MyArray& left_obj, const MyArray& right_obj)
{
	MyArray result;

	unsigned int t_size = left_obj.size + right_obj.size;

	if (result.arr)
	{
		delete[] result.arr;
	}

	result.arr = new int[t_size];
	result.size = t_size;

	for (int i = 0; i < left_obj.size; i++)
	{
		if (result.arr)
		{
			result.arr[i] = left_obj.arr[i];

		}
	}

	for (int i = left_obj.size; i < t_size; i++)
	{
		if (result.arr)
		{
			result.arr[i] = right_obj.arr[i - left_obj.size];
		}
	}

	return result;
}

MyArray operator+(const MyArray& obj, const int num)
{
	MyArray result;

	unsigned int t_size = obj.size + num;

	if (result.arr)
	{
		delete[] result.arr;
	}

	result.arr = new int[t_size];
	result.size = t_size;

	for (int i = 0; i < obj.size; i++)
	{
		if (result.arr)
		{
			result.arr[i] = obj.arr[i];

		}
	}

	for (int i = obj.size; i < t_size; i++)
	{
		if (result.arr)
		{
			result.arr[i] = 0;
		}
	}

	return result;
}

MyArray operator+(const int num, const MyArray& obj)
{
	MyArray result;

	unsigned int t_size = obj.size + num;

	if (result.arr)
	{
		delete[] result.arr;
	}

	result.arr = new int[t_size];
	result.size = t_size;

	for (int i = 0; i < num; i++)
	{
		if (result.arr)
		{
			result.arr[i] = 0;

		}
	}

	for (int i = num; i < t_size; i++)
	{
		if (result.arr)
		{
			result.arr[i] = obj.arr[i - num];
		}
	}

	return result;
}

ostream& operator<<(std::ostream& out, const MyArray& obj)
{
	for (int i = 0; i < obj.size; i++)
	{
		out << obj.arr[i] << " ";
	}

	out << endl;

	return out;
}

istream& operator>>(std::istream& in, MyArray& obj)
{
	cout << "\nВведите размер массива: ";
	in >> obj.size;

	obj.arr = new int[obj.size];

	cout << "\nВведите данные: ";
	
	for (int i = 0; i < obj.size; i++)
	{
		cout << "\nЗначение номер " << i + 1 << " :"; 
		in >> obj.arr[i];
	}
	
	cout << endl;
	return in;
}
