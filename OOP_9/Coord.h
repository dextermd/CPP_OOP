#pragma once
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
	Coord(const int value); // Конструктор с одним параметром (конструктор переобразователь)

	//Coord(const int x = 0, const int y = 0); // Конструктор с параметрами по умолчанию
	
	Coord(const char* str); // Конструктор с одним параметром (конструктор переобразователь)

	// Принимает константную ссылку на обьект
	Coord(const Coord& obj); // Конструктор копирования copy

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

	~Coord();
};

