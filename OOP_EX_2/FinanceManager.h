#pragma once
#include <iostream>
#include <vector>
#include "TransactionCategory.h"
#include "Wallet.h"
#include <map>

using namespace std;

class FinanceManager
{
	map<string, Wallet> wallets;
	vector<TransactionCategory> categories;
	
public:
	FinanceManager() {};
	
	void add_vallet(const string& name, const string& number);
	const void show_wallers() const;
	const void show_categories() const;
	void create_category(const string& category);
	void topup_wallet(const string& wallet_number, double summa);
};
