#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include "Rectangle.h"

using namespace std;

int main()
{

#if 0

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

    //a.show();
    /*b.init();
    b.show();*/

    /*b.set_height(a.get_height());
    cout << endl << endl;
    cout << "\nШирина : " << b.get_width();
    cout << "\nВысота : " << b.get_height();
    cout << "\nСимвол : " << b.get_symbol();
    cout << "\nЦвет   : " << b.get_color_name();*/



    // --------------------------------------------------------------------------------- //
    /*
        Дополнить класс "Прямоугольник" следующими методами :
        -вывод данных объекта на экран : void show();
        -инициализация объекта с клавиатуры(init)
    */

    /*b.init();
    b.show();*/


    // --------------------------------------------------------------------------------- //
    /*Самостоятельно:
        - расчет и возврат площади прямоугольника
        - расчет и возврат периметра прямоугольника*/

    a.show();
    cout << "\nПлощадь: " << a.area();
    cout << "\nПериметр: " << a.perimetr();

    cout << endl << endl;

    class Rectangle c;
    c.show();
    cout << "\nsizeof = " << sizeof(c);
    cout << "\nadress 'c' = " << &c;

    cout << endl << endl;
    c.set_width(5);
    c.show();

    cout << endl << endl;

    class Rectangle d(12, 7, '#', "Blue");
    d.show();

    cout << endl << endl;

    class Rectangle e(12, 7, '#');
    e.show();

    // Конструктор с параметрами по умолчанию 
    cout << "\n--------------------------------------\n";
    class Rectangle k1(200), k2(200, 3), k3(5, 10, '&');
    k1.show();
    k2.show();
    k3.show();


    // Конструктор переобразования

    class Rectangle t("cветло голубой");
    t.show();

#endif 


#if 0

    // Указатель на обьект класса 

    class Rectangle x; // конструктор по умолчанию 
    x.show();

    class Rectangle* ptr;
    ptr = &x;

    ptr->show();

    // Создание обьекта динамически

    // class Rectangle* tmp = new class Rectangle; // конструктор по умолчанию 
    // class Rectangle* tmp = new class Rectangle(25,3,'-', "red"); // конструктор по умолчанию 
    class Rectangle* tmp = new class Rectangle; // конструктор по умолчанию 
    if (tmp)
    {
        tmp->init();

        //tmp->show(); или //(*tmp).show();
        (*tmp).show();

        delete tmp;
        tmp = nullptr;
    }

#endif


#if 0

    // Создание статического массива обьектов типа Rectangle

    const int N = 5;
    class Rectangle arr[N]{ 
        {10, 5, '^', "yellow"},
        (6, 9, '%'),
        "blue",
        {125, 3, '!'}
    };

    for (int i = 0; i < N; i++)
    {
        arr[i].show();
    }

    cout << "\nsizeof: = " << sizeof(arr) << endl;

#endif

#if 1

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


    _getch();
}