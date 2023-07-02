#pragma once
class MyArray
{

	int* arr;
	unsigned int size;

public:

	MyArray();
	MyArray(const int num, const unsigned int size);
	MyArray(const int* arr, const unsigned int size);
	MyArray(const unsigned int size, const int min, const int max);
	MyArray(const MyArray& obj);

	// Методы
	const void show() const;
	void init();

	const unsigned int get_size() const { return size; };

	const double avarage_array() const;

	MyArray add(const MyArray& obj) const;


	~MyArray();
};

