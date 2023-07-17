#pragma once
// #include "Truck.h"

class Truck;

class Car
{
	int passengers_count;
	int speed;

public:
	Car();

	Car(int passager_count, int speed);

	void show();

	friend int speed_compare(const Car& car, const Truck& t);

	~Car();

};

