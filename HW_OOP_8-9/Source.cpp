#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include "Student.h"

using namespace std;

int main()
{
    /*Задание 1. 
        Реализуйте класс “Студент”.Необходимо хранить в переменных - свойствах класса :

        + Фамилию(память выделять динамически),
        + Имя(память выделять динамически),
        + год рождения,
        + контактный телефон(статическая строка),
        + название учебного заведения(память выделять динамически),
        + номер группы,
        + 5 оценок(одномерный статический массив).

        + Реализуйте конструкторы, метод класса для вывода данных на экран, реализуйте методы
            доступа к отдельным переменным - членам и метод определения и возврата среднего балла
            студента.
        
        + Напишите метод для инициализации объекта класса с клавиатуры.

        + Реализуйте деструктор и конструктор копирования.

        + Продемонстрируйте работу всех методов на примерах.

        + Создайте статический массив типа “Студент”, инициализируйте на этапе разработки и выведите
            его на экран.*/

    Student Stud;
    Stud.show();
    cout << "\n ------------------------------------------- \n";
    Stud.set_surname("Dvornicov");
    Stud.show();
    cout << "\nМетод get_surname: " << Stud.get_surname() << endl;
    cout << "\n ------------------------------------------- \n";
    Stud.set_name("Ruslan");
    Stud.show();
    cout << "\nМетод get_name: " << Stud.get_name() << endl;
    cout << "\n ------------------------------------------- \n";
    Stud.set_year_of_birth(1990);
    Stud.show();
    cout << "\nМетод get_year_of_birth: " << Stud.get_year_of_birth() << endl;
    cout << "\n ------------------------------------------- \n";
    Stud.set_phone("068751173");
    Stud.show();
    cout << "\nМетод get_phone: " << Stud.get_phone() << endl;
    cout << "\n ------------------------------------------- \n";
    Stud.set_education_name("ItStep");
    Stud.show();
    cout << "\nМетод get_education_name: " << Stud.get_education_name() << endl;
    cout << "\n ------------------------------------------- \n";
    Stud.set_group_number(2222);
    Stud.show();
    cout << "\nМетод get_group_number: " << Stud.get_group_number() << endl;
    cout << "\n ------------------------------------------- \n";
    const int N = 5;
    int arr[N] = { 8, 9, 10, 5, 6 };
    int arr2[N];
    Stud.set_five_grades(arr);
    Stud.show();
    Stud.get_five_grades(arr2);
    cout << "\nМетод get_five_grades: "; 
    Stud.show_array(arr2, N);
    cout << "\n ------------------------------------------- \n";
    cout << "\nСредний балл студента = " << Stud.get_average_grades() << endl;
    cout << "\n ------------------------------------------- \n";
    //Stud.init();
    Stud.show();
    cout << "\nСредний балл студента " << Stud.get_name() << " = " << Stud.get_average_grades() << endl;
    cout << "\n ------------------------------------------- \n";
    Student d(Stud);
    d.show();
    cout << "\n ------------------------------------------- \n";

    Student arr_student[N]{
        {},
        {"Demo Surname2", "Demo Name2", 1902, "060111222", "Demo Education2", 2, 4,9,5,3,5 },
        {"Demo Surname3", "Demo Name3", 1903, "060111223", "Demo Education3", 3, 5,5,8,9,6 },
        {"Demo Surname4", "Demo Name4", 1904, "060111224", "Demo Education4", 4, 6,3,7,3,7 },
        {"Demo Surname5", "Demo Name5", 1905, "060111225", "Demo Education5", 5, 7,1,5,2,1 },
    };

    Student::show_array(arr_student, N);


    _getch;
}