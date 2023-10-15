#include "Ticket.h"

Ticket::Ticket()
{
	car_number = "No";
}

Ticket::Ticket(const string& car_number)
{
	this->car_number = car_number;
}

Ticket::Ticket(const string& car_number, vector<string> pen)
{
	this->car_number = car_number;
	this->penality = pen;
}

void Ticket::add()
{
	string penality;
	cout << "\nInput car number: ";
	getline(cin, car_number);
	cout << "\nInput penality: ";
	getline(cin, penality);
	add_penality(penality);
}

void Ticket::add_penality(const string& penality)
{
	this->penality.push_back(penality);
}

const void Ticket::show() const
{
	cout << "\nCar Number: " << car_number;
	cout << "\nPenality: ";
	for (const auto& value : penality) {
		cout << value << " ";
	}
}

bool Ticket::operator<(const Ticket& other) const
{
	return car_number < other.car_number;
}
