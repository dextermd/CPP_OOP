#pragma once
#include <iostream>
#include <vector>
#include "Transaction.h"

using namespace std;

class Wallet
{
    string name;
    string number;
    double balance;
    vector<Transaction> transactions;

public:
    Wallet();
    Wallet(const string& name, const string& number, double balance, vector<Transaction>& transactions);
    
    void add_balance(double summa);
    void pay(double summa, const TransactionCategory& category, time_t datetime);
    const void show_wallet() const;

    string get_name() { return name; };
    string get_number() { return number; };
    double get_balance() { return balance; };

    void set_name(const string& name) { this->name = name; };
    void set_number(const string& number) { this->number = number; };
    void set_balance(double balance) { this->balance = balance; };
};

