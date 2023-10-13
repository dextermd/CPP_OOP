#include "Coord.h"
#include <iostream>
#include <cstring>
#include <conio.h>

using namespace std;

//#define DEBUG

// Инициализация статической переменной класса
int Coord::count = 0; // количество созданных объектов
const int Coord::N = 10;

////: x(0), y { 0 } - список инициализации конструткора
//Coord::Coord() : x(0), y { 0 }
//{
//#ifdef DEBUG
//	cout << "\nКонструктор по умолчанию";
//#endif // DEBUG
//	//N = 10;// error
//	/*this->x = 0;
//	this->y = 0;*/
//	this->count++;
//}

Coord::Coord(const int x, const int y) :  x(x), y(y)
{
#ifdef DEBUG
	cout << "\nКонструктор с параметрами Coord";
#endif // DEBUG
	//x = 100;
	/*this->x = x;
	this->y = y;*/
	this->count++;
	correct();
}

///*explicit*/ Coord::Coord(const int value)
//{
//#ifdef DEBUG
//	cout << "\nКонструктор преобразования";
//#endif // DEBUG
//	this->x = this->y = value;
//	this->count++;
//	correct();
//}

Coord::Coord(const char* str)
{
#ifdef DEBUG
	cout << "\nКонструктор преобразования";
#endif // DEBUG

	char* copy{nullptr};
	//copy ? new char[strlen(str) + 1] : nullptr;
	copy = new char[strlen(str) + 1];
	if (copy)
	{
		strcpy_s(copy, strlen(str) + 1, str);

		char* t1;
		char* t2;
		t1 = strtok_s(copy, ", :/_.\\;", &t2);

		this->x = atoi(t1);
		//t1 = strtok_s(nullptr, ", :/_.\\;", &t2);
		//this->y = atoi(t1);
		this->y = atoi(t2);

		correct();
		this->count++;

		delete[] copy;
		copy = nullptr;
	}
	else
	{
		cout << "Error mem.";
	}
	
	
}

Coord::Coord(const Coord& obj)// конструктор копирования
{
#ifdef DEBUG
	cout << "\nКонструктор копий\n";
#endif // DEBUG
	this->x = obj.x;
	this->y = obj.y;
	this->count++;
}


void Coord::set_x(int val)
{
	this->x = val;
	correct();
}

void Coord::set_y(int val)
{
	this->y = val;
	correct();
}

int Coord::get_x() const
{
	//this->x = 2;
	return x;
}

int Coord::get_y() const
{
	return y;
}

void Coord::reset_x_y(int x, int y)
{
	this->x = x;
	this->y = y;
	correct();
}

void Coord::init()
{
	cout << "\nEnter X : ";
	cin >> x;
	cout << "\nEnter Y : ";
	cin >> y;
	this->correct();
}

void Coord::show()const
{
	//this->x = 50;// mutable разрешает изменять поле по this в константном методе
	cout << "\n X : " << x;
	cout << "\n Y : " << y<< endl;
}

Coord Coord::add(const Coord& obj) const
{
	Coord res;

	res.x = this->x + obj.x;
	res.y = this->y + obj.y;
	res.correct();

	return res;
}

Coord Coord::operator+(const Coord& obj) const
{
	Coord res;

	res.x = this->x + obj.x;
	res.y = this->y + obj.y;
	res.correct();

	return res;
}

// Возврат по ссылке НЕЛЬЗЯ!!! делать для временного объекта
Coord Coord::operator+(const int& obj) const
{
	Coord r;// 
	r.x = this->x + obj;
	r.y = this->y + obj;
	return r;
}

// Возврат по ссылке возможен только если объект сущестует
// на момент вызова метода
Coord& Coord::operator+=(const Coord& obj)
{
	this->x += obj.x;
	this->y += obj.y;
	return *this;// возврат объекта через разименование this
}

bool Coord::operator==(const Coord& obj) const
{
	//return this->x == obj.x && this->y == obj.y ? true : false;
	return this->x == obj.x && this->y == obj.y;
}

// Перегрузка coord != coord
bool Coord::operator!=(const Coord& obj) const
{
	return this->x != obj.x || this->y != obj.y;

	return !(*this == obj);
}

// Перегрузка операции > для сравнения двух координат
bool Coord::operator > (const Coord& obj)const
{
	//логика...
	//return (this->x > obj.x && this->y > obj.y);

	return (this->x + this->y) > (obj.x + obj.y);

	//return (sqrt(pow(x, 2) + pow(y, 2))) > (sqrt(pow(obj.x, 2) + pow(obj.y, 2)));
}

// Перегрузка операции < для сравнения двух координат
bool Coord::operator<(const Coord& obj) const
{
	return  (this->x + this->y) < (obj.x + obj.y);;
}

Coord& Coord::operator++()
{
	this->x++;
	this->y++;
	return *this;
}


Coord Coord::operator++(int unused)
{
	Coord res = *this;
	this->x++;
	this->y++;
	return res;
}

Coord Coord::operator-() const
{
	Coord res;
	res.x = this->x * (-1);
	res.y = -this->y;
	return res;
}

void Coord::operator()(const int a, const int b)
{
	this->x = a;
	this->y = b;
}

//void Coord::operator()(const int a)
//{
//	this->x = a;
//	this->y = a;
//}
//
//void Coord::operator()()
//{
//	this->x = 0;
//	this->y = 0;
//}

//Coord::operator int()
//{
//	return this->x + this->y;
//}

Coord::operator MyString()
{
	char t[60], ty[32]; //"125;-36"

	/*_itoa_s(this->x, t, 10);
	strcat_s(t, "|");
	_itoa_s(this->y, ty, 10);
	strcat_s(t, ty);

	return MyString(t);*/

	_itoa_s(this->x, t, 10);//"125"
	_itoa_s(this->y, ty, 10);//"-36"
	
	return MyString(MyString("x = ") + t + " y =  " + ty);

}

Coord::~Coord()
{
	count--;
#ifdef DEBUG
	cout << "\nДеструктор Coord"<< count;
	_getch();
#endif // DEBUG

	
}

void Coord::correct()
{
	if (this->x < MIN)
		this->x = MIN;
	if (this->y < MIN)
		this->y = MIN;
	if (x > MAX)
		x = MAX;
	if (y > MAX)
		y = MAX;

}



//Дружественная функция - не является методом класса.
//Дружественная функция - есть доступ к закрытым полям класса через объект.
//Дружественная функция - нет доступа к this.

Coord operator*(const Coord& left, const Coord& right)
{
	Coord res;
	res.x = left.x * right.x;
	res.y = left.y * right.y;
	return res;
}

Coord operator+(const int left, const Coord& right)
{
	//Coord res;
	//res = right + left;
	//return res;

	//return Coord(right + left);

	Coord res;
	res.x = left + right.x;//есть доступ к закрытым полям класса через объект.
	res.y = left + right.y;//есть доступ к закрытым полям класса через объект.
	return res;
}

ostream& operator<<(ostream& out, const Coord& right)
{
	out << "{" << right.x << ";" << right.y << "}";
	return out;
}

// Перегрузка потока ввода (>>)
istream& operator >>(istream& in, Coord& b)
{
	cout << "\nx : ";
	in >> b.x;
	cout << "y : ";
	in >> b.y;
	return in;
}
