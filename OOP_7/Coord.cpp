#include "Coord.h"
#include <iostream>
#include <conio.h>

using namespace std;




Coord::Coord()
{
	x = 0;
	y = 0;
}

Coord::Coord(const int x, const int y)
{
	this->x = x;
	this->y = y;

}

Coord::Coord(const char* str)
{
	char* copy;
	copy = new char[strlen(str) + 1];
	strcpy_s(copy, strlen(str) + 1, str);
	char* t1;
	char* t2;

	t1 = strtok_s(copy, ":, ./_-\\.", &t2);
	this->x = atoi(t1);
	this->y = atoi(t2);

	correct();

	delete[] copy;
	copy = nullptr;
	//t1 = strtok_s(nullptr, ":, ./_-\\.", &t2);
	//this->y = atoi(t1);
}


void Coord::correct()
{
	if (this->x < MIN)
		this->x = MIN;
	if (this->y < MIN)
		this->y = MIN;

	if (this->x > MAX)
		this->x = MAX;
	if (this->y > MAX)
		this->y = MAX;

}




void Coord::show() const
{
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
}

void Coord::show(const Coord* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i].show();
	}
}

int Coord::get_x() const
{
	return x;
}

void Coord::set_x(const int& x)
{
	this->x = x;
}


int Coord::get_y() const
{
	return y;
}

void Coord::set_y(const int& y)
{
	this->y = y;
}

void Coord::reset(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Coord::init()
{
	cout << "\nВведите x: ";
	cin >> x;
	cout << "\nВведите y: ";
	cin >> y;
}

Coord Coord::add(const Coord& obj) const
{
	Coord res;
	res.x = this->x + obj.x;
	res.y = this->y + obj.y;
	res.correct();
	return res;
}




Coord::~Coord()
{
}




