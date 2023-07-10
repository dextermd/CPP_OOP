#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include "Coord.h"
#include "Stock.h"
#include "MyString.h"
#include "Rectangle.h"
#include "Car.h"
#include "Truck.h"
#include "tv.h"
#include "function.h"

using namespace std;


int main()
{


#if 1

	// ------------------------------------------------------------------------------------- //
	// 
	//printf("Hello\n");
	//int a = 5;
	//printf("a = %d", a);

	// Функции с произвольным количеством и типом аргуметов -------------------------------- //

	cout << summa(4, 1, 3, -5, 10, 3, 6, 4) << endl;
	cout << summa_double(4, 1.25, 31.25, -5.25, 3.3, 6.6, 4.4) << endl;





#endif 


#if 0

	// ------------------------------------------------------------------------------------- //
	// Пример - дружественные классы 

	Tv t;
	t.settings();
	t.onoff();
	t.settings();
	t.chanup();
	t.settings();

	
	Remote black;
	// Вариант 1
	black.set_chan(t, 25);
	t.settings();

	// Вариант 2
	//set_chan(t, black, 30);
	//t.settings();


#endif 



#if 0
	 
	// ------------------------------------------------------------------------------------- //
	// Пример - дружественная функция в классе 

	class Rectangle r(12, 58, '+', "Red", "Rectangle");
	r.show();

	r.set_symbol('#'); // Вызов метода класса

	r.show();

	set_symbol(r, '%'); // Вызов дружественной функции

	r.show();

#endif 

#if 0

	// ------------------------------------------------------------------------------------- //
	// Пример - дружественная функция для двух классов

	// Car - кол-во пассажиров, скорость
	// Truck - грузовместимость, скорость

	
	Car c(2, 100);
	c.show();

	Truck t(600, 80);
	t.show();

	cout << "\nРазность скоростей: " << speed_compare(c, t) << endl;


#endif 


}