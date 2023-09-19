#include "Circle.h"
#include <iostream>

using namespace std;

Circle::Circle() : Shape()
{
	this->radius = 0;
}

Circle::Circle(int x, int y, int radius) : Shape(x, y)
{
	this->radius = radius;

}

void Circle::show() const
{
	cout << "\nCircle------------------";
	Shape::show();
	cout << "\nradius: " << this->radius << endl;

}

void Circle::save_to_binary_file(std::ofstream& fout) const
{
	Shape::save_to_binary_file(fout);
	fout.write((char*)&this->radius, sizeof(this->radius));
}

void Circle::read_from_binary_files(std::ifstream& fin)
{
	Shape::read_from_binary_files(fin);
	fin.read((char*)&this->radius, sizeof(this->radius));
}

Circle::~Circle()
{
}
