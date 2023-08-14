
#pragma once
#include <iostream>
#include "MyString.h"

using namespace std;

class Coord
{
	static int count_obj; // Кол-во созданных обьектов

	// private: //  модификатор доступа по умолчанию в классе
	// const int MIN = -500; // Ошибка при присвоении
	// Спецефичемкие константы в классе:
	// static const int MIN = -500, MIN = -500; // Вариант 1
	enum { // Вариант 2
		MAX = 500,
		MIN = -500
	};

	int x;
	int y;

	// Coord(); // Конструктор может быть pivat
	void correct(); // private method

public:

	Coord(); // Конструктор по умолчанию
	Coord(const int x, const int y); // Конструктор с параметрами 
	/*explicit*/ Coord(const int value); // Конструктор с одним параметром (конструктор переобразователь)

	
	//Coord(const int x = 0, const int y = 0); // Конструктор с параметрами по умолчанию
	
	/*explicit*/ Coord(const char* str); // Конструктор с одним параметром (конструктор переобразователь)


	Coord(double x, double y) = delete; // Запрещенный конструктор

	// Принимает константную ссылку на обьект
	Coord(const Coord& obj); // Конструктор копирования copy
	Coord(Coord&& obj); // Конструктор перемещения

	void show() const;
	static void show(const Coord* arr, int size);

	static int get_count_obj() { return count_obj; };

	int get_x() const;
	void set_x(const int& h);

	int get_y() const;
	void set_y(const int& h);

	void reset(int x = 0, int y = 0);

	void init();

	Coord add(const Coord& obj) const;

	// Перегрузка = для coord + coord 
	Coord operator+(const Coord& obj) const;

	// Перегрузка = для coord + int 
	Coord operator+(const int& obj) const;

	// Перегрузка = для coord += coord 
	Coord& operator+=(const Coord& obj);

	// Перегрузка = для coord == coord 
	bool operator==(const Coord& obj) const;

	// Перегрузка = для coord != coord 
	bool operator!=(const Coord& obj) const;

	// Перегрузка = для coord > coord 
	bool operator>(const Coord& obj) const;

	// Префиксная форма (сначало отрабатывает)
	Coord& operator++();

	// Постфиксная форма (отрабатывает после)
	Coord operator++(int unused);

	Coord operator-() const;

	Coord& operator=(const Coord& obj) = default;

	// Перегрузка = для coord * coord 
	// Coord operator*(const Coord& obj) const;
	friend Coord operator*(const Coord& left_obj, const Coord& right_obj);

	// Дружественная функция
	// Дружественная функция - не является методом класса.
	// Дружественная функция - есть доступ к закрытым полям класса через объект.
	// Дружественная функция - нет доступа к this.
	friend Coord operator+(const int num, const Coord& obj);

	// Перегрузка потока вывода (<<)
	friend ostream& operator<<(std::ostream& out, const Coord& obj);

	// Перегрузка потока ввода (>>)
	friend istream& operator>>(std::istream& in, Coord& obj);

	// Перегрузка "круглых скобок"
	void operator()(const int a, const int b); // Два параметра
	void operator()(const int a); // Один параметра
	void operator()(); // Без параметра

	// operator type
	operator int();

	operator MyString();


	~Coord();
};

