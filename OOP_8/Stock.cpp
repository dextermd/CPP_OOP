#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include "Stock.h"

using namespace std;

Stock::Stock()
{
	strcpy_s(this->name, "No name");

	this->platform = new char[strlen("No platform") + 1];
	if (this->platform)
	{
		strcpy_s(this->platform, strlen("No platform") + 1, "No platform");
	}

	qty = 0;
	price = 0.;
    total_price = qty * price;
}


void Stock::show() const
{
	cout << setprecision(2) << fixed;
	cout << "\nНазвание			: " << name;
	cout << "\nПлатформа			: " << platform;
	cout << "\nКол-во				: " << qty;
	cout << "\nЦена				: " << price;
	cout << "\nОбщая цена			: " << total_price;
	cout << endl;
}

Stock::~Stock()
{
	delete[] this->platform;
	this->platform = nullptr;
}
