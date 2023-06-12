#pragma once

#ifndef __RECTANGLE__
#define __RECTANGLE__

// Конструкторы нужны для удобства создания обьекта.

// Поля: ширина, высота, символ, наименование цвета

// public: //  модификатор доступа по умолчанию в структуре
// protected: //  модификатор доступа по умолчанию в структуре

class Rectangle
{

// private: //  модификатор доступа по умолчанию в классе
	enum { N = 30 };
	int width;
	int height;
	char symbol;
	char color_name[N];

public:

	// Rectangle();

	Rectangle(const int w = 10, const int h = 5, const char s = '*', const char* cn = "white");

	Rectangle(const char* cn);


	// Методы доступа к закрытым элементам класса // get/set
	void set_width(const int& w) { width = w; }; // inline потому что в 1 строку
	int get_width() { return width; };

	void set_height(const int& h);
	int get_height() const; // Константный метод он не разрешает менять значения через this

	void set_symbol(const char s);
	int get_symbol()const; // Константный метод он не разрешает менять значения через this

	void set_color_name(const char* cn);
	const char* get_color_name() const; // Константный метод он не разрешает менять значения через this

	// Методы
	void show() const;
	void init();

	int area() const;
	int perimetr() const;

	// Статический
	static void show(const Rectangle* arr, int size);

	// Деструктор
	~Rectangle();
};

#endif // !__RECTANGLE__