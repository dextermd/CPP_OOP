#include "GaiData.h"
#include "Ticket.h"
#include <fstream>

using namespace std;

GaiData::GaiData(Ticket& data)
{
	this->data.insert(data);
}

const void GaiData::show() const
{
	for (const auto& value : data)
	{
		cout << "\nCar Number: " << value.car_number;
		cout << "\nPenality: ";
		for (const auto& v : value.penality)
		{
			cout << v << " ";
		}
		cout << "\n--------------------------------------------";
	}
}

void GaiData::add()
{
	Ticket ticket;
	ticket.add();
	data.insert(ticket);
}

void GaiData::add(Ticket& data)
{
	this->data.insert(data);
}

const void GaiData::show_by_number(string& number) const
{
	for (const auto& ticket : data) {
		if (ticket.car_number == number) {
			ticket.show();
			return;
		}
	}
}

const void GaiData::save_data_to_file()
{

}

const void GaiData::save_data_from_user() const
{
	ofstream fout("GaiData.txt", ios::binary);
	if (fout)
	{
		int size = data.size();
		int size2 = 0;
		bool is_write_size = false;
		fout.write((char*)&size, sizeof(size));

		int len;
		for (const auto& value : data)
		{
			is_write_size = false;
			len = value.car_number.length();
			fout.write((const char*)&len, sizeof(len));
			fout.write(value.car_number.c_str(), len);

			for (const auto& v : value.penality)
			{
				if (!is_write_size)
				{
					size2 = value.penality.size();
					fout.write((char*)&size2, sizeof(size2));
					is_write_size = true;
				}

				len = v.length();
				fout.write((const char*)&len, sizeof(len));
				fout.write(v.c_str(), len);
			}
		}
		fout.close();
	}
	else {
		cout << "\nError Writing File!";
	}
}

const void GaiData::read_data_from_file()
{
	ifstream fin("GaiData.txt", ios::binary);
	if (fin)
	{
		int len;
		int size;
		int size2 = 0;
		bool is_read_size = false;

		fin.read((char*)&size, sizeof(size));

		Ticket ticket;
		string penality;
		for (int i = 0; i < size; i++)
		{

			fin.read((char*)&len, sizeof(len));
			ticket.car_number.resize(len);
			fin.read(const_cast<char*>(ticket.car_number.c_str()), len);

			fin.read((char*)&size2, sizeof(size2));

			for (int i = 0; i < size2; i++)
			{
				fin.read((char*)&len, sizeof(len));
				penality.resize(len);
				fin.read(const_cast<char*>(penality.c_str()), len);
				ticket.add_penality(penality);
			}

			(*this).add(ticket);
			ticket.penality.clear();
		}
		fin.close();
	}
	else {
		cout << "\nError Reading File!";
	}
}

std::ostream& operator<<(std::ofstream& out, GaiData& obj)
{
	int size = obj.data.size();
	int size2 = 0;
	bool is_write_size = false;
	out.write((char*)&size, sizeof(size));

	int len;
	for (const auto& value : obj.data)
	{
		is_write_size = false;
		len = value.car_number.length();
		out.write((const char*)&len, sizeof(len));
		out.write(value.car_number.c_str(), len);
		
		for(const auto& v: value.penality) 
		{
			if (!is_write_size)
			{
				size2 = value.penality.size();
				out.write((char*)&size2, sizeof(size2));
				is_write_size = true;
			}

			len = v.length();
			out.write((const char*)&len, sizeof(len));
			out.write(v.c_str(), len);
		}
	}

	return out;
}

std::istream& operator>>(std::ifstream& in, GaiData& obj)
{
	int len;
	int size;
	int size2 = 0;
	bool is_read_size = false;

	in.read((char*)&size, sizeof(size));

	Ticket ticket;
	string penality;
	for (int i = 0; i < size; i++)
	{

		in.read((char*)&len, sizeof(len));
		ticket.car_number.resize(len);
		in.read(const_cast<char*>(ticket.car_number.c_str()), len);

		in.read((char*)&size2, sizeof(size2));

		for (int i = 0; i < size2; i++)
		{
			in.read((char*)&len, sizeof(len));
			penality.resize(len);
			in.read(const_cast<char*>(penality.c_str()), len);
			ticket.add_penality(penality);
		}

		obj.add(ticket);
		ticket.penality.clear();
	}
	return in;
}
