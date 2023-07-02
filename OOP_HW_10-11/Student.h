#pragma once
#include <iomanip>

class Student
{
    static const int N = 5;
    char* Surname;
    char* Name;
    int YearOfBirth;
    char Phone[20];
    char* EducationName;
    int GroupNumber;
    int Grade[5];

public:

    // Конструкторы
    Student();
    Student(const Student& stud); // Конструктор копирования
    Student
    (
        const char* surname,
        const char* name,
        const int year,
        const char* phone,
        const char* education,
        const int group_num,
        const int grade1,
        const int grade2,
        const int grade3,
        const int grade4,
        const int grade5
    );

    // Методы
    void show() const;

    int get_n() { return N; };

    void set_surname(const char* surname);
    const char* get_surname() const { return Surname; };

    void set_name(const char* name);
    const char* get_name() const { return Name; };

    void set_year_of_birth(const int year);
    int get_year_of_birth() const { return YearOfBirth; };

    void set_phone(const char* phone);
    const char* get_phone() const { return Phone; };

    void set_education_name(const char* name);
    const char* get_education_name() const { return EducationName; };
    
    void set_group_number(const int number);
    const int get_group_number() const { return GroupNumber; };

    void set_five_grades(const int* arr);
    void get_five_grades(int(&arr)[N]);

    void show_array(const int* arr, const int size);

    const double get_average_grades() const;

    void init();

    static void show_array(const Student* stud_arr, const int size);


    // Деструктор
    ~Student();

};

