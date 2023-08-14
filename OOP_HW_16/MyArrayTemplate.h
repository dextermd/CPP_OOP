#pragma once

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <Windows.h>

using namespace std;

template<class Type>
class MyArrayTemplate
{

	Type* arr;
	unsigned int size;

public:

	MyArrayTemplate();
	MyArrayTemplate(const Type num, const unsigned int size);
	MyArrayTemplate(const Type* arr, const unsigned int size);
	MyArrayTemplate(const MyArrayTemplate& obj);
	MyArrayTemplate(MyArrayTemplate&& obj);

	// Методы
	const void show() const;
	void init();



	const double avarage_array() const;

	MyArrayTemplate add(const MyArrayTemplate& obj) const;

	MyArrayTemplate& operator=(const MyArrayTemplate& obj);

	MyArrayTemplate& operator=(MyArrayTemplate&& obj);

	friend MyArrayTemplate operator+(const MyArrayTemplate& left_obj, const MyArrayTemplate& right_obj);

	friend MyArrayTemplate operator+(const MyArrayTemplate& obj, const Type num);

	friend MyArrayTemplate operator+(const Type num, const MyArrayTemplate& obj);

	MyArrayTemplate& operator+=(const Type num);

	MyArrayTemplate& operator+=(const MyArrayTemplate& obj);


	~MyArrayTemplate();
};

template<class Type>
MyArrayTemplate<Type>::MyArrayTemplate()
{
	size = 5;
	arr = new Type[size];
	if (arr)
	{
		for (int i = 0; i < size; i++)
		{
			if constexpr (std::is_same_v<Type, int>) {
				arr[i] = 0;
			}

		}
	}
}

template<class Type>
MyArrayTemplate<Type>::MyArrayTemplate(const Type num, const unsigned int size)
{
	this->size = size;
	this->arr = new Type[this->size];
	if (this->arr)
	{
		for (int i = 0; i < this->size; i++)
		{
			this->arr[i] = num;
		}

	}
}

template<class Type>
MyArrayTemplate<Type>::MyArrayTemplate(const Type* arr, const unsigned int size)
{
	this->size = size;
	this->arr = new Type[this->size];
	if (this->arr)
	{
		for (int i = 0; i < this->size; i++)
		{
			this->arr[i] = arr[i];
		}

	}
}


template<class Type>
MyArrayTemplate<Type>::MyArrayTemplate(const MyArrayTemplate& obj) // Конструктор копии
{
	this->size = obj.size;
	this->arr = new Type[this->size];
	if (this->arr)
	{
		for (int i = 0; i < this->size; i++)
		{
			this->arr[i] = obj.arr[i];
		}
	}
}

template<class Type>
MyArrayTemplate<Type>::MyArrayTemplate(MyArrayTemplate&& obj) // Конструктор перемещения
{
	this->size = obj.size;
	this->arr = obj.arr;

	obj.size = 0;
	obj.arr = nullptr;
}

template<class Type>
const void MyArrayTemplate<Type>::show() const
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
}

template<class Type>
void MyArrayTemplate<Type>::init()
{
	cout << "\nВведите размер массива: ";
	cin >> size;
	cout << "\nПроинициализируйте массив: \n";
	cin.get();
	if (arr)
		delete[] arr;
	arr = new Type[size];
	for (int i = 0; i < size; i++)
	{
		cout << "Введите значение №" << i + 1 << " ";
		cin >> arr[i];
	}

}

template<class Type>
const double MyArrayTemplate<Type>::avarage_array() const
{
	double result = 0.0;

	for (int i = 0; i < size; i++)
	{
		result += arr[i];
	}

	return result / (double)size;
}

template<class Type>
MyArrayTemplate<Type> MyArrayTemplate<Type>::add(const MyArrayTemplate& obj) const
{
	MyArrayTemplate result;
	unsigned int t_size = this->size + obj.size;

	if (result.arr)
	{
		delete[] result.arr;
	}

	result.arr = new Type[t_size];
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

template<class Type>
MyArrayTemplate<Type>& MyArrayTemplate<Type>::operator=(const MyArrayTemplate& obj) // operator= без перемещения с глубоким копированием
{
	if (this == &obj)
		return *this;


	if (this->size != obj.size)
	{
		this->size = obj.size;
		delete[] this->arr;
		this->arr = new Type[this->size];
	}

	for (int i = 0; i < this->size; i++)
	{
		this->arr[i] = obj.arr[i];
	}

	return *this;
}

template<class Type>
MyArrayTemplate<Type>& MyArrayTemplate<Type>::operator=(MyArrayTemplate&& obj)  // operator= с перемещением без глубокого копирования
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

template<class Type>
MyArrayTemplate<Type> operator+(const MyArrayTemplate<Type>& left_obj, const MyArrayTemplate<Type>& right_obj)
{
	MyArrayTemplate result;

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

template<class Type>
MyArrayTemplate<Type> operator+(const MyArrayTemplate<Type>& obj, const Type num)
{
	MyArrayTemplate result;

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

template<class Type>
MyArrayTemplate<Type> operator+(const Type num, const MyArrayTemplate<Type>& obj)
{
	MyArrayTemplate result;

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

template<class Type>
MyArrayTemplate<Type>& MyArrayTemplate<Type>::operator+=(const Type num)
{
	if (this->size != num && num > 0)
	{
		MyArrayTemplate temp;

		if (temp.arr)
		{
			delete[] temp.arr;
			temp.size = this->size;
			temp.arr = new Type[temp.size];
		}

		for (int i = 0; i < temp.size; i++)
		{
			temp.arr[i] = this->arr[i];
		}

		this->size += num;
		delete[] this->arr;
		this->arr = new Type[this->size];

		for (int i = 0; i < temp.size; i++)
		{
			this->arr[i] = temp.arr[i];
		}


		for (int i = temp.size; i < this->size; i++)
		{
			this->arr[i] = 0;
		}

	}

	return *this;
}

template<class Type>
MyArrayTemplate<Type>& MyArrayTemplate<Type>::operator+=(const MyArrayTemplate& obj)
{

	MyArrayTemplate temp;

	if (temp.arr)
	{
		delete[] temp.arr;
		temp.size = this->size;
		temp.arr = new Type[temp.size];
	}

	for (int i = 0; i < temp.size; i++)
	{
		temp.arr[i] = this->arr[i];
	}

	this->size += obj.size;
	delete[] this->arr;
	this->arr = new Type[this->size];

	for (int i = 0; i < temp.size; i++)
	{
		this->arr[i] = temp.arr[i];
	}

	for (int i = temp.size; i < this->size; i++)
	{
		this->arr[i] = obj.arr[i - temp.size];
	}


	return *this;
}

template<class Type>
MyArrayTemplate<Type>::~MyArrayTemplate()
{
	delete[] arr;
	arr = nullptr;
}



