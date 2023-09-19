#include "Shape.h"
#include <iostream>

using namespace std;

Shape::Shape()
{
	this->x = 0;
	this->y = 0;
}

Shape::Shape(int x, int y)
{
	this->x = x;
	this->y = y;
}


void Shape::show() const
{
	cout << "\nx: " << x;
	cout << "\ny: " << y;
}

void Shape::save_to_binary_file(std::ofstream& fout) const
{
	fout.write((char*)&this->x, sizeof(this->x));
	fout.write((char*)&this->y, sizeof(this->y));
}

void Shape::read_from_binary_files(std::ifstream& fin)
{
	fin.read((char*)&this->x, sizeof(this->x));
	fin.read((char*)&this->y, sizeof(this->y));
}



