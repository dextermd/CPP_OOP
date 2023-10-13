#pragma once
#include <iostream>

using namespace std;

class Train
{

public:
	int number;
	string dep_time;
	string dest_station;

	Train();
	Train(int num, string time, string destination);

	const void show() const;
	void init();

	// Перегрузка потока записи в файл <<
	friend std::ostream& operator<<(std::ofstream& out, Train& obj);
	// Перегрузка потока чтении из файла >>
	friend std::istream& operator>>(std::ifstream& in, Train& obj);

	~Train();
};

