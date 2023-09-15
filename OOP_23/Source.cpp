#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include "Coord.h"
#include "MyString.h"
#include "Circle.h"
#include "Cylinder.h"

using namespace std;

int main()
{
	// Наследование ============================================================================
	
#if 0

	// Кордината <-- круг <-- цилиндр.

	Coord a(2, -2);
	a.show(); // Ранее связывание

	Circle b;
	b.show();

	Circle c(12, 9, 5.5);
	c.show(); // Ранее связывание

	cout << endl;

	Circle d(a, 2.5);
	d.show(); // Ранее связывание

	cout << endl << endl;

	Coord* ptr_coord; // Указатель базового класса
	ptr_coord = &a; // a - Coord;
	ptr_coord->show(); // Позднее связывение  // или  (*ptr_coord).show();
	
	ptr_coord = &c; // Позднее связывение --> // В указатель базового класса (Coord) записываем адресс обьекта произвольного класса -> (Circle)
	ptr_coord->show(); // Зачсет того что в Coord базавого класса есть  [--> virtual <-- void show() const;]  он выведет все данные произвольного класса -> (Circle) VIRTUAL ДАЕТ ВОЗМОЖНОСТЬ ПОЗДНЕГО СВЯЗЫВАНИЯ 
	
	// Виртуальные функции базового клаасса позволяют делать позднее связывание
	/*
	
		Связывание(binding) – это связь между именем вызываемого метода
		  и непосредственно местом, где этот метод реализован.

		  Раннее связывание:
			  Перегрузка методов и конструкторов относится к раннему связыванию.

			  Т.е.когда компилятор на этапе компиляции, исходя из имеющихся типов данных,
			  передаваемых в вызываемый метод, определяет что вызывать.

			  Преимущество раннего связывания в том,
			  что при невозможности установить связь между вызываемым именем
			  и существующими методами,
			  будет выдана ошибка на этапе компиляции, и сборка проекта прекращается.

		  Позднее связывание:
				Выбор переопределённого(override) метода откладывается на момент
				обращения к методу во время исполнения программы.

				На момент компиляции компилятор точно не знает,
				какой из группы переопределённых методов будет выполнен.

				Для включения позднего связывания необходимо объявить
				соответствующие методы виртуальными(virtual).
	*/

	ptr_coord = new Circle(20, 20, 6.5);
	if (ptr_coord)
	{
		ptr_coord->show();
		//.....
		delete ptr_coord;
	}

	Cylinder cyl, cyl1(2,3, 4.2, 3);
	cyl.show();
	cyl1.show();

	cout << endl << endl;

	cout << "\nPTR\n";
	Coord* ptr_coord2;
	ptr_coord2 = &cyl1;
	ptr_coord2->show();

	//-----------------------------------------------------------------------------------------//
	// Реалтзовать класс цилиндр который будет являтся производным от класса Круг
	// Дополнительное поле - высота

#endif

#if 1

	//---------------------------------------------------------
	//Динамический полиморфизм---------------------------------

	int s, n;
	cout << "\nEnter the number of objects(shapes) ";
	cin >> s;

	// динамический массив указателей базового класса
	Coord** mas = new Coord * [s];

	if (mas) {

		for (int i = 0; i < s; )
		{
			cout << "\nChoose a figure:";
			cout << "\n1 - Coord \n2 - Cyrcle  \n3 - Cylinder \n ";
			cin >> n;

			if (n < 1 || n > 3) {
				cout << "\nError\n";
				continue;
			}

			switch (n){
			case 1: mas[i] = new Coord(2, 2);  break;
			case 2: mas[i] = new Circle(12, 6, 9.5);  break;
			case 3: mas[i] = new Cylinder(1, 1, 5, 40);  break;
			}

			mas[i]->init();
			i++;
		}

		cout << "\nArray of objects:\n";
		for (int i = 0; i < s; i++)
		{
			mas[i]->show();
			cout << endl;
		}

		//...

		for (int i = 0; i < s; i++)
			delete mas[i];

		delete[]mas;



	}
#endif // 1


	// Работа с файлами ========================================================================

#if 0

	// Работа с файлами C++ -------------------------------------------------------------------------
	// Произвольный доступ  -------------------------------------------------------------------------

	ofstream fout("text.txt");
	int k = 20;
	if (fout)
	{
		cout << "\nPosition in file: " << fout.tellp(); // 0
		fout << "Write to file!\nl = " << k;
		cout << "\nPosition in file: " << fout.tellp(); // 22
		// fout.seekp(0); // по умолчанию смещение от начала
		fout.seekp(-5,ios::end); // смещение от конца
		cout << "\nPosition in file: " << fout.tellp(); // 17
		fout.seekp(-2, ios::cur);
		cout << "\nPosition in file: " << fout.tellp(); // 15
		fout.seekp(0, ios::beg);
		cout << "\nPosition in file: " << fout.tellp(); // 0
		fout << "!!!";
		cout << "\nPosition in file: " << fout.tellp();
		fout.close();
	}
	else {
		cout << "\nError writing file!";
	}

#endif

#if 0

	fstream f("my_file.txt", ios::out | ios::in | ios::trunc /*| ios::ate*/);

	// ios::ate - помещает файловый указатель в конец существующего файла
	// и позволяет перемещаться по файлу
	// но требуется чтобы файл уже существовал

	char s;
	if (f)
	{
		cout << "\nPosition in file: " << f.tellp(); // 0
		f << "Writing to txt file in txt format";
		cout << "\nPosition in file: " << f.tellp();
		f.seekp(21);
		cout << "\nPosition in file: " << f.tellp();
		f << "FORMAT";
		cout << "\nPosition in file: " << f.tellp();
		f.seekp(0);
		f.get(s);
		cout << endl << s << endl;
		cout << "\nPosition in file: " << f.tellp();

		f.close();
	}

	else {
		cout << "\nError";
	}

#endif

#if 0
	int k;
	Coord arr[5]{ {1,1}, {10,0}, {5,-5}, {-7,11}, {-10,6} }, cord;

	fstream c("cord.txt", ios::out | ios::in | ios::trunc);
	if (c)
	{
		f << arr;
		f.seekp(0);
		f.get(cord);
		f.close();
	}

	else {
		cout << "\nError";
	}

#endif 


}