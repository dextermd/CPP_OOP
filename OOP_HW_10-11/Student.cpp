#include "Student.h"
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <Windows.h>

using namespace std;

// Конструкторы
Student::Student()
{
    Surname = new char[strlen("No Surname") + 1];
    if (Surname)
        strcpy_s(Surname, strlen("No Surname") + 1, "No Surname");

    Name = new char[strlen("No Name") + 1];
    if (Name)
    	strcpy_s(Name, strlen("No Name") + 1, "No Name");

    YearOfBirth = 0;

    strcpy_s(Phone, "No Phone");

    EducationName = new char[strlen("ITStep") + 1];
    if (EducationName)
        strcpy_s(EducationName, strlen("ITStep") + 1, "ITStep");

    GroupNumber = 0;

    for (int i = 0; i < N; i++)
    {
        Grade[i] = 0;
    }
    
}

Student::Student(const Student& stud)
{
    Surname = new char[strlen(stud.Surname) + 1];
    if (Surname)
    {
        strcpy_s(Surname, strlen(stud.Surname) + 1, stud.Surname);
    }

    Name = new char[strlen(stud.Name) + 1];
    if (Name)
    {
        strcpy_s(Name, strlen(stud.Name) + 1, stud.Name);
    }

    YearOfBirth = stud.YearOfBirth;

    strcpy_s(Phone, stud.Phone);

    EducationName = new char[strlen(stud.EducationName) + 1];
    if (EducationName)
    {
        strcpy_s(EducationName, strlen(stud.EducationName) + 1, stud.EducationName);
    }

    GroupNumber = stud.GroupNumber;

    for (int i = 0; i < N; i++)
    {
        Grade[i] = stud.Grade[i];
    }
}

Student::Student
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
)

{
    Surname = new char[strlen(surname) + 1];
    if (Surname)
    {
        strcpy_s(Surname, strlen(surname) + 1, surname);
    }

    Name = new char[strlen(name) + 1];
    if (Name)
    {
        strcpy_s(Name, strlen(name) + 1, name);
    }

    YearOfBirth = year;

    strcpy_s(Phone, phone);

    EducationName = new char[strlen(education) + 1];
    if (EducationName)
    {
        strcpy_s(EducationName, strlen(education) + 1, education);
    }

    GroupNumber = group_num;

    const int t_arr[N] = { grade1, grade2, grade3 , grade4 , grade5 };

    for (int i = 0; i < N; i++)
    {
        Grade[i] = t_arr[i];
    }

}

Student::Student(const char* surname, const char* name, const int year, const char* phone, const char* education, const int group_num, const int grades[N])
{
    Surname = new char[strlen(surname) + 1];
    if (Surname)
    {
        strcpy_s(Surname, strlen(surname) + 1, surname);
    }

    Name = new char[strlen(name) + 1];
    if (Name)
    {
        strcpy_s(Name, strlen(name) + 1, name);
    }

    YearOfBirth = year;

    strcpy_s(Phone, phone);

    EducationName = new char[strlen(education) + 1];
    if (EducationName)
    {
        strcpy_s(EducationName, strlen(education) + 1, education);
    }

    GroupNumber = group_num;


    for (int i = 0; i < N; i++)
    {
        Grade[i] = grades[i];
    }
}


// Методы
void Student::show() const
{
    cout << "\nФамилия              : " << Surname;
    cout << "\nИмя                  : " << Name;
    cout << "\nГод рождения         : " << YearOfBirth;
    cout << "\nТелефон              : " << Phone;
    cout << "\nУчебное заведение    : " << EducationName;
    cout << "\nНомер группы         : " << GroupNumber;
    cout << "\nОценки               : ";

    for (int i = 0; i < N; i++)
    {
        cout << Grade[i] << " ";
    }

    cout << endl;
}

void Student::set_surname(const char* surname)
{
    if (strlen(Surname) != strlen(surname) + 1)
    {
        delete[] Surname;
        Surname = nullptr;
        Surname = new char[strlen(surname) + 1];
    }

    strcpy_s(Surname, strlen(surname) + 1, surname);
}

void Student::set_name(const char* name)
{
    if (strlen(Name) != strlen(name) + 1)
    {
        delete[] Name;
        Name = nullptr;
        Name = new char[strlen(name) + 1];
    }

    strcpy_s(Name, strlen(name) + 1, name);
}

void Student::set_year_of_birth(const int year)
{
    Student::YearOfBirth = year;
}

void Student::set_phone(const char* phone)
{ 
    strcpy_s(Phone, phone); 
}

void Student::set_education_name(const char* name)
{
    if (strlen(EducationName) != strlen(name) + 1)
    {
        delete[] EducationName;
        EducationName = nullptr;
        EducationName = new char[strlen(name) + 1];
    }

    strcpy_s(EducationName, strlen(name) + 1, name);
}

void Student::set_group_number(const int number)
{
    GroupNumber = number;
}

void Student::set_five_grades(const int* arr)
{
    for (int i = 0; i < N; i++)
    {
        Grade[i] = arr[i];
    }
}

void Student::get_five_grades(int(&arr)[N])
{
    for (int i = 0; i < N; i++)
    {
        arr[i] = Grade[i];
    }
}

void Student::show_array(const int* arr, const int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}


const double Student::get_average_grades() const
{
    double sum = 0.0;
    for (int i = 0; i < N; i++)
    {
        sum += (double)Grade[i];
    }

    return (double)sum / N;
}

void Student::init()
{
    char buf[250];

    cout << "\nВведите Фамилию: ";
    cin.getline(buf, sizeof(buf));

    if (Surname)
        delete[] Surname;

    Surname = new char[strlen(buf) + 1];
    strcpy_s(Surname, strlen(buf) + 1, buf);

    cout << "\nВведите Имя: ";
    cin.getline(buf, sizeof(buf));

    if (Name)
        delete[] Name;

    Name = new char[strlen(buf) + 1];
    strcpy_s(Name, strlen(buf) + 1, buf);

    cout << "\nВведите Год рождения: ";
    cin >> YearOfBirth;
    cin.get();

    cout << "\nВведите Телефон: ";
    cin.getline(Phone, sizeof(Phone));

    cout << "\nВведите Название Учебного заведения: ";
    cin.getline(buf, sizeof(buf));

    if (EducationName)
        delete[] EducationName;

    EducationName = new char[strlen(buf) + 1];
    strcpy_s(EducationName, strlen(buf) + 1, buf);

    cout << "\nВведите Номер группы: ";
    cin >> GroupNumber;
    cin.get();

    cout << "\nВведите 5 Оценок: \n";

    for (int i = 0; i < N; i++)
    {
        cout << i + 1 << " -> ";
        cin >> Grade[i];
    }


}

void Student::show_array(const Student* stud_arr, const int size)
{
    cout << "\nВыводим Массив Студентов: \n";

    for (int i = 0; i < size; i++)
    {
        cout << "\nФамилия              : " << stud_arr[i].Surname;
        cout << "\nИмя                  : " << stud_arr[i].Name;
        cout << "\nГод рождения         : " << stud_arr[i].YearOfBirth;
        cout << "\nТелефон              : " << stud_arr[i].Phone;
        cout << "\nУчебное заведение    : " << stud_arr[i].EducationName;
        cout << "\nНомер группы         : " << stud_arr[i].GroupNumber;
        cout << "\nОценки               : ";

        for (int i = 0; i < N; i++)
        {
            cout << stud_arr[i].Grade[i] << " ";
        }
        cout << "\nСредний балл студента = " << stud_arr[i].get_average_grades() << endl;
        cout << endl;
    }
}

Student& Student::operator=(const Student& obj)
{
    if (this == &obj)
        return *this;

    char_copy(this->Surname, obj.Surname);
    char_copy(this->Name, obj.Name);
    this->YearOfBirth = obj.YearOfBirth;
    strcpy_s(this->Phone, obj.Phone);
    char_copy(this->EducationName, obj.EducationName);
    this->GroupNumber = obj.GroupNumber;
    
    for (int i = 0; i < N; i++)
    {
        this->Grade[i] = obj.Grade[i];
    }

    return *this;
}

void Student::char_copy(char*& dest, const char* source)
{
    if (strlen(dest) != strlen(source))
    {
        delete[] dest;
        dest = new char[strlen(source) + 1];
    }

    strcpy_s(dest, strlen(source) + 1, source);
}





// Деструктор
Student::~Student()
{
    delete[] Surname;
    Surname = nullptr;

    delete[] Name;
    Name = nullptr;   

    delete[] EducationName;
    EducationName = nullptr;
}
