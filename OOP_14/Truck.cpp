#include "Truck.h"
#include <iostream>

using namespace std;

Truck::Truck()
{
	this->cargo_capacity = 0;
	this->speed = 0;
}

Truck::Truck(int cargo_capacity, int speed)
{
	this->cargo_capacity = cargo_capacity;
	this->speed = speed;
}

void Truck::show() const
{
	cout << "\nГрузоподьемность: " << this->cargo_capacity;
	cout << "\nСкорость:	  " << this->speed;
	cout << endl;
}

Truck::~Truck()
{
}
