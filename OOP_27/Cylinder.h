#pragma once
#include "Circle.h"
class Cylinder : public Circle
{

protected:
	int height;

public:
	Cylinder();
	Cylinder(int x, int y, double radius, int height);

	void show() const override;

	~Cylinder();
	
};

