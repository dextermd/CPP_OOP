#pragma once
#include "Shape.h"

class Triangle : public Shape
{
	int base;
	int height;

public:
	Triangle();
	Triangle(int x, int y, int base, int height);

	// В производном классе ДОЛЖНЫ быть переопределены
	// все чисто-виртуальные методы базового класса
	double area()const override;
	int perimetr()const override;
	void show()const override;

	~Triangle();
};

