#include "Transaction.h"

Transaction::Transaction(double summa, time_t datetime, const TransactionCategory& category)
{
	this->summa = summa;
	this->datetime = datetime;
	this->category = category;
}
