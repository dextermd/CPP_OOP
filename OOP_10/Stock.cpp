#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include "Stock.h"

using namespace std;

//Stock::Stock()
//{
//	strcpy_s(this->name, "No name");
//
//	this->platform = new char[strlen("No platform") + 1];
//	if (this->platform)
//	{
//		strcpy_s(this->platform, strlen("No platform") + 1, "No platform");
//	}
//
//	qty = 0;
//	price = 0.;
//    total_price = qty * price;
//}

Stock::Stock(const char* name, const char* platform, int qty, double price)
{
	strcpy_s(this->name, name);

	this->platform = new char[strlen(platform) + 1];
	if (this->platform)
	{
		strcpy_s(this->platform, strlen(platform) + 1, platform);
	}

	if (qty < 0)
		qty = -qty;
	
	this->qty = qty;

	if (price < 0)
		price = -price;

	this->price = price;
	this->total_price = this->qty * this->price;
}

Stock::Stock(const Stock& obj)
{
	strcpy_s(this->name, obj.name);
	this->qty = obj.qty;
	this->price = obj.price;

	this->platform = new char[strlen(obj.platform) + 1];
	if (this->platform)
	{
		strcpy_s(this->platform, strlen(obj.platform) + 1, obj.platform);
	}

	this->total_price = obj.total_price;
}


void Stock::show() const
{
	cout << setprecision(2) << fixed;
	cout << "\nНазвание	: " << name;
	cout << "\nПлатформа	: " << platform;
	cout << "\nКол-во		: " << qty;
	cout << "\nЦена		: " << price;
	cout << "\nОбщая цена	: " << total_price;
	cout << endl;
}

void Stock::set_name(const char* name)
{
	strcpy_s(this->name, name);
}

void Stock::set_platform(const char* platform)
{
	if (strlen(this->platform) != strlen(platform) + 1)
	{
		delete[] this->platform;
		this->platform = nullptr;
		this->platform = new char[strlen(platform) + 1];
	}

	strcpy_s(this->platform, strlen(platform) + 1, platform);
	
}

void Stock::set_qty(const int qty)
{
	this->qty = qty;
	this->total_price = this->qty * this->price;
}

void Stock::set_price(const double price)
{
	this->price = price;
	this->total_price = this->price * this->qty;
}

void Stock::buy_stock(int qty)
{
	this->qty += qty;
	this->total_price = this->qty * this->price;
}

bool Stock::sell_stock(int qty)
{
	if (qty <= this->qty)
	{
		this->qty -= qty;
		this->total_price = this->qty * this->price;
		return true;
	}
	return false;
}

void Stock::init()
{
	char buf[250];
	cout << "\nНазвание	: ";
	cin.getline(this->name, sizeof(this->name));

	cout << "\nПлатформа	: ";
	//cin.get();
	cin.getline(buf, sizeof(buf));

	if (this->platform)
		delete[] this->platform;

	this->platform = new char[strlen(buf) + 1];
	strcpy_s(this->platform, strlen(buf) + 1, buf);

	cout << "\nКол-во		: ";
	cin >> this->qty;

	cout << "\nЦена		: ";
	cin >> this->price;
	cin.get();

	this->total_price = this->qty * this->price;
}

Stock::~Stock()
{
	delete[] this->platform;
	this->platform = nullptr;
}
