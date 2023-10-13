#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <fstream>
#include <Windows.h>
#include <array>
#include <vector>
#include <algorithm>
#include <list>
#include "Coord.h"
#include <algorithm>
#include "person.h"
#include <set>

using namespace std;


int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));

	// -------------------------------------------------------------------------------------
	// Pair

#if 0

	pair<int, int> p(2, 6);
	cout << p.first << "   " << p.second << endl;

	pair<int, double> p2(2, 3.56);
	cout << p2.first << "   " << p2.second << endl;

	Coord z(5, 9);
	pair<int, int> p3(z.get_x(), z.get_y());
	cout << p3.first << "  " << p3.second << endl;

	pair<string, Coord> psc("Point A", " 25,-25");
	cout << psc.first << "   " << psc.second << endl;

	pair<int, string> p4(2, "string");
	cout << p4.first << "  " << p4.second << endl;

	auto a = make_pair("3,-3", "point");// const char*    const char* 
	cout << a.first << "  " << a.second << endl;

	auto min_max = minmax({ 2,9,-25, 6,9, 100,36,-1 });

	cout << "\nMin: " << min_max.first;
	cout << "\nMax: " << min_max.second;


#endif 

#if 0

	Person _person("Ivan", "Borisov", 30, 180, 75);

	list<Coord> lc;

	lc.push_back("2,9");
	lc.push_back("-10,3");
	lc.push_back({ 5,6 });

	pair < Person, list<Coord>> pl{ _person, lc };

	cout << "\nПара Person и список коодинат: \n";
	pl.first.show();

	cout << " \nКоординаты :  ";
	for (auto& v : pl.second)
	{
		//v.show();
		cout << v;
	}

#endif 

#if 0

	Person _person("Ivan", "Borisov", 30, 180, 75);

	list<Coord> lc;
	lc.push_back("2,9");
	lc.push_back("-10,3");
	lc.push_back({ 5,6 });

	pair < Person, list<Coord>> plst{ _person, lc };

	pair<string, vector<int>> p9("Chisinau", { 2010,2015,2018,2021 });

	pair< pair <Person, list<Coord>>, pair<string, vector<int>>> ppp(plst, p9);

	ppp.first.first.show();
	cout << "\nКординаты: ";
	for (const auto& value : ppp.first.second)
	{
		cout << value << "  ";
	}

	cout << endl << ppp.second.first;

	for (const auto& value : ppp.second.second)
	{
		cout  << " " << value << " ";
	}

#endif 

	// -------------------------------------------------------------------------------------
	// set (множество)

#if 1

	// -------------------------------------------------------------------------------------
	// set (множество)

	set<int> st;    // Только уникалные значения
	//multiset<int> st; // Позволяет повторение элементов
	for (int i = 5; i > 0; i--)
	{
		st.insert(i);
	}

	for (int i = 8; i > 0; i--)
	{
		st.insert(i);
	}


	for (auto value : st)
	{
		cout << value << " "; // 1 2 3 4 5
	}

	cout << "\nSize: " << st.size() << endl;
	cout << "Max size: " << st.max_size() << endl;

#endif








	_getch();
}

