#pragma once
#include "Shape.h"

class Square : virtual public Shape
{
private:
	int side;

public:
	Square();
	Square(int x, int y, int side);

	void show() const override;
	void save_to_binary_file(std::ofstream& fout) const override;
	void read_from_binary_files(std::ifstream& fin) override;

	~Square();
};

