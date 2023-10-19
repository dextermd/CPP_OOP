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
#include "Dictionary.h"
#include "DictionaryMenu.h"
#include "FrequencyDictionary.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	//setlocale(LC_ALL, "ru_RU.utf8");

#if 0
	// Задание 1.
	//Dictionary dict, dict_file;
	//dict.add("apple", "яблоко", "un mar");
	//dict.add("orange", "апельсин", "tabelul");
	//dict.add("pear", "груша", "para");
	//dict.add("table", "стол", "tabelul");
	//dict.add("window", "окно", "fereastra");
	//dict.show();
	//dict.remove("orange2");
	//dict.show();
	//dict.find_by_key("table");
	//dict.edit("orange", "апельсин_e", "tabelul_e");
	//dict.show();
	//dict.save_data_to_file();
	//dict_file.read_data_from_file();
	//cout << "\nFrom_File\n";
	//dict_file.show();

	Dictionary dict;
	dict.read_data_from_file();
	show_menu(1);
	init_menu(dict);

#endif

#if 1
	// Задание 2.
	FrequencyDictionary fd("input.txt");
	fd.show();
	fd.show_max();
	fd.save_data_to_file();

#endif



	_getch();
}