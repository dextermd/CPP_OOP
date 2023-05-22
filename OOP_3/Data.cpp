#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include "Data.h"

using namespace std;

Data init()
{
    Data t;
    cout << "\nВведи день, месяц, год: ";
    cin >> t.day >> t.month >> t.year;

    return t;
}

void init(Data& d)
{
    cout << "\nВведи день, месяц, год: ";
    cin >> d.day >> d.month >> d.year;
}

Data init(const char* str) // Выриант 3 информация передана из строки "6.8.2022"
{
    Data t;
    char* t1, * t2;
    char copy[32]; // делаем копию потому что мы передаеи const char
    strcpy_s(copy, str);

    t1 = strtok_s(copy, ",. /;_", &t2); // "6"
    t.day = atoi(t1); // конвертируем строку в int

    t1 = strtok_s(nullptr, ",. /;_", &t2); // "8"
    t.month = atoi(t1); // конвертируем строку в int

    t1 = strtok_s(nullptr, ",. /;_", &t2); // "2022"
    t.year = atoi(t1); // конвертируем строку в int

    return t;
}

void show(const Data& d, bool p)
{
    if (p)
    {
        cout << d.day << " " << month_name(d.month) << " " << d.year;
    }
    else {
        cout << d.day << "." << d.month << "." << d.year;
    }

}

char* month_name(int n)
{
    // статическая переменая должна быть  обьявлена и одновременно проинициализирована !!!!!!
    static char name[][20]{
        "none", "Январь", "Февраль", "Март", "Апрель", "Май", "Июнь", "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь"
    };

    return (n >= 1 && n <= 12) ? name[n] : name[0];
}