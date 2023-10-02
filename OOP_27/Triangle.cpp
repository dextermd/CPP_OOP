#include "Triangle.h"
#include <iostream>

using namespace std;

Triangle::Triangle() : Shape()
{
	this->base = 1;
	this->height = 1;
}

Triangle::Triangle(int x, int y, int base, int height) : Shape(x, y)
{
	this->base = base;
	this->height = height;
}

double Triangle::area() const
{
	return 0.5 * this->base * this->height;

}

int Triangle::perimetr() const
{
	return 2 * base + height;
}

void Triangle::show() const
{
	Shape::show();
	cout << "\nOsnovanie: " << base;
	cout << "\nVisota:	" << height;
}

Triangle::~Triangle()
{
}
