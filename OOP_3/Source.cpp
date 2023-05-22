#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include <string.h>
#include <algorithm>
#include "Student.h"
#include "Data.h"


using namespace std;

int main()
{

    /*
    Режимы доступа:

    r — чтение, если файла нет, то данная функция
    генерирует ошибку (возвращает 0)  - для fopen

    r — чтение, если файла нет, то данная функция
    генерирует ошибку (возвращает ее код)
    и нуль в случае успеха  - для fopen_s

    w — запись, если файла нет, то файл создаётся,
        если файл есть, исходное содержимое удаляется.

    a — добавление в конец, а если файла нет, то он создаётся.

    r+ — чтение и запись (файл должен существовать).
    w+ — чтение и запись (принцип работы как у w).
    a+ — добавление и чтение (принцип работы как у a).

    wb - запись в двоичный файл
    rb - чтение из двоичного файла

    rb+ (r+b) — чтение и запись (файл должен существовать).
    wb+ (a+b) — чтение и запись (принцип работы как у w).
    ab+ (a+b) — добавление и чтение (принцип работы как у a).

*/


    /*
    Язык С позволяет определять имена новых типов данных
    с помощью ключевого слова typedef.

    На самом деле здесь не создается новый тип данных,
    а определяется новое имя существующему типу.


    Он позволяет облегчить создание машинно-независимых программ.
    Единственное, что потребуется при переходе на другую платформу
    - это изменить оператор typedef.

    Стандартный вид оператора typedef следующий:

        typedef тип имя;

    где тип — это любой существующий тип данных,
    а   имя - это новое имя для данного типа.

    Новое имя определяется в дополнение к существующему имени типа,
    а не замещает его.

*/

#if 0

// ------------------------------------------------------------------------------------------------- //
// Текстовые и двоичные файлы ---------------------------------------------------------------------- //
// Последовательный и произвольный доступ ---------------------------------------------------------- //
// ------------------------------------------------------------------------------------------------- //
// ------------------------------------------------------------------------------------------------- //
// Запись в файл а текстовом формате, Си ----------------- fopen ----------------------------------- //
// необходим: #define _CRT_SECURE_NO_WARNINGS ------------------------------------------------------ //
// Общая форма  ------------------------------------------------------------------------------------ //
// ------------------------------------------------------------------------------------------------- //

// 1. Последовательный

/*
    Файловый указатель — специальная переменная, которая
    автоматически присваивается открытому файлу и
    хранит текущую позицию в файле.
    */

    // Общая форма Cи

    FILE* file;

    char path[60] = "d:\\file_test\\test.txt";
    file = fopen("1.txt", "w"); // текущая папка проекта
    //file = fopen(path, "w");
    if (file)
    {
        // TODO
        fprintf(file, "Hello, summer!");
        fputs("\nПривет, лето", file); // (fputs) Запись ТОЛЬКО СТРОКИ в файл.)
        printf("\nФайл записан \n");
        fclose(file);
    }
    else {
        printf("\nОшибка записи в файл");
    }

    // Чтение файла ------------------------------------------------------------------------------

    char str[256];
    char s;

    FILE* fread;
    fread = fopen("1.txt", "r");
    if (fread)
    {
        // TODO
        //fgets(str, sizeof(str), fread); // (fgets) Чтение ТОЛЬКО 1 СТРОКИ из файла.
        //printf("\nСтрока из файлов: %s", str);

        printf("\nИнформация из файла: \n");

        //// Построчное чтение - вариант 1
        //while (!feof(fread))
        //{
        //    fgets(str, sizeof(str), fread); // (fgets) Чтение ТОЛЬКО 1 СТРОКИ из файла. (while  цикл для чтение всех строк)
        //    printf("%s", str);
        //}

        // Посимвольное чтение - вариант 2
        while (!feof(fread)) // !feof(fread) - Пока не конец файла
        {
            s = fgetc(fread); // Чтение символа с возвратом кодировки ASCHI
            if (feof(fread)) break;
            printf("%c", s);
        }

        fclose(fread);
    }
    else {
        printf("\nОшибка чтении файла");
    }

#endif


#if 0

    /*
    Задача: ввести  с клавитуры три строки и записать их в файл.
    */

    char str[250];
    FILE* file;
    errno_t err;
    err = fopen_s(&file, "strings.txt", "w");

    if (!err)
    {
        printf("\nВведите при строки: \n");

        for (int i = 0; i < 3; i++)
        {
            fputs(str, file); // запись только строки в файл
            fprintf(file, "\n%d). %s\n", i + 1, str); // запись в файл
        }

        fclose(file);
    }
    else {
        strerror_s(str, sizeof(str), err);
        printf("\nERROR: %s", str);
    }

   
#endif



#if 0

    /*
    Задача: Написать программу, которая создает копию текстового файла
    */

    char str[250];
    FILE* file;
    errno_t err;
    err = fopen_s(&file, "strings.txt", "r");

    if (!err)
    {
        FILE* fw;
        errno_t err_cpy;
        err_cpy = fopen_s(&fw, "copy_strings.txt", "w");

        if (!err_cpy)
        {
            while (!feof(file)) // пока не конец файла
            {
                fgets(str, sizeof(str), file); // считывание только строки целиком из файла
                if (!feof(file)) break;
                fputs(str, fw); // запись только строки в файл
                fprintf(fw, "\n---------------------------\n");
                // puts(str); // Вывод строки  на экран
                printf("%s", str);
            }
            fclose(fw);
        }

        fclose(file);
    }
    else {
        printf("\nОшибка открытия файла");
    }

#endif


#if 0

    /*
    Задача: Последовательно записать в файл значения переменных разного типа, затем
    считать из файла с инициализацией других переменных соответствующего типа.
    */

    int a = 25;
    double d = 36.8954621;
    char s = '!';
    char str[20] = "Hello, world!";

    FILE* fw;
    errno_t err;
    err = fopen_s(&fw, "data.txt", "w");

    if (!err)
    {
        fprintf(fw, "%d %lf %c %s", a, d, s, str);
        printf("\nOk");
        fclose(fw);
    }
    else {
        printf("\nОшибка записи в файл");
    }


    int a2;
    double d2;
    char s2;
    char str2[20];

    FILE* fr;
    errno_t err2;
    err2 = fopen_s(&fr, "data.txt", "r");

    if (!err2)
    {
        int count  = fscanf_s(fr, "%d %lf %c %s", &a2, &d2, &s2, 1, &str2, sizeof(str2));
        printf("\nДанные из файла: \na2 = %d\nd2 = %lf\ns2 = %c\nstr2 = %s", a2, d2, s2, str2);
        printf("\nКоличество считанных данных: %d", count);
        fclose(fr);
    }
    else {
        printf("\nОшибка чтения файла");
    }



#endif


#if 0

    // Запись в файл в текстовом формате, Си ----------------fopen_s--------------------

    /*
     Самостоятельно:
     Записать/считать один экземпляр структуры Студент
     в файл в текстовом формате (по полям)
    */

    Student student{ "Nikitin", "Timur", "ASEM", 5,8,10,9,3, 20,5,2000 };
    show(student);

    FILE* file;
    errno_t err;
    err = fopen_s(&file, "student.txt", "w");
    
    if (!err)
    {
        // fprintf(file, "Фамилия: %s %s %s ", student.surname, student.name, student.vuz);
        fprintf(file, "%s %s %s ", student.surname, student.name, student.vuz);
        fprintf(file, "%d %d %d", student.birthday.day, student.birthday.month, student.birthday.year);

        for (int i = 0; i < student.N; i++)
        {
            fprintf(file, " %d", student.marks[i]);
        }

        printf("\nOk");
        fclose(file);
    }
    else {
        printf("\nОшибка записи в файл");
    }

    Student student2;

    err = fopen_s(&file, "student.txt", "r");

    if (!err)
    {
        fscanf_s(file, "%s %s %s ", 
            student2.surname, sizeof(student2.surname),
            student2.name, sizeof(student2.name),
            student2.vuz, sizeof(student2.vuz)
        );

        fscanf_s(file, "%d %d %d", 
            &student2.birthday.day, 
            &student2.birthday.month, 
            &student2.birthday.year
        );

        for (int i = 0; i < student2.N; i++)
        {
            fscanf_s(file, " %d", &student2.marks[i]);
        }


        cout << endl << endl;
        printf("\nСтудент из файла: \n");
        show(student2);

        fclose(file);
    } else {
        printf("\nОшибка чтении файла");
    }



#endif

#if 0

    // Запись блоками в двоичный(бинарный) файл  ---------------------------------------------------------------------- //

    /* 
        Прототип: size_t fwrite( const void *buffer, size_t size, size_t count, FILE *stream ) 
        Функция записывает count объектов — каждый объект размером size — в поток, 
        указанный stream, из массива, указанного buf. 
        Указатель позиции в файле продвигается вперед на количество записанных элементов.
     */

    // Пример записи/чтение  структуры  в файл Студента 

    int a = 125;
    double d = a/7.;
    char str[20] = "Hello, C!";
    int arr[5]{ 25,-369,4,78,13 };
    Student student{ "Nikitin", "Timur", "ASEM", 5,8,10,9,3, 20,5,2000 };

    printf("\nd = %.15lf\n", d);

    FILE* file;
    errno_t err;
    err = fopen_s(&file, "test.txt", "wb");

    if (!err)
    {
        fwrite(&a, sizeof(a), 1, file); // Запись одной переменной целого типа
        fwrite(&d, sizeof(d), 1, file); // Запись одной переменной целого типа
        fwrite(str, sizeof(str), 1, file); // Запись одной строки
        fwrite(arr, sizeof(arr), 1, file); // Запись статического массива или --> fwrite(arr, sizeof(int), 5, file);
        fwrite(arr + 2, sizeof(int), 3, file); // Запись части статического массива начиная с элемента под индексом 2
        fwrite(&student, sizeof(student), 1, file); // Запись экзэмпляра структуры в файл

        printf("\nOk\n");
        fclose(file);
    }
    else {
        printf("\nОшибка записи в файл");
    }

    // Чтение блоками ------------------------------------------------------------ //

    int a2;
    double d2;
    char str2[20];
    int arr2[5];
    int arr3[3];
    Student s2;

    err = fopen_s(&file, "test.txt", "rb");
    if (!err)
    {
        fread(&a2, sizeof(a2), 1, file); // Чтение одной переменной целого типа
        fread(&d2, sizeof(d2), 1, file); // Чтение одной переменной целого типа
        fread(str2, sizeof(str2), 1, file); // Чтение одной переменной целого типа
        fread(arr2, sizeof(arr2), 1, file); // Чтение статического массива
        fread(arr3, sizeof(int), 3, file); // Чтение статического массива
        fread(&s2, sizeof(Student), 1, file); // Чтение экзэмпляра структуры

        fclose(file);

        printf("\na2 = %d", a2);
        printf("\nd2 = %.15lf", d2);
        printf("\nstr2 = %s\n", str2);
        
        for (int v : arr2)
        {
            printf("%d ", v);
        }

        printf("\n");

        for (int v : arr3)
        {
            printf("%d ", v);
        }

        show(s2);
    }
    else {
        printf("\nОшибка чтении файла");
    }


#endif

   
#if 1

    // Пример - копирование файлов/картинка -------------------
    // Бинарные файлы

    FILE* fr;
    errno_t err;
    err = fopen_s(&fr, "c++.jpeg", "rb");
    char s;

    if (!err)
    {
        FILE* fw;
        errno_t err2;
        err2 = fopen_s(&fw, "copy_c++.jpeg", "wb");

        if (!err2)
        {
            while (!feof(fr))
            {
                s = fgetc(fr);
                fputc(s, fw);
                printf("%c", s);

            }
            printf("\nOk");
            fclose(fw);
        }

        fclose(fr);
    }
    else {
        printf("\nОшибка открытия файла");
    }

#endif

    _getch();
}