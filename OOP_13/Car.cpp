#include "Car.h"
#include "Truck.h"
#include <iostream>

using namespace std;

Car::Car()
{
	this->passengers_count = 0;
	this->speed = 0;
}

Car::Car(int passager_count, int speed)
{
	this->passengers_count = passager_count;
	this->speed = speed;
}

void Car::show()
{
	cout << "\nКоличество пассажиров:  " << this->passengers_count;
	cout << "\nСкорость:		" << this->speed;
	cout << endl;
}

Car::~Car()
{
}

int speed_compare(const Car& car, const Truck& t)
{
	return car.speed - t.speed;
}
