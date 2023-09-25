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

//double Shape::area() const
//{
//	cout << "\nPlosiadi: ";
//	return 0.0;
//}

void Shape::show() const
{
	cout << "\nX: " << x << " Y: " << y;
}

//Shape::~Shape()
//{
//}
