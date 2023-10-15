#include <windows.h>
#include <fstream>
#include "IRSSystem.h"
#include "color.h"

using namespace std;

void IRSSystem::add()
{
	Train train;
	train.init();
	trains.push_back(train);
}

void IRSSystem::add(int num, string time, string destination)
{
	Train train(num, time, destination);
	trains.push_back(train);
}

const void IRSSystem::show_by_number(int num)
{
	int count = 0;
	for (const auto& value : trains)
	{
		if (value.number == num)
		{
			value.show();
			count++;
		}
	}

	if (count < 1)
		show_error("Нет поезда с таким номером!");
}

const void IRSSystem::show_all() const
{
	if (trains.size() < 1)
		show_error("Список пуст!");

	for (const auto& train : trains) {
		train.show();
		std::cout << "\n-----------------------" << std::endl;
	}
}

const void IRSSystem::show_error(string text) const
{
	cout << "\033[" << Color::TEXT_RED << "m" << text << "\033[" << Color::TEXT_DEFAULT << "m\n";
}

const void IRSSystem::show_success(string text) const
{
	cout << "\033[" << Color::TEXT_GREEN << "m" << text << "\033[" << Color::TEXT_DEFAULT << "m\n";

}

const void IRSSystem::save_data_to_file()
{
	ofstream fout("IRSSystem.txt", ios::binary);
	if (fout)
	{
		int size = (*this).trains.size();
		fout.write((char*)&size, sizeof(size));

		int len;
		for (const auto& value : (*this).trains)
		{
			fout.write((char*)&value.number, sizeof(value.number));

			len = value.dep_time.length();
			fout.write((const char*)&len, sizeof(len));
			fout.write(value.dep_time.c_str(), len);

			len = value.dest_station.length();
			fout.write((const char*)&len, sizeof(len));
			fout.write(value.dest_station.c_str(), len);
		}
		fout.close();
	}
	else {
		show_error("Error Writing File!");
	}

}

const void IRSSystem::save_data_from_user() const
{
	ofstream fout("Data_From_User.txt");
	if (fout)
	{
		for (const auto& value : (*this).trains)
		{
			fout << "Номер поезда: " << value.number << endl;
			fout << "Время отправления: " << value.dep_time << endl;
			fout << "Станцию назначения: " << value.dest_station << endl;
			fout << "__________________________________________" << endl;

		}
		fout.close();
	}
	else {
		show_error("Error Writing File!");
	}
}

const void IRSSystem::read_data_from_file()
{
	ifstream fin("IRSSystem.txt", ios::binary);
	if (fin)
	{
		int len;
		int size;
		fin.read((char*)&size, sizeof(size));

		Train train;
		for (int i = 0; i < size; i++)
		{
			fin.read((char*)&train.number, sizeof(train.number));

			fin.read((char*)&len, sizeof(len));
			train.dep_time.resize(len);
			fin.read(const_cast<char*>(train.dep_time.c_str()), len);

			fin.read((char*)&len, sizeof(len));
			train.dest_station.resize(len);
			fin.read(const_cast<char*>(train.dest_station.c_str()), len);

			(*this).trains.push_back(train);
		}
		fin.close();
	}
	else {
		show_error("Error Reading File!");
	}
}

std::ostream& operator<<(std::ofstream& out, IRSSystem& obj)
{
	int size = obj.trains.size();
	out.write((char*)&size, sizeof(size));

	int len;
	for (const auto& value : obj.trains)
	{
		out.write((char*)&value.number, sizeof(value.number));

		len = value.dep_time.length();
		out.write((const char*)&len, sizeof(len));
		out.write(value.dep_time.c_str(), len);

		len = value.dest_station.length();
		out.write((const char*)&len, sizeof(len));
		out.write(value.dest_station.c_str(), len);
	}

	return out;
}

std::istream& operator>>(std::ifstream& in, IRSSystem& obj)
{
	int len;
	int size;
	in.read((char*)&size, sizeof(size));
	
	Train train;
	for (int i = 0; i < size; i++)
	{
		in.read((char*)&train.number, sizeof(train.number));

		in.read((char*)&len, sizeof(len));
		train.dep_time.resize(len);
		in.read(const_cast<char*>(train.dep_time.c_str()), len);

		in.read((char*)&len, sizeof(len));
		train.dest_station.resize(len);
		in.read(const_cast<char*>(train.dest_station.c_str()), len);

		obj.trains.push_back(train);
	}

	return in;
}
