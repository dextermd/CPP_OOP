#include "Train.h"
#include <fstream>

using namespace std;

Train::Train()
{
	number = 0;
	dep_time = "00:00";
	dest_station = "No";

}

Train::Train(int num, string time, string destination)
{
	number = num;
	dep_time = time;
	dest_station = destination;
}

const void Train::show() const
{
	cout << "\nНомер поезда: " << number;
	cout << "\nВремя отправления: " << dep_time;
	cout << "\nCтанция назначения: " << dest_station;
}

void Train::init()
{
	cout << "\n\nВведите номер поезда: ";
	cin >> number;
	cout << "\nВведите время отправления: ";
	cin >> dep_time;
	cout << "\nВведите cтанцию назначения: ";
	cin >> dest_station;
}

Train::~Train()
{
}




