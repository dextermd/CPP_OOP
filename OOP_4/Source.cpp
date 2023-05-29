#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include <string.h>
#include <algorithm>
#include <io.h>
#include <stdio.h>
#include <direct.h>

using namespace std;

//int main()
int main(int argc, char* argv[])
{



#if 0

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


#if 0

    // -------------------------------------------------------------------------------- //
    // Запись/чтение динамического массива целых в двоичный файл ---------------------- //
    // -------------------------------------------------------------------------------- //
    srand(time(0));

    int size;
    cout << "\nВведи кол-во элементов массива: ";
    cin >> size;

    int* arr = (int *)malloc(size * sizeof(int)); // Выделение динамическеого массива на Си - Вариант 1
    //int* arr = (int *)calloc(size, sizeof(int)); // Выделение динамическеого массива на Си - Вариант 2

    if (arr)
    {
        for (int i = 0; i < size; i++)
        {
            arr[i] = rand() % 21 - 10;
            printf("%d ", arr[i]);
        }
        // "..\\array.txt" // Относительно текущей папки проекта на 1 выше создает файл
        // "..\\..\\array.txt" // Относительно текущей папки проекта на 2 выше создает файл
        FILE* fw;
        errno_t err;
        err = fopen_s(&fw, "array.txt", "wb"); 
        if (!err)
        {
            fwrite(&size, sizeof(int), 1, fw); // Запись кол-ва элементов (4 байта)
            fwrite(arr, size * sizeof(int), 1, fw); // Запись данных массива в файл - Вариант 1
            //fwrite(arr, sizeof(int), size, fw); // Запись данных массива в файл - Вариант 2
            fclose(fw);
        }
        else {
            printf("\nОшибка записи в файл");
        }

        err = fopen_s(&fw, "array.txt", "rb");

        if (!err)
        {
            int size2;
            fread(&size2, sizeof(int), 1, fw); // Чтение кол-во элементов
            int* arr2 = (int*)malloc(size2 * sizeof(int)); // Выделение динамическеого массива на Си - Вариант 1
            
            if (arr2)
            {
                fread(arr2, sizeof(int), size2, fw); // Чтение  данных массива

                printf("\nМассив из файла: \n");

                for (int i = 0; i < size2; i++)
                {
                    printf("%d ", arr2[i]);
                }

                free(arr2);
            }

            fclose(fw);

        } else {
            printf("\nОшибка чтения файла");
        }
    }

    if (arr)
    {
        free(arr);
    }

#endif


#if 0
    
    // -------------------------------------------------------------------------------- //
    // Файлы - произвольный доступ ---------------------------------------------------- //
    // -------------------------------------------------------------------------------- //

    /* 
        SEEK_CUR	Current position of file pointer.
        SEEK_END	End of file.
        SEEK_SET	Beginning of file. 
    */

    char s;
    char str[100];

    FILE* file;
    errno_t err;
    err = fopen_s(&file, "test.txt", "w+");

    if (!err)
    {
        printf("\nПозиция в файле: %d", ftell(file));
        fputs("Hello, Summer!", file);
        printf("\nПозиция в файле: %d", ftell(file));
        fputs("Go go go, fff!", file);
        printf("\nПозиция в файле: %d", ftell(file));
        fputs("Gip Hop!", file);
        printf("\nПозиция в файле: %d", ftell(file));

        fseek(file, 7, SEEK_SET);
        printf("\nПозиция в файле: %d", ftell(file));

        s = fgetc(file); // Чтение одного символа
        printf("\ns = %c", s);
        printf("\nПозиция в файле: %d", ftell(file));

        fseek(file, 28, SEEK_SET);
        printf("\nПозиция в файле: %d", ftell(file));

        fgets(str, sizeof(str), file);
        printf("\nstr = %s", str);
        printf("\nПозиция в файле: %d", ftell(file));

        fseek(file, 10, SEEK_END);
        printf("\nПозиция в файле: %d", ftell(file));
        fputs("Mems!!!", file);
        printf("\nПозиция в файле: %d", ftell(file));

        fseek(file, -2, SEEK_END);
        printf("\nПозиция в файле: %d", ftell(file));

        fclose(file);
    }
    else {
        printf("\nОшибка работы с файлом");
    }

#endif // 0

    
#if 0

    // -------------------------------------------------------------------------------- //
    // Функции библиотеки io.h -------------------------------------------------------- //
    // -------------------------------------------------------------------------------- //
    
    // Прототип: int _access( const char *path, int mode )
    /*
        mode — флаги для проверки.
        00 — проверка на существование,
        02 — проверка на разрешение на запись,
        04 — проверка на разрешение на чтение,
        06 — проверка на чтение и запись.
        Если разрешение есть, функция возвращает нуль, в
        случае отсутствия –1.
    */

    //int ac = _access("array.txt", 00); // Проверка файла на существование (00)
    //int ac = _access("debug", 00); // Проверка папки на существование (00)
    int ac = _access("D:\\Projects\\OOP_4\\OOP_4\\copy.txt", 00); // Проверка файла на существование (00) (Полный путь)
    if (!ac)
    {
        cout << "\nФайл/папка существут ";

        ac = _access("copy.txt", 02);

        if (!ac)
        {
            cout << "\nЗапись разрешена!";

            FILE* fw;
            errno_t err;
            err = fopen_s(&fw, "copy.txt", "a");

            if (!err)
            {
                fputs("\n\nПривет, файл!", fw);
                fclose(fw);
            }
            else {
                cout << "\nОшибка записи в файл";
            }
        }
        else {
            cout << "\nЗапись не разрешена!";
        }
    }
    else {
        cout << "\nТакого файла или папки не существует!";
    }

#endif // 0


#if 0
    // -------------------------------------------------------------------------------- //
    // Операции по работе с файлами #include <direct.h> ------------------------------- //
    // -------------------------------------------------------------------------------- //

    int ac = _access("copy.txt", 00);

    if (!ac)
    {
        int res = rename("copy.txt", "rename_copy.txt");
        if (!res)
        {
            cout << "\nФайл переименован!";
        }
        else {
            cout << "\nФайл не переименован!";
        }
    }
    else {
        cout << "\nТакого файла или папки не существует!";
    }

#endif // 1


#if 0

    // -------------------------------------------------------------------------------- //
    // Операции по работе с файлами --------------------------------------------------- //
    // stdio.h - переименование и удаление файлов ------------------------------------- //
    // -------------------------------------------------------------------------------- //

    int ac = _access("rename_copy.txt", 00);

    if (!ac)
    {
        int res = remove("rename_copy.txt");
        if (!res)
        {
            cout << "\nФайл удален!";
        }
        else {
            cout << "\nФайл не удален!";
        }
    }
    else {
        cout << "\nТакого файла или папки не существует!";
    }

#endif // 1


#if 0

    // -------------------------------------------------------------------------------- //
    // Операции для работы с директориями  --------------------------------------------------- //
    // stdio.h - переименование и удаление файлов ------------------------------------- //
    // -------------------------------------------------------------------------------- //

    int ac = _access("rename_copy.txt", 00);

    if (!ac)
    {
        int res = remove("rename_copy.txt");
        if (!res)
        {
            cout << "\nФайл удален!";
        }
        else {
            cout << "\nФайл не удален!";
        }
    }
    else {
        cout << "\nТакого файла или папки не существует!";
    }

#endif // 1



#if 0

    // -------------------------------------------------------------------------------- //
    // Операции по работе с файлами #include <direct.h> ------------------------------- //
    // -------------------------------------------------------------------------------- //

    int res = _mkdir("TEST");
    if (!res)
    {
        cout << "\nПапка содана";
    }
    else {
        cout << "\nОшибка создание папки";
    }

    /*if (!_mkdir("D:\\test"))
    {
        cout << "\nПапка содана";
    }
    else {
        cout << "\nОшибка создание папки";
    }*/

    int r = rename("TEST","RENAME_TEST");
    if (!r)
    {
        cout << "\nПапка переименованна";
    }
    else {
        cout << "\nПапка не переименованна";
    }

    int result = _rmdir("TEST");
    if (!result)
    {
        cout << "\nПапка удалена";
    }
    else {
        cout << "\nПапка не удалена";
    }

#endif // 1


#if 0

    // -------------------------------------------------------------------------------- //
    // Функции для работы с каталогами ------------------------------------------------ //
    // -------------------------------------------------------------------------------- //

    char path[40] = "D:\\tmp\\*.*";
    char info[30];

    int ac = _access("D:\\tmp", 00);
    if (ac == 0) {

        _finddata_t f;

        char buffer[30];
        // Поиск первого файла/папки
        long done = _findfirst(path, &f);
        if (done != -1)
        {
            do {
                cout << "\nName: " << f.name;

                // Проверка - файл или папка
                f.attrib & _A_SUBDIR ? strcpy_s(info, " Папка ") : strcpy_s(info, " Файл ");
                cout << "  -  " << info;

                cout << "\nAttr read only: " << ((f.attrib & _A_RDONLY) ? " Y  " : " N  ");

                ctime_s(buffer, sizeof(buffer), &f.time_write);
                                /*
                                ctime_s
                                Преобразование значения времени в строку и
                                настройка параметров локального часового пояса.
                                */
                cout << "\nTime write: " << buffer << endl;

            } while (_findnext(done, &f) == 0); // Поиск следущих файлов/папок
        }
        _findclose(done); // освобождение ресурсов
    }
    else cout << "\nТакой директория нет";

#endif // 1


#if 0

    // -------------------------------------------------------------------------------- //
    // Использование аргументов командной строки -------------------------------------- //
    // int main(int argc, char* argv[]) ----------------------------------------------- //
    // -------------------------------------------------------------------------------- //

    cout << "Параметры командной строки: \n";

    for (int i = 0; i < argc; i++)
    {
        cout << i + 1 << ") ->  " << argv[i] << endl;
    }

    //if (strcmp(argv[1], "hello") == 0) // strcmp сравнивает стпроки есть ок то = 0;
    //{
    //    cout << "\nПривет!";
    //}
    //else {
    //    cout << "\nПока!";
    //}

#endif // 1


   
#if 1

    char str[200];

    if (argv[1] && argv[2])
    {
        FILE* fr;
        errno_t err;
        err = fopen_s(&fr, argv[1], "r");

        if (!err)
        {
            FILE* fw;
            errno_t err2;
            err2 = fopen_s(&fw, argv[2], "w");

            if (!err2)
            {
                while (!feof(fr))
                {
                    fgets(str, sizeof(str), fr);
                    fputs(str, fw);
                }

                cout << "\nКопия файла создана";

                fclose(fw);
            }
            else {
                cout << "\nОшибка записи в файл";
            }

            fclose(fr);
        }
        else {
            cout << "\nОшибка чтения файла";
        }
    }
    else {
        cout << "\nОшибка перпедачи параметров";
    }

#endif // 1




    _getch();
}