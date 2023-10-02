#pragma once
// Обстрактный класс
class Shape
{
private:
	int x;
	int y;

protected:

public:
	Shape();
	Shape(int x, int y);

	virtual double area()const = 0; //Чисто вируальная функция
	virtual int perimetr()const = 0; //Чисто вируальная функция
	virtual void show()const;

	virtual ~Shape() = 0 {}; // У чисто виртуапльного диструктора обязательно должно быть тело   = 0 {}; пусть даже пустое, но должно быть.
};

