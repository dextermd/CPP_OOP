#include "Rectangle.h"
#include <iostream>

using namespace std;


void Rectangle::set_height(const int& h)
{
	height = h;
}

int Rectangle::get_height()
{
	return height;
}

void Rectangle::set_symbol(const char s)
{
	symbol = s;
}

int Rectangle::get_symbol()
{
	return symbol;
}

void Rectangle::set_color_name(const char* cn)
{
	strcpy_s(color_name, cn);
}

const char* Rectangle::get_color_name()
{
	return color_name;
}