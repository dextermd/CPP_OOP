#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <assert.h>   
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

double MyArray::avarage_array() const
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

void MyArray::save_to_binary_file(FILE* f)
{
	fwrite(&this->size, sizeof(this->size), 1, f);
	fwrite(&this->arr, sizeof(int) * this->size, 1, f);
}

void MyArray::read_from_binary_file(FILE* f)
{
	delete[] arr;
	fread(&size, sizeof(size), 1, f);
	arr = new int[size];

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


void MyArray::set_size(unsigned int size)
{
	delete[]arr;
	this->size = size;
	if (this->size)
		this->arr = new int[this->size] { 0 };
	else this->arr = nullptr;
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

void MyArray::save_to_file_plus(std::ostream& fout) const
{
	fout << *this << " ";
}

void MyArray::save_to_binary_file_plus(std::ofstream& fout) const
{
	fout.write((char*)&this->size, sizeof(this->size));
	fout.write((char*)this->arr, sizeof(this->arr) * this->size);
}

void MyArray::read_from_binary_file_plus(std::ifstream& fin)
{
	delete[] this->arr;
	fin.read((char*)&this->size, sizeof(this->size));
	this->arr = new int[this->size];
	fin.read((char*)this->arr, sizeof(this->arr) * this->size);
}

std::ostream& operator<<(std::ofstream& out, const MyArray& obj)
{
	out.write((char*)&obj.size, sizeof(obj.size));
	out.write((char*)obj.arr, sizeof(obj.arr) * obj.size);
	return out;
}

std::istream& operator>>(std::ifstream& in, MyArray& obj)
{
	delete[] obj.arr;
	in.read((char*)&obj.size, sizeof(obj.size));
	obj.arr = new int[obj.size];
	in.read((char*)obj.arr, sizeof(obj.arr) * obj.size);
	return in;
}




//
//#include <iostream>
//#include <conio.h>   
//#include <assert.h>   
//#include "MyArray.h"
//
//using namespace std;
//
////---------------------------------------------
////MyArray::MyArray()
////{
////	size = 5;
////	arr = new int[size];
////	
////	for (int i = 0; i < size; i++)
////		arr[i] = 0;
////	
////	/*arr = nullptr;
////	size = 0;*/
////}
//
////---------------------------------------------
//MyArray::MyArray(unsigned int size, int val)
//{
//	this->size = size;
//	arr = new int[this->size];
//	for (int i = 0; i < this->size; i++)
//		arr[i] = val;
//}
//
////---------------------------------------------
//MyArray::MyArray(const int *pn, unsigned int size)
//{
//	this->size = size;
//	arr = new int[this->size];
//	
//	for (int i = 0; i < this->size; i++)
//		arr[i] = pn[i];
//}
//
////---------------------------------------------
//MyArray::MyArray(unsigned int size, int a, int b)
//{
//	if (a > b)
//	{
//		int t = a;
//		a = b;
//		b = t;
//	}
//	this->size = size;
//	arr = new int[this->size];
//	for (int i = 0; i < this->size; i++)
//		arr[i] = rand() % (b - a + 1) + a;
//}
//
////---------------------------------------------
//MyArray::MyArray(const MyArray & a)
//{
//	//cout << "\nКонструктор копирования\n";
//	size = a.size;
//	arr = new int[size];
//	for (int i = 0; i < size; i++)
//		arr[i] = a.arr[i];
//}
//
////---------------------------------------------
//MyArray::~MyArray()
//{
//	delete[] arr;
//	arr = nullptr;
//	/*cout << "\nДеструктор\n";
//	_getch();*/
//}
//
////---------------------------------------------
//double MyArray::average() const
//{
//	double sum = 0;
//	int i;
//	
//	for (i = 0; i < this->size; i++)
//		sum += arr[i];
//	
//	if (i > 0)  return sum / i;
//	else
//	{
//		cout << "\nМассив пуст\n";
//		return 0;
//	}
//}
//
////---------------------------------------------
//void MyArray::show()const
//{
//	for (int i = 0; i < size; i++)
//		cout << arr[i] << " ";
//	cout << endl;
//}
//
//
////---------------------------------------------
//void MyArray::init()
//{
//	cout << "\nВведите количество элементов массива: ";
//	cin >> size;
//	delete[]arr;
//	arr = new int[size];
//	cout << "\nВведите значения массива: \n";
//	for (int i = 0; i < size; i++) {
//		cout << i + 1 << " : ";
//		cin >> arr[i];
//	}
//}
//
////---------------------------------------------
//MyArray MyArray::add(const MyArray& b)const
//{
//	MyArray t;// По умолчанию выделение памяти под 5 элементов     X100
//	if (t.arr)
//		delete[]t.arr;// освобождение старой памяти
//	t.size = this->size + b.size;
//	t.arr = new int[t.size];   // X200
//	int k = 0;
//	for (int i = 0; i < this->size; i++)
//		t.arr[k++] = this->arr[i];
//	for (int i = 0; i < b.size; i++)
//		t.arr[k++] = b.arr[i];
//	return t;
//}
//
//
//
////-----------------------------------------------
//
//MyArray& MyArray::operator=(const MyArray& a)
//{
//	//cout << "\n Оператор = \n";
//	if (this == &a)
//		return *this;
//	delete[] arr;
//	size = a.size;
//	arr = new int[size];
//	for (int i = 0; i < size; i++)
//		arr[i] = a.arr[i];
//	return *this;
//}
//
////----------------------------------------------------
//ostream& operator<<(ostream& os, const MyArray& a)
//{
//	int i;
//	for (i = 0; i < a.size; i++)
//	{
//		os << a.arr[i] << " ";
//	}
//	return os;
//}
//
////----------------------------------------------------
//istream& operator>>(istream& is, MyArray& a)
//{
//	int i;
//	for (i = 0; i < a.size; i++)
//	{
//		is >> a.arr[i];
//	}
//
//	return is;
//}
//
//std::ostream& operator<<(std::ofstream& out, const MyArray& obj)
//{
//	out.write((char*)&obj.size, sizeof(obj.size));
//	out.write((char*)obj.arr, sizeof(obj.arr) * obj.size);
//	return out;
//}
//
//std::istream& operator>>(std::ifstream& in, MyArray& obj)
//{
//	delete[] obj.arr;
//	in.read((char*)&obj.size, sizeof(obj.size));
//	obj.arr = new int[obj.size];
//	in.read((char*)obj.arr, sizeof(obj.arr) * obj.size);
//	return in;
//}
//
//
//int& MyArray::operator[](int i)
//{
//	assert(i >= 0 && i < size);
//	return arr[i];
//}
////---------------------------------------------
//
//const int& MyArray::operator[](int i) const
//{
//
//	/*if (i < 0 || i >= size)
//	{
//	cout << "Неверный индекс : " << i << endl;
//	exit(1);
//	}*/
//
//	assert(i >= 0 && i < size);
//	return arr[i];
//}
//
//
//void MyArray::set_size(unsigned int size)
//{
//	delete[]arr;
//	this->size = size;
//	if (this->size)
//		this->arr = new int[this->size]{ 0 };
//	else this->arr = nullptr;
//}
//
//
//void MyArray::save_to_binary_file(FILE* f)
//{
//	fwrite(&size, sizeof(size), 1, f);// запись количества элементов массива
//
//	// Запись значений массива - Вариант 1
//	/*for(int i = 0; i < size; i++)
//		fwrite(&arr[i], sizeof(arr[i]), 1, f);*/
//
//		// Запись значений массива - Вариант 2
//	fwrite(arr, sizeof(int) * size, 1, f);
//
//	// Запись значений массива - Вариант 3
//	//fwrite(arr, sizeof(int), size, f);
//}
//
//void MyArray::read_from_binary_file(FILE* f)
//{
//	delete[]arr;
//	fread(&size, sizeof(size), 1, f);
//	arr = new int[size];
//
//	// Чтение значений массива - Вариант 1
//	/*for (int i = 0; i < size; i++)
//		fread(&arr[i], sizeof(arr[i]), 1, f);*/
//
//		// Чтение значений массива - Вариант 2
//	//fread(arr, sizeof(int) * size, 1, f);
//	fread_s(arr, sizeof(int) * size, sizeof(int), size, f);
//
//
//	// Чтение значений массива - Вариант 3
//	//fread(arr, sizeof(arr[0]), size, f);
//
//}
//
//void MyArray::save_to_file_plus(std::ostream& fout) const
//{
//	fout << *this << " ";
//}
//
//void MyArray::save_to_binary_file_plus(std::ofstream& fout) const
//{
//	fout.write((char*)&this->size, sizeof(this->size));
//	fout.write((char*)this->arr, sizeof(this->arr) * this->size);
//}
//
//void MyArray::read_from_binary_file_plus(std::ifstream& fin)
//{
//	delete[] this->arr;
//	fin.read((char*)&this->size, sizeof(this->size));
//	this->arr = new int[this->size];
//	fin.read((char*)this->arr, sizeof(this->arr) * this->size);
//}
//
//
