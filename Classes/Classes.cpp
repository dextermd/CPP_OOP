#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include "Rectangle.h"

using namespace std;

int main()
{
    // ---------------------------------------------------------------------- //
    // Классы --------------------------------------------------------------- //
    // ---------------------------------------------------------------------- //
    /*
        Написать класс Прямоугольник
        Поля: ширина, высота, символ, наименование цвета
    */

    class Rectangle a, b;
    a.set_width(20);
    a.set_height(5);
    a.set_symbol('#');
    a.set_color_name("green");

    cout << "\nШирина : " << a.get_width();
    cout << "\nВысота : " << a.get_height();
    cout << "\nСимвол : " << a.get_symbol();
    cout << "\nЦвет   : " << a.get_color_name();

    b.set_height(a.get_height());

    cout << endl << endl;

    cout << "\nШирина : " << b.get_width();
    cout << "\nВысота : " << b.get_height();
    cout << "\nСимвол : " << b.get_symbol();
    cout << "\nЦвет   : " << b.get_color_name();
    
    _getch();
}