#pragma once
#include <iostream>
using namespace std;

class MyArray
{

private:
	unsigned int size;               
	int * arr;                       

public:
	//MyArray();                      
	MyArray() : MyArray(5) {} // Делегирующий конструктор

	MyArray(unsigned int size, int val = 0 );

	MyArray(const int * pn, unsigned int n = 1);

	MyArray(unsigned int n,  int a, int b);

	MyArray(const MyArray & a);         // Конструктор копий
	                  
	unsigned int get_size() const { return size; }
	int* get_ptr()const { return this->arr; } //***
	
	double average() const;                 
											
	void show() const;
	void init();

	MyArray add(const MyArray& b) const;

	~MyArray();

	//***from hw
	MyArray& operator = (const MyArray& a);
	friend ostream& operator<<(ostream& os, const MyArray& a);
	friend istream& operator>>(istream& is, MyArray& a);

	int& operator[](int i);
	const int& operator[](int i) const;

	void set_size(unsigned int size);

	void save_to_binary_file(FILE* f);
	void read_from_binary_file(FILE* f);

};



