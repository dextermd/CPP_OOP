#pragma once

#include "Coord.h"

// По умолчанию класс pivate
// private inheritance - по умолчанию has-a
// public is-a
class Circle : public Coord
{
protected:
	double radius;

public:
	Circle();
	Circle(int x, int y, double radius);
	Circle(Coord& obj, double radius);

	// override - переопределение метода базового класса
	void show() const;

	~Circle();

};