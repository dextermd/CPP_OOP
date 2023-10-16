#include <iostream>
#include <conio.h>
#include "coord.h"
#include "person.h"
#include<iomanip>
#include <map>
#include <set>
#include <vector>
#include "Coord.h"

using namespace std;
//------------------------------------------------------------------------

// Бинарная Предикатная функция , т.е. принимает два параметра и возвращает bool
bool comp(const string& a, const string& b)
{
	return a > b;
}

//------------------------------------------------------------------------
// Предикат - это структура или класс, в которой есть перегрузка operator() 
// с возвращением bool
struct Compare {

	bool operator()(const string& a, const string& b)const
	{
		return a > b;
	}
};

//------------------------------------------------------------------------
bool cmp_person(const Person& a, const Person& b)
{
	return a.get_surname() > b.get_surname();
}

//------------------------------------------------------------------------
struct CmpPerson {

	bool operator()(const Person& a, const Person& b)const
	{
		return a.get_surname() > b.get_surname();
	}
};
//------------------------------------------------------------------------


int main()
{
	system("chcp 1251>nul");
	system("color 1F");

	/*
	Ассоциативные контейнеры:

	- map     (отображение, карта)
		Похож на set, но значения хранятся в виде std::pair
		Ключ - pair.first, значение - pair.second
		Поддерживает прямой доступ по ключу - at() и []
		Удобно, когда цифровой ключ не подходит, а нужен строковый или объетный.

	- multimap
		Аналогичен multiset
		Не поддерживает прямой доступ по ключу
*/

//Отображение - map-------------------------------------------------------
/*
Примеры использования:
- Русско-англ. словарь. Ключ -русское слово, значение — английский перевод
- Прайс лист. Ключ - Наименование товара, значение — цена товара
- Квартира. Ключ - Номер, значение - количество жителей или список жителей.
*/

#if 0

	map<int, int> m;
	cout << m.size() << endl;

	//m.insert(2, -2);// error

	m.insert(pair<int, int>(2, -2));
	m.emplace(10, 6);
	m.insert(make_pair(5, 50));
	m.emplace(-10, 6);

	m[-5] = 500;
	m[3];

	m.at(10) = 100;//+ exception   значение по ключу менятеся
	m[10] = 50;// значение по ключу менятеся

	m.emplace(10, 1000);// значение по ключу не менятеся
	m.emplace(1, 1000);

	for (auto v : m)
	{
		cout << v.first << "  " << v.second << endl;
	}

	cout << "Количество значений по ключу: " << m.count(10) << endl;
	cout << "Количество значений по ключу: " << m.count(300) << endl;



#endif


	// добавление элементов: []----------------------------------------------
#if 0

	cout << m[-5] << endl;// 0

	cout << m[100] << endl << endl;// по ключу 100 записывается 0

	m[50];// по ключу 50 записывается 0

	m[45] = 200;
	m[45] = 400;// ключ уникален, значение переписывается
	m.at(45) = 100;

	auto r = m.emplace(7, 500);// ключ уникален, значение не меняется

	if (r.second)
	{
		cout << "\nЗначение добавлено\n";
	}
	else {
		cout << "\nЗначение не добавлено\n";
	}
	// Проход по элементам map      ---------------------------------------
	for (auto v : m)
	{
		cout << v.first << "  " << v.second << endl;
	}



#endif // 0

#if 0


	/*auto*/map<int, int>::iterator it = m.begin();

	cout << endl << it->first << "  " << (*it).second << endl;
	++it;
	cout << endl << it->first << "  " << (*it).second << endl;
	//it += 3;//error
	advance(it, 3);
	cout << endl << it->first << "  " << it->second << endl;

	cout << "\nsize: " << m.size() << endl << endl;

	// Проход по элементам map      ---------------------------------------
	for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
	{
		cout << it->first << "  " << (*it).second << endl;
	}

	//  Количество элементов с ключом: count---------------------------------
	cout << "\nКоличество элементов с ключом -5:  " << m.count(-5);
	cout << "\nКоличество элементов с ключом 150:  " << m.count(150);

#endif // 0


	// Поиск значения по ключу: find------------------------------------------
#if 0


	it = m.find(3);

	if (it != m.end())
	{
		cout << "\nРезультат поиска: " << it->first << "  " << it->second;
		cout << "\nПозиция(индекс): " << distance(m.begin(), it) << endl;
	}
	else {
		cout << "\nЭлемент не найден";
		// Последний элемент
		--it;
		cout << "\n" << it->first << "  " << it->second;
	}

#endif // 0

	//-----------------------------------------------------------------------
	// Удаление элементов из map

	// Удаление одного элемента из map по ключу ---------------------------
#if 0

	cout << "\nУдаление------------------\n";
	cout << m.erase(45) << endl;


	if (m.count(-5))
	{
		cout << "\nЭлемент удален: " << m.erase(-5) << endl; // Удаление по значению
	}
	else {
		cout << "\nЭлемента нет в map\n";
	}

	for (auto v : m)
	{
		cout << v.first << "  " << v.second << endl;
	}


	it = m.find(10);
	if (it != m.end())
	{
		it = m.erase(it);// Удаление по итератору

		if (it != m.end()) {
			cout << "\nЭлемент удален, положение итератора:  " << (*it).first << endl;
			cout << "\nПозиция(индекс): " << distance(m.begin(), it) << endl;// на следующем элементе
		}
	}
	else {
		cout << "\nЭлемента нет в map";
	}


	cout << endl << endl;
	for (auto v : m)
	{
		cout << v.first << "  " << v.second << endl;
	}

#endif // 0


	//-----------------------------------------------------------------------
	//Самостоятельно:  Удалить пары с четными ключами в map------------------


#if 0
	map<int, int> m;

	m.insert(pair<int, int>(10, 15));
	m.emplace(-5, 5);
	m.emplace(4, 5);
	m.insert(make_pair(-25, 16));
	m[20] = 358;
	m[24] = 12;
	m[31];
	m[7] = 300;
	m[26] = 15;
	m[-30] = 1;
	m[200];
	m[-40] = 5;
	m[240] = 5;

	for (const auto& v : m)
	{
		cout << v.first << "  " << v.second << endl;
	}

	for (auto it = m.begin(); it != m.end(); /*++it*/)
	{
		if (!(it->first % 2))
		{
			it = m.erase(it);// 
		}
		else {
			++it;
		}
	}


	cout << "\nmap после удаления пар с четными ключами: \n";
	for (const auto& v : m)
	{
		cout << v.first << "  " << v.second << endl;
	}



	//int a = 10;
	//int* p = &a;

	////int c = ++(* p)  - (* p)++ / 2 + a;// 11-5+11=17
	////cout << "\nc = "<< c << endl;

	//a = (*p)++ - (*p)++ / 2 + a;// 10-5+10=15
	//cout << "\na = " << a << endl;



#endif // 0

	//-----------------------------------------------------------------------
	// Удаление нескольких элементов из map по границам----------------------
	/*
		lower_bound(key) - итератор на первый элемент, чей ключ больше или равен указанному ключу;
		upper_bound(key) - итератор на первый элемент, чей ключ больше указанного ключа;
		(key должен быть меньше значения последнего элемента)
	*/
#if 0

	map<int, int> m;

	m.insert(pair<int, int>(10, 15));
	m.emplace(-5, 5);
	m.emplace(4, 5);
	m.insert(make_pair(-25, 16));
	m[20] = 358;
	m[24] = 12;
	m[31];
	m[7] = 300;
	m[26] = 15;
	m[-30] = 1;
	m[200];//  

	for (const auto& v : m)
	{
		cout << v.first << "  " << v.second << endl;
	}

	auto lm = m.lower_bound(5);
	cout << "\nlm = " << lm->first << "  " << lm->second << endl;

	//auto um = m.upper_bound(200); //! key должен быть меньше значения последнего элемента)
	auto um = m.upper_bound(24);
	cout << "\num = " << um->first << "  " << um->second << endl;

	m.erase(lm, um);

	cout << "\nmap после удаления по границам: \n";
	for (const auto& v : m)
	{
		cout << v.first << "  " << v.second << endl;
	}


#endif // 0

	//-----------------------------------------------------------------------
	// Копирование map
#if 0


	map<int, int> m;
	map<int, int> m2;

	m.insert(pair<int, int>(10, 15));
	m.emplace(-5, 5);
	m.emplace(4, 5);
	m.insert(make_pair(-25, 16));
	m[20] = 358;
	m[24] = 12;
	m[31];
	m[7] = 300;
	m[26] = 15;
	m[-30] = 1;
	m[200];//  

	for (const auto& v : m)
	{
		cout << v.first << "  " << v.second << endl;
	}

	m2 = m; // Вариант 1 operator=
	cout << endl;
	for (const auto& v : m2)
	{
		cout << v.first << "  " << v.second << endl;
	}

	//auto i1 = m.begin();
	//auto i2 = m.begin();
	//advance(i1, 3);
	//advance(i2, 7);// не влючая

	//map<int, int>m3(i1,i2);
	//cout << endl<< endl << endl;
	//for (const auto& v : m3)
	//{
	//	cout << v.first << "  " << v.second << endl;
	//}



	//auto lb = m.lower_bound(3);
	//auto ub = m.upper_bound(24);// включительно

	//map<int, int> m4(lb, ub);

	//cout << endl << endl << endl;
	//for (const auto& v : m4)
	//{
	//	cout << v.first << "  " << v.second << endl;
	//}

#endif // 0

	//-----------------------------------------------------------------------
	// Пример: Справочник телефонных номеров----------------------------------



	// Вариант 1 - в алфавитном порядке, по умолчанию------------------------


#if 0
	map<  string, string  > mt{ {"Катя", "069874213"}, { "Саша","069325987" } };

	mt["Алла"] = "079654789";
	mt["Валя"] = "060654189";
	mt["Валя"] = "079888888";// значение заменится
	mt["Ирина"] = "079654111";
	mt["Марина"] = "068654789";

	mt.emplace("Денис", "060457895");// значение не заменится
	mt.emplace("Денис", "062222222");

	cout << "\nСправочник телефонов:\n";
	for (auto v : mt)
	{
		cout << v.first << "  " << v.second << endl;
	}
	cout << endl << endl;
#endif


	// Вариант 2 - в обратном алфавитном порядке по предикату -----------------

#if 0

		//bool (*)(const string&, const string&) - указатель на предикатную функцию - v1

		//map<   string, string, bool (*)(const string&, const string&)   > mt(comp);

	map<string, string, Compare> mt;//compare - объект - предикат  v2

	mt.emplace("Катя", "069874213");
	mt.emplace("Саша", "069325987");

	mt["Алла"] = "079654789";
	mt["Валя"] = "060654189";
	mt["Валя"] = "079888888";// значение заменится
	mt["Ирина"] = "079654111";
	mt["Марина"] = "068654789";

	mt.emplace("Денис", "060457895");// значение не заменится
	mt.emplace("Денис", "062222222");

	cout << "\nСправочник телефонов:\n";
	for (auto v : mt)
	{
		cout << v.first << "  " << v.second << endl;
	}

#endif // 0

	//--------------------------------------------------------------------
	//Самостоятельно: 

	/*
	Используя контейнер map реализовать словарь на двух / трех языках,
	ключ – английское слово и пара значений – перевод на два языка.

	Объявить map, проинициализировать на этапе разработки,
	вывести на экран.

	Добавить возможность ввода данных с клавиатуры.
	*/


#if 0

	map<string, pair<string, string>> voc;

	voc.emplace("груша", make_pair("pear", "pere"));
	voc.emplace("яблоко", pair<string, string>("apple", "mar"));
	voc.emplace("апельсин", make_pair("orange", "portocala"));
	cout << endl;

	for (auto v : voc)
	{
		cout << left << setw(15) << v.first << setw(15) << v.second.first
			<< setw(15) << v.second.second << endl;
	}


#endif // 0

	//--------------------------------------------------------------------
	/*
	 Задача: Что выполнит код?
	 Количество повторений значений вектора - частотный словарь
	*/
#if 0

	vector<int> v{ 25, -9, 25, 9, 5, 7, 8, 5, 25, 3, 25, 9, 7, 7, 7, 25, 9 };
	map<int, int> count;

	for (auto x : v)
	{
		cout << x << "  ";
		count[x]++;
	}

	cout << endl;

	count[10];//0
	count[10]++;//1
	count[10]++;//2
	count[25]++;//6
	for (auto v : count)
	{
		cout << v.first << "\t" << v.second << endl;
	}


#endif // 0

	//--------------------------------------------------------------------
	// Создание map со значением и ключом типа пользовательского класса
	// В пользовательском классе для ключа обязательно перегрузить операцию <.
#if 0

	// Задача: Создать map с парой Person(ключ) и coord.
	{
		map<Person, Coord> mp;

		Person a("Ivanov", "Ivan", 20, 180, 75);
		Person b("Borisov", "Anton", 18, 170, 65);
		Person c("Aromov", "Alex", 25, 175, 65);

		mp[a] = Coord(25, 9);
		mp[b] = { -5,9 };
		mp[c] = "12,6";

		mp.emplace(make_pair(Person("Domov", "Alex", 21, 175, 65), Coord(2, -3)));

		for (auto v : mp)
		{
			v.first.show();
			cout << " -> " << v.second << endl;
		}
	}

#endif
	//-----------------------------------------------
	//Вариант 2 (в обратном алфавитном порядке)
#if 0
	// ключ должен быть уникальным

	{
		//map<Person, Coord, bool(*)(const Person&, const Person&)> mp(cmp_person);    // cmp_person - предикатная функция
		map<Person, Coord, CmpPerson> mp;//cmpPerson - предикат


		Person a("Ivanov", "Ivan", 20, 180, 75);
		Person b("Borisov", "Anton", 18, 170, 65);
		Person c("Aromov", "Alex", 25, 175, 65);

		mp[a] = Coord(25, 9);
		mp[b] = { -5,9 };
		mp[c] = "25,-25";

		mp.emplace(make_pair(Person("Domov", "Alex", 21, 175, 65), Coord(2, -3)));
		cout << endl << "============================" << endl;
		for (auto v : mp)
		{
			v.first.show();
			cout << " -> " << v.second << endl;
		}
	}
#endif // 0

	//-----------------------------------------------
	/* Примечание:

	Существуют три ограничения на тип элементов контейнера
	(практически это касается только пользовательских классов).
	Для  них  должны быть определены:
		-	операция =
		-	операция <
		-	значение по умолчанию
			(для класса это означает наличие конструктора по умолчанию).
	*/


	//-----------------------------------------------------------------------
	// Пример: Справочник столиц---------------------------------------------
#if 0

	map <string, string> Capitals;
	string country, city;

	Capitals["Russia"] = "Moscow";
	Capitals["Ukraine"] = "Kiev";
	Capitals["USA"] = "Washington";

	cout << "В какой стране вы живете? ";
	getline(cin, country);
	//cin >> country;

	// Проверим, есть ли такая страна в словаре Capitals
	if (Capitals.count(country))
	{
		// Если есть - выведем ее столицу
		cout << "Столица вашей страны " << Capitals[country] << endl;
	}
	else
	{
		// Запросим название столицы и добавив его в словарь
		cout << "Как называется столица вашей страны? ";
		cin >> city;
		Capitals[country] = city;
	}
	cout << endl;

	for (auto it = Capitals.begin(); it != Capitals.end(); ++it) {
		cout << setw(10) << left << "\nСтрана:" << setw(12)
			<< (*it).first << setw(10) << "- Столица: " << setw(12)
			<< it->second;
	}


#endif // 0
	//===============================================================
	// multimap
#if 1


	multimap<string, int> mlt;
	mlt.insert(pair<string, int>("Иванов", 20));
	mlt.insert(pair<string, int>("Петров", 23));
	mlt.insert(pair<string, int>("Сидоров", 18));
	mlt.insert(pair<string, int>("Петров", 21));
	mlt.insert(pair<string, int>("Петров", 51));

	mlt.emplace("Зайцев", 15);
	// mlt.insert("Зайцев", 15); //  error
	mlt.insert(pair<string, int>("Зайцев", 45));

	cout << endl;

	for (auto x : mlt)
	{
		cout << x.first << "    " << x.second << endl;
	}
	cout << endl;

	cout << "\nНаличие значения(по ключу): " << mlt.count("Петров") << endl;

	// Найти и вывести все телевоны по ключу "Петров"
	// Получаем все элементы с ключом 

	auto pr = mlt.equal_range("Петров");

	if (pr.first != pr.second) {
		for (auto it = pr.first; it != pr.second; ++it) {
			cout << it->first << "->" << it->second << endl;
		}
	}
	else {
		cout << "\nЭлементы не найдены";
	}

#endif // 0
	_getch();
	return 0;
}

//===============================================================
/* Плюсы/минусы:

map состоит из пар ключ/значение, причем ключ используется для поиска элемента,
а значение содержит хранимую информацию (например, Телефонный справочник)

+ Этот класс предназначен для быстрого поиска значения по ключу.
		Быстрый поиск значения по ключу осуществляется благодаря тому,
		что пары хранятся в отсортированном виде.

- Недостаток — скорость вставки новой пары обратно
  пропорциональна количеству элементов, сохраненных в классе.

- Ключ должен быть уникальным.

*/