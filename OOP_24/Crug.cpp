#include "Crug.h"
#include <iostream>

using namespace std;

Crug::Crug() : Shape()
{
	this->radius = 1;
}

Crug::Crug(int x, int y, double radius) : Shape(x,y)
{
	this->radius = radius;
}

void Crug::show() const
{
	Shape::show();
	cout << "\nRadius: " << radius;
}

int Crug::perimetr() const
{
	return 0;
}

double Crug::area() const
{
	return 3.14 * radius * radius;
}

Crug::~Crug()
{
}
