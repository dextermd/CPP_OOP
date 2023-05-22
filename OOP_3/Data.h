#pragma once

// Data  - Имя типа данных
struct Data {
    int day; // поля - свойства структуры
    int month;
    int year;
};

Data init();

void init(Data& d);

Data init(const char* str);

void show(const Data& d, bool p = false);

char* month_name(int n);