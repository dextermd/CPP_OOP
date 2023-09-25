#include "Cylinder.h"

Cylinder::Cylinder() : Circle()
{
	this->height = 1;
}

Cylinder::Cylinder(int x, int y, double radius, int height) : Circle(x, y, radius)
{
	if (height <= 0)
	{
		throw exception("Negative height value");
	}
	this->height = height;
}

void Cylinder::show() const
{
	cout << "\nx = " << this->x;
	cout << "\ny = " << this->y;
	cout << "\nradius = " << this->radius << endl;
	cout << "\height = " << this->height << endl;
}

Cylinder::~Cylinder()
{
}
