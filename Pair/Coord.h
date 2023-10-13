#pragma once
#include <iostream>
using namespace std;

#include "MyString.h"

class Coord
{
//private:

	//const int MIN = -500;// ошибка при присвоении
	static int count; // количество созданных объектов

	// Специфическаие константы в классе:
	static const int M = 5;		// вариант 1
	
	static const int N;

	enum { MIN = -500, MAX = 500 }; // вариант 2
	
protected: // защищенные поля/методы
	/*mutable*/ int x;
	int y;
	//int* k;
	
	//Coord(); // конструктор может быть private
	
	void correct();//private method

public:
	//Coord(); // конструктор по умолчанию
	//Coord(const int x,const int y);// конструктор с параметрами

	/*explicit*/ Coord(const int x = 0, const int y = 0);// конструктор с параметрами по умолчанию

	//explicit Coord(const int value); // конструктор с одним параметром(конструктор преобразования)
	/*explicit*/ Coord(const char* str); // конструктор с одним параметром(конструктор преобразования)

	// Запрещенный констуктор
	Coord(double x, double y) = delete;

	//конструктор копирования - принимает константную ссылку на объект
	Coord(const Coord& obj);// конструктор копирования

	void set_x(int val);
	void set_y(int val);

	int get_x()const;
	int get_y()const;

	static int get_count() {
		return count;
	}

	void reset_x_y(int x = 0, int y = 0);

	// Вируальный метод базового класса
	virtual void init();

	// Вируальный метод базового класса
	virtual void show()const;

	Coord add(const Coord& obj)const;

	// Перегрузка + для  coord + coord
	Coord  operator+(const Coord& obj)const;

	// Перегрузка + для  coord + int
	Coord  operator+(const int& obj)const;

	// Перегрузка + для  coord += coord
	Coord& operator+=(const Coord& obj);
	
	// Перегрузка coord == coord
	bool operator==(const Coord& obj) const;
	

	// Перегрузка coord != coord
	bool operator!=(const Coord& obj) const ;

	// Перегрузка операции > для сравнения двух координат
	bool operator >(const Coord& obj)const;

	// Перегрузка операции > для сравнения двух координат
	bool operator <(const Coord& obj)const;

	// Перегрузка ++ префиксная форма
	Coord& operator++();

	// Перегрузка ++ постфиксная форма
	Coord operator++(int unused);//int unused - фиктивный параметр

	Coord operator-()const;

	// Перегрузка * для  coord * coord
	//Coord  operator*(const Coord& obj)const;
	friend Coord  operator*(const Coord& left, const Coord& right);

	friend Coord operator+(const int left, const Coord& right);

	// Перегрузка потока вывода (<<)
	friend ostream& operator<<(/*std::*/ostream& out, const Coord& right);

	// Перегрузка потока ввода (>>)
	friend istream& operator >>(istream& in, Coord& b);
	
	// Перегрузка "круглых скобок"
	void operator()(const int a = 0, const int b = 0);// два параметра
	//void operator()(const int a);// один параметра
	//void operator()();// без параметров

	// operator type : coord -> int
	//operator int();
	//operator int() { return this->x * this->y; }

	//operator type : из coord в MyString
	operator MyString();

	virtual ~Coord();
};


