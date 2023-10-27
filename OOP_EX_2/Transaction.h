#pragma once
#include <iostream>
#include <chrono>
#include "TransactionCategory.h"

using namespace std;

class Transaction
{
	TransactionCategory category;
	time_t datetime;
	double summa;

public:
	Transaction(double summa, time_t datetime, const TransactionCategory& category);

	time_t get_datetime() { return datetime; };
	double get_summa() { return summa; };

	void set_datetime(time_t& datetime) { this->datetime = datetime; };
	void set_summa(double& summa) { this->summa = summa; };
};

