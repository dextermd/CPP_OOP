#pragma once
#include "Shape.h"

class Ellipse : virtual public Shape
{
private:
	int width;
	int height;

public:
	Ellipse();
	Ellipse(int x, int y, int width, int height);

	void show() const override;
	void save_to_binary_file(std::ofstream& fout) const override;
	void read_from_binary_files(std::ifstream& fin) override;

	~Ellipse();
};
