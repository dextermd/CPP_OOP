#include "Square.h"
#include <iostream>

using namespace std;

Square::Square() : Shape()
{
	this->side = 0;
}

Square::Square(int x, int y, int side) : Shape(x, y)
{
	this->side = side;
}

void Square::show() const
{
	cout << "\nSquare------------------";
	Shape::show();
	cout << "\nside: " << this->side << endl;
}

void Square::save_to_binary_file(std::ofstream& fout) const
{
	Shape::save_to_binary_file(fout);
	fout.write((char*)&this->side, sizeof(this->side));

}

void Square::read_from_binary_files(std::ifstream& fin)
{
	Shape::read_from_binary_files(fin);
	fin.read((char*)&this->side, sizeof(this->side));
}

Square::~Square()
{
}
