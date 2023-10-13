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

std::ostream& operator<<(std::ofstream& out, Train& obj)
{
	int len;

	out.write((char*)&obj.number, sizeof(obj.number));

	len = obj.dep_time.length();
	out.write((const char*)&len, sizeof(len));
	out.write(obj.dep_time.c_str(), len);

	len = obj.dest_station.length();
	out.write((const char*)&len, sizeof(len));
	out.write(obj.dest_station.c_str(), len);

	return out;
}

std::istream& operator>>(std::ifstream& in, Train& obj)
{
	int len;

	in.read((char*)&obj.number, sizeof(obj.number));

	in.read((char*)&len, sizeof(len));
	obj.dep_time.resize(len);
	in.read(const_cast<char*>(obj.dep_time.c_str()), len);

	in.read((char*)&len, sizeof(len));
	obj.dest_station.resize(len);
	in.read(const_cast<char*>(obj.dest_station.c_str()), len);

	return in;
}
