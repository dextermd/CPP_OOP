#include "Wallet.h"

Wallet::Wallet()
{
    this->name = "No";
    this->number = "No";
    this->balance = 0.0;
}

Wallet::Wallet(const string& name, const string& number, double balance, vector<Transaction>& transactions)
{
	this->name = name;
	this->number = number;
	this->balance = balance;
}

void Wallet::add_balance(double summa)
{
	this->balance += summa;
}

void Wallet::pay(double summa, const TransactionCategory& category, time_t datetime)
{
    if (balance >= summa) {
        balance -= summa;
        Transaction transaction(summa, datetime, category);
        transactions.push_back(transaction);
    }
    else {
        cout << "\n������������ ������� �� ��������." << endl;
    }
}

const void Wallet::show_wallet() const
{
    cout << "\n----------------------------------------------";
    cout << "\n�������� ��������: " << name;
    cout << "\n����� ��������: " << number;
    cout << "\n������: " << balance;
    cout << "\n----------------------------------------------";
}
