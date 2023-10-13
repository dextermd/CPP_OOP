#include <windows.h>
#include "IRSSystem.h"
#include "color.h"

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

std::ostream& operator<<(std::ofstream& out, IRSSystem& obj)
{
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
	//int len;
	//for(const auto& value : obj.trains)
	//{ 
	//	in.read((char*)&value.number, sizeof(value.number));

	//	in.read((char*)&len, sizeof(len));
	//	value.dep_time.resize(len);
	//	in.read(const_cast<char*>(value.dep_time.c_str()), len);

	//	in.read((char*)&len, sizeof(len));
	//	value.dest_station.resize(len);
	//	in.read(const_cast<char*>(value.dest_station.c_str()), len);
	//}

	return in;
}
