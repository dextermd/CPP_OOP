#pragma once
#include "Shape.h"
class Crug : public Shape
{
	double radius;

public:
	Crug();
	Crug(int x, int y, double radius);

	void show()const override;
	int perimetr()const override;
	double area()const override;

	~Crug();
};

