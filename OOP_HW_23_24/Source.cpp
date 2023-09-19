#include <iostream>
#include <iomanip>
#include <Windows.h>
#include "MyString.h"
#include "ListOneT.h"
#include "Passport.h"
#include "ForeignPassport.h"
#include "HomePet.h"
#include "Cat.h"
#include "Dog.h"
#include "Parrot.h"
#include "Hamster.h"
#include "Shape.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Rectangle.h"
#include "Square.h"

using namespace std;

int main()
{

#if 0

	/*
		Задание 1. 
			Создайте базовый класс Passport(паспорт), который будет содержать паспортную
			информацию о гражданине Молдовы.С помощью механизма наследования, реализуйте класс
			ForeignPassport(заграничный паспорт), производный от Passport.Напомним, что заграничный
			паспорт содержит помимо паспортных данных, также данные о визах, номер заграничного
			паспорта.Реализовать метод для добавления визы.Примечание: для полей строкового типа
			используйте класс MyString.Данные о визах необходимо хранить в списке(класс ListT).
	*/

	Passport passport;
	passport.show();

	cout << endl << endl;

	ForeignPassport fpassport;
	fpassport.show();
	MyString visa_usa = "USA";
	fpassport.add_visa(visa_usa);
	fpassport.show();

#endif 

#if 0

	/*
		Задание 2. 
			Создайте абстрактный базовый класс «Домашнее животное» и производные классы
			«Собака», «Кошка», «Попугай», «Хомяк».С помощью конструктора установите имя каждого
			животного и его характеристики.Реализуйте для каждого из классов функции :
			Sound – издает звук животного(пишем текстом в консоль);
			Show – отображает имя животного;
			Type – отображает название его подвида.
			Продемонстрируйте на примере инструмент динамического полиморфизма.
	*/

	HomePet* ptr = new Cat("Skitless", "British chinchilla fold");
	ptr->show();
	ptr->show_type();
	ptr->sound();
	delete ptr;

#endif

#if 0

	/*
		Задание 3. 
			Создайте абстрактный класс Shape для рисования плоских фигур.Определите виртуальные методы :
				-Show() — вывод на экран информации о фигуре,
				-Save() — сохранение данных фигуры в двоичный файл,
				-Load() — считывание данных фигуры из двоичного файла.
			Определите производные классы :
				-Square — квадрат, который характеризуется координатами левого верхнего угла идлиной стороны;
				-Rectangle — прямоугольник с заданными координатами верхнего левого угла и размерами;
				-Circle — окружность с заданными координатами центра и радиусом;
				-Ellipse — эллипс с заданными координатами верхнего угла описанного вокруг него
				прямоугольника со сторонами, параллельными осям координат, и размерами этого
				прямоугольника.
			Создайте массив фигур, сохраните фигуры в двоичный файл, загрузите в другой массив и отобразите информацию о каждой из фигур.
	*/

	Square square(1, 2, 5);
	class Rectangle rectangle(3, 4, 6, 7);
	Circle circle(8, 9, 10);
	class Ellipse ellipse(11, 12, 13, 14);

	Shape* shapes[] = { &square, &rectangle, &circle, &ellipse };
	
	ofstream fout("shape.txt", ios::binary);
	if (fout)
	{
		for (const auto& shape : shapes) {
			shape->show();
			shape->save_to_binary_file(fout);
		}	
		fout.close();
	}
	else {
		cout << "\nError write file!";
	}
	
	Square square_c;
	class Rectangle rectangle_c;
	Circle circle_c;
	class Ellipse ellipse_c;

	Shape* shapes_c[] = { &square_c, &rectangle_c, &circle_c, &ellipse_c };

	cout << "\n\nCOPY-----------------------------------------------------------------\n\n";

	ifstream fin("shape.txt", ios::binary);

	if (fin)
	{
		for (const auto& shape : shapes_c)
		{
			shape->read_from_binary_files(fin);
			shape->show();
		}
	}
	else {
		cout << "\nError read file!";
	}


#endif

}