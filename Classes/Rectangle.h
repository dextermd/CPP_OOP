#pragma once

#ifndef __RECTANGLE__
#define __RECTANGLE__

// Поля: ширина, высота, символ, наименование цвета

// public: //  модификатор доступа по умолчанию в структуре
// protected: //  модификатор доступа по умолчанию в структуре

class Rectangle
{

// private: //  модификатор доступа по умолчанию в классе
	enum { N = 30 };
	int width;
	int height;
	int symbol;
	char color_name[N];

public:

	// Методы доступа к закрытым элементам класса // get/set
	void set_width(const int& w) { width = w; }; // inline потому что в 1 строку
	int get_width() { return width; };

	void set_height(const int& h);
	int get_height();

	void set_symbol(const char s);
	int get_symbol();

	void set_color_name(const char* cn);
	const char* get_color_name();
};

#endif // !__RECTANGLE__