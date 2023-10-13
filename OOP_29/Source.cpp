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
#include <list>
#include "person.h"

using namespace std;


template<class T>
void show(const list<T>& lst)
{
	for (auto it = lst.begin(); it != lst.end(); ++it)
	{
		cout << *it << "  ";
	}
	cout << endl;
}

bool decr(int a, int b) { return a > b; }

// Унарная предикатная функция
bool is_even(int a) { return a % 2 == 0; };


bool comp_age(const Person& p1, const Person& p2)
{
	return p1.get_age() < p2.get_age();
}


bool comp_surname_decr(const Person& p1, const Person& p2)
{
	return (p1 > p2);  // нужна перегрузка
}


int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));


#if 0

	// ---------------------------------------------------------------------------------------------------------------------
	// Обьявить и проинициализировать двумерный вектор

	vector<int> v = { 2, 3, 6, 9, 8 }, v2(5);
	int row = 3, col = 5;

	vector<vector<int>> arr(row, vector<int>(col));

	//vector<vector<int>>::iterator it = arr.begin();
	for (auto it_row = arr.begin(); it_row != arr.end(); it_row++)
	{
		for (auto it_col = it_row->begin(); it_col != it_row->end(); it_col++)
		{
			*it_col = rand() % 10;
			cout << *it_col << "  ";
		}
		cout << endl;
	}

	cout << endl << endl;

	// ---------------------------------------------------------------------------------------------------------------------
	// Вывести матрицу с использованием ranfe_base цикла

	for (auto value : arr)
	{
		for (auto v : value)
		{
			cout << v << "  ";
		}
		cout << endl;
	}


	cout << endl << endl;

	vector<vector<int>> arr2(row, vector<int>(col));
	for (auto& value : arr2)
	{
		for (auto& v : value)
		{
			v = rand() % 10;
			cout << v << "  ";
		}
		cout << endl;
	}

	cout << endl << endl;

	for (const auto& value : arr2)
	{
		for (const auto& v : value)
		{
			cout << v << "  ";
		}
		cout << endl;
	}

#endif


#if 1

	// Объявление и инициализация---------------------------------------------

	list<int> lt = { 12, 6, -9, 5, 34, 8, 7, 7, 11, 6, 6, 6, 5, 5 };

	for (auto x : lt)
	{
		cout << x << "  ";
	}
	cout << endl << endl;

#endif

#if 0



	//// сортировка------------------------------------------------------------
	cout << "\nСписок после сортировки по возрастанию \n";
	lt.sort();  // по возрастанию 
	show(lt);

	cout << "\nСписок после сортировки по убыванию \n";
	lt.sort(decr);  // по убыванию
	show(lt);

#endif // 0


#if 0


	// добавление элементов в начало/конец-----------------------------------
	cout << "\nдобавление элементов в начало/конец\n";
	lt.push_back(20);
	lt.push_front(5);
	show(lt);
	cout << "\nsize = " << lt.size() << endl;


#endif // 0

#if 0


	// удаление элементов: первого/последнего--------------------------------
	cout << "\nудаление элементов: первого/последнего\n";
	lt.pop_back();
	lt.pop_front();
	show(lt);
	cout << "\nsize = " << lt.size() << endl;

#endif // 0

#if 0


	// удаление последовательных дубликатов-----------------------------------
	cout << "\nудаление последовательных дубликатов\n";
	lt.unique();
	show(lt);

#endif // 0


#if 0


	// реверс-----------------------------------------------------------------
	cout << "\nreverse\n";
	lt.reverse();
	show(lt);

#endif // 0

#if 0


	// добавление элементов --------------------------------------------------
	cout << "\nдобавление элементов\n";
	auto it = lt.begin();
	++it;
	lt.insert(it, 222);  // 

	show(lt);
	cout << endl << *it << endl;// итератор смещается на следующий элемент


	//it += 3;// error

	advance(it, 3);// смещение итератора на 3 относительно текущей позиции

	cout << "\nИндекс " << distance(lt.begin(), it) << endl;


	lt.insert(it, -1000); // после добавления итератор смещается на 1
	show(lt);
	cout << endl << *it << endl;


	advance(it, -3);
	cout << endl << *it << endl;


#endif // 0

#if 0


	// удаление элементов - по итератору------------------------------------
	// после удаления итератор остается на месте удаленного элемента
	cout << "\nудаление элементов по итератору\n";
	it = lt.erase(it);
	show(lt);
	cout << endl << *it << endl;
	cout << "\nИндекс " << distance(lt.begin(), it) << endl;

#endif // 0

#if 0
	
	// удаление элементов(все элементы) - по значению--------------------------------------
	cout << "\nудаление элементов по значению\n";
	lt.remove(34);
	lt.remove(2000);  //  ничего не произошло
	show(lt);

	cout << "\nСписок нечетных значений - ( ниже мы удаляем все четные значения и оставляем нечетные)";
	lt.remove_if(is_even);
	show(lt);

#endif // 0

#if 0

	// заполнение списка несколькими одинаковыми значеними
	lt.assign(5, 10);
	show(lt);
	cout << endl << lt.size() << endl;

#endif // 0

#if 0


	// копирование списка----------------------------------------------------

	cout << "\nкопирование списка\n";
	list<int> sp;

	sp = lt;  // оператор присваивания - 1
	show(lt);

	cout << "\nкопирование части списка\n";
	list<int> sp2;
	it = lt.begin();
	advance(it, 4);
	//cout << endl << *it << endl;

	sp.assign(it, lt.end());

	show(sp);

#endif // 0

#if 0

	// очищение от всех элементов---------------------------------------------
	cout << "\nочищение от всех элементов списка\n";
	cout << "\nsize = " << lt.size() << endl;
	lt.clear();
	show(lt);
	cout << "\nsize = " << lt.size() << endl;

	auto it3 = lt.begin();
	lt.insert(it3, 200);
	show(lt);


#endif // 0


	//--------------------------------------------------------------------
#if 0

	list<string> fam = { "Иванов","Петров","Сидоров" };
	show(fam);


#endif // 0

	//--------------------------------------------------------------------
#if 0

	/*
	 Организовать список наименований товаров(string),
	 осуществить ввод данных через клавиатуру.
	 */


	list<string> tovar;
	string tmp;

	cout << "\nвведите три наименования товара \n";
	for (int i = 0; i < 3; i++)
	{
		getline(cin, tmp);
		tovar.push_back(tmp);
	}

	//show(tovar);
	cout << "\nСписок товаров:\n";
	for (auto x : tovar)
		cout << x << endl;


#endif // 0


	//--------------------------------------------------------------------
#if 1

	// В классе Person заменить MyString на string
	// Объявить список сотрудников, проинициализировать
	// на этапе разработки и вывести на экран.

	list<Person> staff = { { "Ivan", "Borisov",30,180,75 },
							{ "Semen","Akimov", 25,160,55 },
							{ "Petr", "Petrov",28,170,69 } };
	for (auto v : staff)
	{
		//cout << v;
		v.show();
		cout << endl;
	}
	//
	////Сортировка------------------------------------------
	// В классе Person обязательна перегрузка operator<
	staff.sort();


	cout << "\n---------sort by surname---------------\n";
	for (auto v : staff)
	{
		//cout << v;
		v.show();
		cout << endl;
	}


	cout << "\n----------sort by age-------------------\n";

	staff.sort(comp_age);
	for (auto v : staff)
	{
		//cout << v;
		v.show();
		cout << endl;
	}

	cout << "\n----------sort by surname decr-------------------\n";

	staff.sort(comp_surname_decr);
	for (auto v : staff)
	{
		//cout << v;
		v.show();
		cout << endl;
	}

#endif

	/* Плюсы/минусы:

	+ Вставка и удаление реализованы эффективно: изменяются только указатели.

	- Но произвольный доступ поддерживается плохо:
	чтобы прийти к определенному элементу, придется посетить все предшествующие.

	- Кроме того, в отличие от вектора, дополнительно расходуется
	память под два указателя на каждый элемент списка.

	*/

	_getch();
}


/*
Некоторые критерии для выбора одного из последовательных контейнеров:

-	если требуется произвольный доступ к элементам,
	вектор предпочтительнее;

-	если количество элементов известно заранее,
	также предпочтительнее вектор;

-	если мы должны иметь возможность вставлять и удалять
	элементы в середину, предпочтительнее список;

-	если нам не нужна возможность вставлять и удалять
	элементы в начало контейнера, вектор предпочтительнее, чем deque.

	Коротко: многократный быстрый доступ по индексу - вектор
	Почти во всех остальных случаях лучше список.
*/