#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <fstream>
#include <Windows.h>
#include <array>
#include <vector>
#include <algorithm>
#include "string_to_b_file.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");

	// КОНТЕЙНЕРЫ   https://ru.cppreference.com/w/cpp/container

/*
	Последовательные контейнеры:
	- array   (статический непрерывный массив )
	- vector  (C-подобный динамический массив)
	- list    (Двусвязный список)
	- forward_list (односвязный список)
	- deque (Двусвязная очередь  — структура данных,
		   в которой элементы можно
		   добавлять и удалять как в начало, так и в конец.
		   Может быть реализована при помощи двусвязного списка).


	Контейнеры адаптеры
	- stack   (LIFO: last-in first-out)
	- queue   (FIFO: first-in first-out)
	- priority_queue
*/

//---------------------------------ARRAY-------------------------------
#if 0

	array<int, 5> a1{ 15, -2, 4 };
	array<int, 3> a2 = { 1, 2, 3 };

	array<string, 3> a3 = { { "Ivanov", string("Sidorov"), "Petrov" } };

	// Вывод 1
	for (int i = 0; i < a1.size(); i++)
	{
		cout << a1[i] << "  ";
	}
	cout << endl;

	// Вывод 2
	// поддерживается  range-based цикл
	for (const auto& v : a2)
		cout << v << "  ";

	cout << endl << endl;

	// Вывод 3
	array<string, 3>::iterator it;
	for (/*auto*/ it = a3.begin(); it != a3.end(); ++it)
		cout << *it << "  ";


	/*array<int, 3> a4;
	cout << "\nВведите данные массива: \n";
	for ( auto & v : a4)
	{
		cin >> v;
	}

	for (auto v : a4)
		cout << v << "  ";
	cout << endl << endl;*/

	array<string, 3> a5;
	a5.fill("abc");
	for (const auto& v : a5)
		cout << v << "  ";

	cout << endl << endl;

#endif // 0

	//---------------------------------VECTOR-------------------------------
	// Объявляем вектор  целых.

#if 0

	vector <int> v1;								// конструктор 1
	vector <int> v2(5);							// конструктор 2   
	vector <int> v2_1(5, 8);						// конструктор 2_1 
	vector <int> v3(v2);							// конструктор 3

	int a[] = { 32, 71, -12, 45, 3, 80, 53, 33 };
	vector<int> v4(a, a + 8);						// конструктор 4

	vector <int> v5{ 25, -35, 9, -3, 55, -18, 75 };	// конструктор 5

	initializer_list<int> lst{ 1, 10, 100 };
	vector <int> v6(lst);							// конструктор 6


	// Отображение вектора на экране------------------------------------------
	// Вывод 1----------------------------------------------------------------
	for (int i = 0; i < v2_1.size(); i++)
	{
		cout << v2_1[i] << "  ";
	}
	cout << endl;

	//// Вывод 2----------------------------------------------------------------
	vector<int>::iterator p;

	for (p = v5.begin(); p != v5.end(); ++p)
	{
		cout << *p << "   ";
	}
	cout << endl;

	// Вывод 3 reverse_iterator------------------------------------------------
	vector <int>::reverse_iterator pr;
	for (auto pr = v4.rbegin(); pr < v4.rend(); pr++)	// можно без объявления итератора использовать auto 
	{
		cout << *pr << "   ";
	}
	cout << endl;



	// Вывод 4 range-based цикл------------------------------------------------ 
	for (auto x : v4)
	{
		x *= 2;  // при передаче auto  x по ссылке не меняются значения массива
		cout << x << ", ";
	}
	cout << endl;

	for (auto x : v4)
	{
		cout << x << ", ";
	}
	cout << endl;


	//  Изменение данных вектора в range-based цикл-------------------------------
	for (auto& x : v4)
	{
		x *= 2;
		cout << x << ", ";
	}
	cout << endl;


	// Пользовательская функция-------------------------------------------------
	show(v5);


#endif // 0

	// Доступ к элементу(способы)-----------------------------------------------
#if 0


	vector <int> v5{ 25, -35, 9, -3, 55, -18, 75 };
	//vector <int>::iterator it;
	auto it = v5.begin();
	cout << *it << endl;  // первое значение вектора
	++it;  // переход на второе значение вектора
	cout << *it << endl;

	/*it += 3;
	cout << *it << endl;*/

	advance(it, 3); // смещение итератора
	cout << *it << endl;

	cout << v5[3] << "  =  " << v5.at(3) << "  =  " << *it << endl;
	cout << v5.front() << "   " << v5.back() << "   " << v5.data() << endl;

	int* ptr = v5.data();  //- адрес вектора
	cout << ptr << "  " << *ptr;

#endif // 0

	// Размеры вектора----------------------------------------------------------
#if 0

	vector <int> v{ 25, -35, 9, -3, 55, 10, 75 }, vv(10);
	show(v);
	cout << "\nsize v: " << v.size() << endl;
	cout << "\ncapacity v: " << v.capacity() << endl;

	cout << "\nsize vv: " << vv.size() << endl;
	cout << "\ncapacity vv: " << vv.capacity() << endl;

	v.resize(v.size() * 2);   // увеличить/уменьшить размер вектора
	show(v);
	cout << "\nsize*2: " << v.size() << endl;

	v.reserve(50);
	cout << "\ncapacity=50: " << v.capacity() << endl;

	v.clear();
	show(v);
	cout << "\nclear: " << v.size() << endl;
	cout << "\ncapacity after clear: " << v.capacity() << endl;


	//очищение памяти

	v.shrink_to_fit();
	cout << "\ncapacity after shrink_to_fit: " << v.capacity();
	cout << "\nsize: " << v.size() << endl;

#endif // 0

	// метод assign------------------------------------------------------------
#if 0

	vector <int> v{ 25, -35 };
	vector <int> vec;
	show(vec);
	cout << "\nsize = " << vec.size() << endl;
	vec = v;                   //перегрузка =
	show(vec);
	cout << "\nsize = " << vec.size();

	vector <int> v5{ 25, -35, 9, -3, 55, -18, 75 };	// конструктор 5
	show(v5);

	v5.assign(5, 10);  //   записывает в вектор 5 значений 10
	show(v5);
	cout << "\nsize v5: " << v5.size() << endl;

	array<int, 10> a1{ 15, -2, 4, 6, 8, 10, -12, 7, 45 };
	v5.assign(a1.begin() + 2, a1.end());
	show(v5);
	cout << "\nsize v5: " << v5.size() << endl;

	v5.assign({ 2,9,10 });
	show(v5);
	cout << "\nsize v5: " << v5.size() << endl;


#endif // 0	

#if 0
	// Добавление элементов-------------------------------------------------------

	vector <int> k(5);
	show(k);
	cout << endl << "\nsize: " << k.size() << "\n";

	//// 1. Добавление элементов в конец----------------------------------------------- 

	k.push_back(22);
	k.push_back(11);
	k.push_back(4);

	cout << endl << "\nsize: " << k.size() << "\n";
	k[0] = 25;
	show(k);


	////// 2. Добавление элементов по позиции итератора/индексу-------------------------

	auto it = k.begin();
	//добавляет 255 в начало(перед указанным положением итератора)
	it = k.insert(it, 255);
	show(k);
	cout << *it << endl;
	it += 4;
	it = k.insert(it, 10000);
	show(k);
	cout << *it << endl;
	it = k.insert(it, -100);
	show(k);


	it = k.begin();
	it = k.insert(it + 2, -39);    //добавляет -39 по индексу 2
	show(k);
	// итератор остается в месте добавления нового значения


	// добавляет четыре значения 10 перед -39(текущим положением итератора)
	it = k.insert(it, 4, 10);
	show(k);


	//// добавляет 300  перед первым значение 10(текущим положением итератора)
	it = k.insert(it, 300);
	show(k);


	it += 3; // смещение итератора
	//// добавляет 555 после второго значения 10
	it = k.insert(it, 555);
	show(k);

	//


	//// 3. Добавление нескольких значений другого вектора---------------------------
	//show(k);
	cout << endl << endl;
	vector <int> v5{ 25, -35, 9, -3, 55, -18, 75 };	// конструктор 5
	show(v5);



	auto iter = v5.begin(); // v5
	//
	it = k.insert(k.begin(), iter + 3, iter + 6);

	//// iter+6 -  не включается
	cout << endl << endl;
	show(k);
	//
	//
	//
	//// Добавление в начало вектора k первых четырех элементов массива mas

	int mas[] = { 1, 2 , 3, 4, 5, 6, 7 };
	auto it2 = k.insert(k.begin(), mas, mas + 4);
	show(k);

	initializer_list<int> la{ 1, 10, 100 };
	it = k.insert(k.end(), la);
	show(k);


#endif // 0

	// Удаление элементов--------------------------------------------------------
#if 0

	// 1. Удаление с конца 
	vector <int> v5{ 25, -35, 9, -3, 55, -18, 75 };	// конструктор 5
	show(v5);
	v5.pop_back();
	show(v5);


	//// 2. Удаление по позиции
	v5.erase(v5.begin());
	show(v5);
	v5.erase(v5.begin() + 1, v5.begin() + 3);// по диапазону, последний не включительно
	show(v5);


#endif // 0

#if 0
	// Обмен значениями двух векторов - swap------------------------------------

	vector <int> v2;
	v2.push_back(2);
	v2.push_back(-300);
	v2.push_back(4);
	v2.push_back(-50);
	v2.push_back(1);
	v2.push_back(-1231);
	v2.push_back(1500);
	v2.push_back(3);
	cout << "\nv2: ";
	show(v2);

	vector <int> v5{ 25, -35, 199, -3, 55, -18, 75 };
	cout << "\nv2: ";
	show(v5);


	cout << "\nОбмен двух векторов:\n";

	v5.swap(v2);
	cout << "\nv2: ";
	show(v2);
	cout << "\nv2: ";
	show(v5);



	// Сортировка - алгоритм-------------------------------------------------------
	// #include <algorithm> // подключение библиотеки алгоритмов
	cout << "\n\nВектор до сортировки: ";
	show(v5);


	// сравнение по умолчанию (operator <)
	// сортировка первых 5-ти элементов
	/*cout << "\nВектор после сортировки по возрастанию(все значания) : ";
	sort(v5.begin(), v5.end());
	show(v5);*/


	// надо закомментировать сортировку выше
	cout << "\nВектор после сортировки  по возрастанию(диапазона от v5[2] до предпоследнего элемента ): \n";
	sort(v5.begin() + 2, v5.end() - 1);
	show(v5);




	// для сравнения - пользовательская функция mycompare(третий параметр)
	cout << "\nВектор после сортировки по убыванию: ";
	cout << endl;
	sort(v5.begin(), v5.end(), mycompare);
	show(v5);

#endif // 0

	//-----------------------vector coord--------------------------------------
#if 0

	vector<Coord> vc{ {250, -35}, { 9,-3 }, Coord(55, -18), "75,0" };

	//for (auto & x : vc)
	for (Coord& x : vc)
	{
		//cout << x << "    ";
		x.show();
	}
	cout << endl;


	// Сортировка вектора координат
	cout << "\nВектор координат после сортировки(по возрастанию суммы координат):\n ";
	sort(vc.begin(), vc.end()); // <
	show(vc);


	cout << "\nВектор координат после сортировки(по убыванию суммы координат): ";
	sort(vc.begin(), vc.end(), coord_compare);//coord_compare - критерий сортировки
	show(vc);

#endif // 0

#if 0


	//--------------------------------------------------------------------------------
	// Создание вектора - массива строк и применение алгоритма сортировки-------------

	////вариант 1 - инициализации
	/*	vector<string> vecstr{ "Кишинев", "Тирасполь","Унгены","Бельцы","Бендеры","Каменка" };
		show(vecstr);*/

		//вариант 2 - инициализации
		//// или
	string mas[6] = { "Кишинев", "Тирасполь","Унгены","Бельцы","Бендеры","Каменка" };
	vector<string> vecstr;
	vecstr.assign(mas, mas + 5);

	show(vecstr);

	for (int i = 0; i < vecstr.size(); i++)
		cout << vecstr[i] << endl;
	cout << endl;


	//

	//// алгоритм sort--------------------------------------------------------------------

	sort(vecstr.begin(), vecstr.end());
	show(vecstr);

	sort(vecstr.begin(), vecstr.end(), mycompstr);
	show(vecstr);
	sort(vecstr.begin(), vecstr.end(), mycompstr2);

	for (int i = 0; i < vecstr.size(); i++)
		cout << vecstr[i] << endl;
	cout << endl;


#endif // 0

	//-------------------------------------------------------------------------------
	/*
		Запись/чтение в файл при помощи:  методов  write / read в бинарный файл.
	*/
#if 0
	vector<int> v{ 25, -35, 9, -3, 55, -18, 75 };

	for (auto x : v)
	{
		cout << x << ",  ";
	}
	cout << "\nsize v: " << v.size() << endl;

	cout << endl << endl;


#endif 

#if 0

    //==========================================================================================
    //Запись строки в текстовый файл

    string st("Строка для записи в файл"), tmp;
    cout << st << endl;
    cout << "\nСтрока для записи (длина, размер): " << st.length() << " " << st.size() << endl;
    cout << "\nСтрока для чтения (длина, размер): " << tmp.length() << " " << st.size() << endl;

    ofstream fout("str.txt");
    if (fout)
    {
        fout << st;
        fout.close();
    }
    else cout << "error";


    //-------------------------------------------------------------------------------------------
    //Чтение чтроки из текстового файла 


    ifstream fin("str.txt");
    if (fin)
    {
        //fin >> tmp;
        //getline(fin, tmp);
         
        tmp.resize(256);
        //fin.getline((char*)tmp.c_str(), tmp.length());
        fin.getline(const_cast<char*>(tmp.c_str()), tmp.length());
        cout << "\nСтрока из файла: " << tmp;
        fin.close();
    }
    else cout << "error";

#endif

#if 0
    //==========================================================================================
    //Запись строки в бинарный файл

    string st("Кот на кухне - жди скандала! Колбоса у нас пропала!"), tmp;
    cout << st << endl;
    cout << "\nСтрока для записи (длина, размер): " << st.length() << " " << st.size() << endl;
    cout << "\nСтрока для чтения (длина, размер): " << tmp.length() << " " << st.size() << endl;

    ofstream fout("str_bin.txt", ios::binary);
    if (fout)
    {
        int len = st.length();
        fout.write((const char*)&len, sizeof(st.length()));
        fout.write(st.c_str(), st.length());
        fout.close();
    }
    else cout << "error";


    //-------------------------------------------------------------------------------------------
    //Чтение чтроки из текстового файла 
 
    ifstream fin("str_bin.txt", ios::binary);
    if (fin)
    {
        int len;
        fin.read((char*)& len, sizeof(int));
        tmp.resize(len);
        fin.read(const_cast<char*>(tmp.c_str()), len);
        fin.close();
    }
    else cout << "error";

    cout << endl << tmp << endl;

#endif

#if 0
    //==========================================================================================
    //Запись строки в бинарный файл

    string st("Кот на кухне - жди скандала! Колбоса у нас пропала!"), tmp;
    cout << st << endl;
    cout << "\nСтрока для записи (длина, размер): " << st.length() << " " << st.size() << endl;
    cout << "\nСтрока для чтения (длина, размер): " << tmp.length() << " " << st.size() << endl;

    ofstream fout("str_bin.txt", ios::binary);
    if (fout)
    {
        fout << st; // глобальная перегрузка  #include "string_to_b_file.h"
        fout.close();
    }
    else cout << "error";


    //-------------------------------------------------------------------------------------------
    //Чтение чтроки из текстового файла 

    ifstream fin("str_bin.txt", ios::binary);
    if (fin)
    {
        fin >> tmp; // глобальная перегрузка  #include "string_to_b_file.h"
        fin.close();
    }
    else cout << "error";

    cout << endl << tmp << endl;

#endif
    _getch();
}