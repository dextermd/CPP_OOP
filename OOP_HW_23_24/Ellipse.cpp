#include "Ellipse.h"
#include <iostream>

using namespace std;

Ellipse::Ellipse() : Shape()
{
	this->width = 0;
	this->height = 0;
}

Ellipse::Ellipse(int x, int y, int width, int height) : Shape(x, y)
{
	this->width = width;
	this->height = height;

}

void Ellipse::show() const
{
	cout << "\nEllipse------------------";
	Shape::show();
	cout << "\nwidth: " << this->width;
	cout << "\nheight: " << this->height << endl;
}

void Ellipse::save_to_binary_file(std::ofstream& fout) const
{
	Shape::save_to_binary_file(fout);
	fout.write((char*)&this->width, sizeof(this->width));
	fout.write((char*)&this->height, sizeof(this->height));

}

void Ellipse::read_from_binary_files(std::ifstream& fin)
{
	Shape::read_from_binary_files(fin);
	fin.read((char*)&this->width, sizeof(this->width));
	fin.read((char*)&this->height, sizeof(this->height));
}

Ellipse::~Ellipse()
{
}
