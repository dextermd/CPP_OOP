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


	~Train();
};

