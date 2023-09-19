#pragma once
#include "Shape.h"

class Circle : virtual public Shape
{
private:
	int radius;


public:
	Circle();
	Circle(int x, int y, int radius);

	void show() const override;
	void save_to_binary_file(std::ofstream& fout) const override;
	void read_from_binary_files(std::ifstream& fin) override;

	~Circle();
};
