#pragma once
class Coord
{
	
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

	Coord();
	Coord(const int x, const int y);
	Coord(const char* str);


	void show() const;
	static void show(const Coord* arr, int size);

	int get_x() const;
	void set_x(const int& h);

	int get_y() const;
	void set_y(const int& h);

	void reset(int x = 0, int y = 0);

	void init();

	Coord add(const Coord& obj) const;

	~Coord();
};

