#include "Rectangle.h"
#include <iostream>
#include <conio.h>
#include "Coord.h"

using namespace std;


Rectangle::Rectangle()
{
	 //this - анонимный параметр
	 //хранит адрес обьекта, вывзвавшего метод:
	cout << "\nАдрес обьекта, вызвавшего метода " << this << endl;
	this->width = 0;
	this->height = 0;
	symbol = '*';
	strcpy_s(color_name, "no color");
	// Поле - динамическая строка
	this->name = new char[strlen("no name") + 1];
	if (this->name)
	{
		strcpy_s(this->name, strlen("no name") + 1, "no name");
	}
}

Rectangle::Rectangle(const int width, const int height, const char symbol, const char* color_name, const char* name)
{
	cout << "\nАдрес обьекта, вызвавшего метода " << this << endl;
	this->width = width;
	this->height = height;
	this->symbol = symbol;
	strcpy_s(this->color_name, color_name);
	
	// Поле - динамическая строка
	this->name = new char[strlen(name) + 1];
	if (this->name)
	{
		strcpy_s(this->name, strlen(name) + 1, name);
	}
}

Rectangle::Rectangle(const char* name, const char* cn)
{
	strcpy_s(this->color_name, cn);
	this->width = 10;
	this->height = 10;
	this->symbol = '#';

	// Поле - динамическая строка
	this->name = new char[strlen(name) + 1];
	if (this->name)
	{
		strcpy_s(this->name, strlen(name) + 1, name);
	}

}

// Конструктор копирования  обязательно надо делать если в классе есть переменные - адресса динамические ( стандартный конструктор коми не подойдет)
Rectangle::Rectangle(const Rectangle& obj)
{
	strcpy_s(this->color_name, obj.color_name);
	this->width = obj.width;
	this->height = obj.height;
	this->symbol = obj.symbol;

	// Поле с динамическим выделение памяти
	// Глубокое копирование
	this->name = new char[strlen(obj.name) + 1];
	if (this->name)
	{
		strcpy_s(this->name, strlen(obj.name) + 1, obj.name);
	}
}

void Rectangle::set_height(const int& h)
{
	height = h;
}

int Rectangle::get_height() const // Константный метод он не разрешает менять значения через this
{
	return height;
}

void Rectangle::set_symbol(const char s) 
{
	symbol = s;
}

int Rectangle::get_symbol() const // Константный метод он не разрешает менять значения через this
{
	return symbol;
}

void Rectangle::set_color_name(const char* cn)
{
	strcpy_s(color_name, cn);
}

const char* Rectangle::get_color_name() const // Константный метод он не разрешает менять значения через this
{
	return color_name;
}

void Rectangle::set_name(const char* name)
{
	if (this->name)
		delete[] this->name;

	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

void Rectangle::show() const // Константный метод он не разрешает менять значения через this
{
	cout << "\nШирина		: " << width;
	cout << "\nВысота		: " << height;
	cout << "\nСимвол		: " << symbol;
	cout << "\nЦвет		: " << color_name;
	cout << "\nНаименование	: " << name;
	cout << "\nПлощадь		: " << area();
	cout << endl;
}

void Rectangle::init()
{
	cout << "\nНаименование   : ";
	char buf[250];
	cin.getline(buf, sizeof(buf));

	if (this->name)
		delete[] this->name;

	this->name = new char[strlen(buf) + 1];
	strcpy_s(this->name, strlen(buf) + 1, buf);

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

int Rectangle::area() const // Константный метод он не разрешает менять значения через this
{
	return width * height;
}

int Rectangle::perimetr() const // Константный метод он не разрешает менять значения через this
{
	return 2 * (width + height);
}

// Статический метод
void Rectangle::show(const Rectangle* arr, int size)
{
	// В статическом методе нет доступа к this !!!!
	for (int i = 0; i < size; i++)
	{
		arr[i].show();
	}
}

Rectangle& Rectangle::operator=(const Rectangle& obj)
{
	if (this == &obj)
		return *this;

	this->width = obj.width;
	this->height = obj.height;
	this->symbol = obj.symbol;
	strcpy_s(this->color_name, obj.color_name);

	if (strlen(this->name) != strlen(obj.name))
	{
		delete[] this->name;
		this->name = new char[strlen(obj.name) + 1];
	}

	strcpy_s(this->name, strlen(obj.name) + 1, obj.name);

	return *this;
}

Rectangle::operator Coord()
{
	return Coord(this->width, this->height);
}

Rectangle::~Rectangle()
{
	delete[] this->name;
	this->name = nullptr;

	cout << "\nДеструктор";
	//_getch();
}

void set_symbol(Rectangle& obj, const char s)
{
	obj.symbol = s;
}
