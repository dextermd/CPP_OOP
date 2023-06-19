#include "Coord.h"
#include <iostream>
#include <conio.h>

using namespace std;

//#define DEBUG
int Coord::count_obj = 0; // Инициализация статической переменной класса

Coord::Coord() : x(0), y{ 0 }
{

#ifdef DEBUG
	cout << "\nКонструктор по умолчанию";
#endif

	/*x = 0;
	y = 0;*/
	this->count_obj++;
}

Coord::Coord(const int x, const int y) : x(x), y(y)
{
#ifdef DEBUG
	cout << "\nКонструктор с параметрами";
#endif

	/*this->x = x;
	this->y = y;*/
	correct();
	this->count_obj++;
}

Coord::Coord(const int value)
{
#ifdef DEBUG
	cout << "\nКонструктор переобразования";
#endif
	this-> x = this-> y = value;
	this->count_obj++;
}

Coord::Coord(const char* str)
{
	char* copy;
	copy = new char[strlen(str) + 1];
	strcpy_s(copy, strlen(str) + 1, str);
	char* t1;
	char* t2;

	t1 = strtok_s(copy, ":, ./_-\\.", &t2);
	this->x = atoi(t1);

	t1 = strtok_s(nullptr, ":, ./_-\\.", &t2);
	this->y = atoi(t1);

	correct();
	this->count_obj++;

	delete[] copy;
	copy = nullptr;
	//t1 = strtok_s(nullptr, ":, ./_-\\.", &t2);
	//this->y = atoi(t1);
}

Coord::Coord(const Coord& obj)
{
#ifdef DEBUG
	cout << "\nКонструктор копий " << endl;
#endif 
	this->x = obj.x;
	this->y = obj.y;
	this->count_obj++;
}


void Coord::correct()
{
	if (this->x < MIN)
		this->x = MIN;
	if (this->y < MIN)
		this->y = MIN;

	if (this->x > MAX)
		this->x = MAX;
	if (this->y > MAX)
		this->y = MAX;

}


void Coord::show() const
{
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
}

void Coord::show(const Coord* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i].show();
	}
}

int Coord::get_x() const
{
	return x;
}

void Coord::set_x(const int& x)
{
	this->x = x;
}


int Coord::get_y() const
{
	return y;
}

void Coord::set_y(const int& y)
{
	this->y = y;
}

void Coord::reset(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Coord::init()
{
	cout << "\nВведите x: ";
	cin >> x;
	cout << "\nВведите y: ";
	cin >> y;
}

Coord Coord::add(const Coord& obj) const
{
	Coord res;

	res.x = this->x + obj.x;
	res.y = this->y + obj.y;
	res.correct();

	return res;
}




Coord::~Coord()
{
	this->count_obj--;
#ifdef DEBUG
	cout << "\nДеструктор " << count_obj << endl;
#endif
}




