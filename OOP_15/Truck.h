#pragma once
#include "Car.h"

class Truck
{
	int cargo_capacity;
	int speed;

public:
	Truck();

	Truck(int cargo_capacity, int speed);

	void show() const;

	friend int speed_compare(const Car& car, const Truck& t);

	~Truck();
};

