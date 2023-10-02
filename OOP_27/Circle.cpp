#include "Circle.h"
#include <conio.h>

Circle::Circle() : Coord()
{
	cout << "\nConstructor default Circle\n";
	this->radius = 1.0;
}

Circle::Circle(int x, int y, double radius) : Coord(x,y)
{
	cout << "\nConstructor default Circle\n";
	this->radius = radius;
}

Circle::Circle(Coord& obj, double radius) : Coord(obj)
{
	this->radius = radius;
}

void Circle::show() const
{
	//// / Доступ через открытые методы класса - 1
	//cout << "x: " << this->get_x() << endl; 
	//cout << "y: " << this->get_y() << endl; 
	
	//// Вызов метода базового класса - 2 
	//Coord::show();

	// Доступ к защищеным элементам(полям) базового класса - 3 (protected)
	cout << "x: " << this->x << endl;
	cout << "y: " << this->y << endl;
	cout << "radius:" << this->radius << endl;
}

Circle::~Circle()
{
	cout << "\nDestructor Circle\n";
	//_getch();
}
