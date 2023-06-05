#include "Rectangle.h"
#include <iostream>
#include <conio.h>

using namespace std;


//Rectangle::Rectangle()
//{
//	// this - анонимный параметр
//	// хранит адрес обьекта, вывзвавшего метод:
//	cout << "\nАдрес обьекта, вызвавшего метода " << this << endl;
//	this->width = 0;
//	this->height = 0;
//	symbol = '*';
//	strcpy_s(color_name, "no color");
//}

Rectangle::Rectangle(const int width, const int height, const char symbol, const char* color_name)
{
	cout << "\nАдрес обьекта, вызвавшего метода " << this << endl;
	this->width = width;
	this->height = height;
	this->symbol = symbol;
	strcpy_s(this->color_name, color_name);
}

Rectangle::Rectangle(const char* cn)
{
	strcpy_s(this->color_name, cn);
	this->width = 10;
	this->height = 10;
	this->symbol = '#';
}

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

void Rectangle::show()
{
	cout << "\nШирина : " << width;
	cout << "\nВысота : " << height;
	cout << "\nСимвол : " << symbol;
	cout << "\nЦвет   : " << color_name;
	cout << "\nПлощадь: " << area();
	cout << endl;
}

void Rectangle::init()
{
	cout << "\nШирина : ";
	cin >> width;
	cout << "\nВысота : ";
	cin >> height;
	cout << "\nСимвол : ";
	cin >> symbol;
	cout << "\nЦвет   : ";
	cin.get();
	cin.getline(color_name, sizeof(color_name));

}

int Rectangle::area()
{
	return width * height;
}

int Rectangle::perimetr()
{
	return 2 * (width + height);
}

void Rectangle::show(Rectangle* arr, int size)
{
	// В статическом методе нет доступа к this !!!!
	for (int i = 0; i < size; i++)
	{
		arr[i].show();
	}
}

Rectangle::~Rectangle()
{
	cout << "\nДеструктор";
	//_getch();
}
