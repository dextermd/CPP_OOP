#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "Train.h"

using namespace std;

class IRSSystem
{
private:
	vector<Train> trains;

public:
	void add();
	void add(int num, string time, string destination);
	const void show_by_number(int num);
	const void show_all() const;
	const void show_error(string text) const;
	const void show_success(string text) const;
	const void save_to_binary(ofstream& file) const;

	// Перегрузка потока записи в файл <<
	friend std::ostream& operator<<(std::ofstream& out, IRSSystem& obj);
	// Перегрузка потока чтении из файла >>
	friend std::istream& operator>>(std::ifstream& in, IRSSystem& obj);
};

