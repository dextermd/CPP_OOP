#include <iostream>
#include <iomanip>
#include <Windows.h>
#include "MyString.h"
#include "Person.h"
#include "Student.h"
#include "Worker.h"
#include "Circle.h"
#include "Cylinder.h"
#include "WorkerStudent.h"
#include "Shape.h"
#include "Triangle.h"
#include "Crug.h"

using namespace std;

int main()
{

#if 1

    //-------------------------------------------------------------------------------------------//
    /*
        Создайте абстрактный базовый класс "Геом. Фигура " с виртуальной
        функцией — площадь.

        Опишите производные классы :
        прямоугольник, круг, прямоугольный треугольник,
        трапеция со своими функциями площади.

        Для проверки определить массив ссылок на абстрактный класс,
        которым присваиваются адреса различных объектов.

        Площадь треугольника(triangle) : S = 0.5 * a * h, где a — основание, h — высота.
        Площадь трапеции(trapeze) : S = (a + b)h / 2
    */

    // Обьект абстрактного класса создать нельзя но можно создать указатель
    /*Shape s;
    s.show();
    cout << s.area();
    cout << endl << endl;*/

    Shape* ptrs; // Указатель создать можно, [для создания коллекции или массива РАЗНОГО типа]


    Triangle t(2, 5, 10, 8);
    t.show();
    cout << t.area();

    cout << endl << endl;

    //ptrs = &t;
    ptrs = new Triangle;
    if (ptrs)
    {
        ptrs->show();
        cout << "\nPlosiadi: " << ptrs->area();
        cout << "\nPerimetr: " << ptrs->perimetr();
        delete ptrs; // удаляем  ptrs = new Triangle;
    }


    cout << endl << endl;

    Crug crug;
    crug.show();

#endif

    
	// Наследование ===================================================================================//

#if 0

    cout << "\n\n--------------------Person-----------------------------\n";
    Person person("Ruslan", "Dvornicov", 33, 183, 86);
    person.show();
    cout << endl;
    //person.init();
    //person.show();

    cout << endl;
    cout << "\n\n--------------------Student-----------------------------\n";
    Student stud("Iuri", "Godina", 33, 186, 95, "StepIT", MyArray(5, 9, 12));
    stud.show();
    //stud.init();
    //stud.show();
    //cout << "\nAverage grades = " << stud.get_average_grades();


    cout << "\n\n--------------------Worker-----------------------------\n";
    Worker worker("Maryna", "Poplavets", 30, 172, 52, "Hyls", 3, 10000);
    worker.show();
    cout << endl;
    //worker.init();
    //worker.show();

    cout << "\n\n--------------------Work_Student-----------------------------\n";

    /*
        Класс Работающий студент,	 наследуем от Студента и Служащего
            - количество рабочих дней в неделю
            - количество дней учебных в неделю
    */

    WorkerStudent worker_stident("Vladimir", "Bogdan", 25, 178, 75, "UTM", MyArray(6, 8, 12), "MicroSoft", 50000, 5, 3, 2);
    worker_stident.show();
    //worker_stident.init();
    cout << endl;


    cout << "\n---------------------------------------------------------------\n";
    Person* ptr;
    //ptr = &worker_stident;
    ptr = new WorkerStudent("Vladimir", "Bogdan", 25, 178, 75, "UTM", MyArray(6, 8, 12), "MicroSoft", 50000, 5, 3, 2);
    if (ptr)
    {
        ptr->show();
    }
    delete ptr;
    cout << endl;

#endif

#if 0

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

            switch (n) {
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

#endif


}


