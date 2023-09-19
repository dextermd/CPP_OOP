#pragma once
#include <fstream>
// Обстрактный класс
class Shape
{
private:


protected:
	int x;
	int y;

public:
	Shape();
	Shape(int x, int y);

	virtual void show() const = 0;
	virtual void save_to_binary_file(std::ofstream& fout) const = 0 ;
	virtual void read_from_binary_files(std::ifstream& fin) = 0;

	virtual ~Shape() = 0 {}; // У чисто виртуапльного диструктора обязательно должно быть тело   = 0 {}; пусть даже пустое, но должно быть.
};

