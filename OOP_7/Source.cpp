#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include "Rectangle.h"
#include "Coord.h"

using namespace std;

int main()
{

#if 1

    /*
    Дополнить класс Координата :
    -метод для сложения двух координат(add)
    */

    Coord a(2, -3), b(25, -9), c;
    a.show();
    cout << endl;
    b.show();
    cout << endl;
    c = a.add(b);
    c.show();


#endif 


#if 0
    /*
        Отредактировать конструкторы :
        Реализовать ограничение на максимальное и минимальное значения полей.
            В случае создания объекта с невозможным значением устанавливать
            соответственно одну из границ. 
    */

    Coord A, B(25, -9);
    A.show();
    A = B;
    A.show();

    Coord C(20, 560);
    C.show();


#endif 



#if 0

    /*
        Написать класс Координата   coord
        Поля:
            два целых значения x, y
        Методы:
            - конструктор по умолчанию
            - конструктор с параметрами

            - конструктор с параметрами по умолчанию
            - конструктор, принимающий строку

            - методы доступа к закрытым полям
            - метод обнуления обеих координат(reset)
            - метод инициализации объекта с клавиатуры(init)
            - метод отображения данных объекта(show)
            - деструктор

        Продемонстрировать работу класса на:
            - отдельных объектах
            - статическом массиве
    */

    class Coord a;
    a.show();

    cout << endl << endl;

    Coord b(1, 2);
    b.show();

    cout << endl << endl;

    Coord m("100,200");
    m.show();
    m.reset(1, 5);
    m.show();
    m.reset(2);
    m.show();
    m.reset();
    m.show();

    cout << endl << endl;

    //Coord I;
    //I.init();
    //I.show();

    //cout << endl << endl;

    Coord d[6]
    {
        {1,2},
        {},
        {"5,6"},
        Coord(7,8),
        Coord(),
    };

    Coord::show(d, 6);


  


#endif 



#if 0

    // 1. Абстракция, 2. Инкапсуляция, 3.  

    class Rectangle A(5, 10, '+', "blue");
    A.show();

    cout << "\nВысота: " << A.get_height();

#endif 




#if 0
        // Создание динамического массива Rectangle
    int size;
    cout << "\nВведи кол-во обьектов: ";
    cin >> size;

    class Rectangle* arr = new class Rectangle[size];

    if (arr)
    {
        //for (size_t i = 0; i < size; i++)
        //{
        //    arr->init();
        //}

        cout << "\nМассив прямоугольников: \n";

        // 1 - Вызов статического метода через обьекта класса
        //arr[0].show(arr, size);

        // 2 - Вызов статического метода через имя класса
        Rectangle::show(arr, size);

        cout << "\nОбьем памяти под обьект: " << sizeof(class Rectangle) << endl;
        cout << "\nОбьем памяти адрес/указатель: " << sizeof(arr) << endl;
        //cout << "\nОбьем памяти под массив: " << sizeof(class Rectangle * size) << endl;

        //...
        delete[]arr;
        arr = nullptr;
    }


    
#endif


    _getch;
}