#pragma once
#include <iostream>
#include <string>
#include <set>
#include "Ticket.h"

using namespace std;

class GaiData
{
public:
	set<Ticket> data;

	GaiData() {};
	GaiData(Ticket& data);

	const void show() const;
	void add();
	void add(Ticket& data);
	const void show_by_number(string& number) const;

	const void save_data_to_file();
	const void save_data_from_user() const;
	const void read_data_from_file();


	// Перегрузка потока записи в файл <<
	friend std::ostream& operator<<(std::ofstream& out, GaiData& obj);
	// Перегрузка потока чтении из файла >>
	friend std::istream& operator>>(std::ifstream& in, GaiData& obj);
};

