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
	void show_wallet_balance(const string& wallet_number);
	void spend_from_wallet(const string& wallet_number, double summa, const string& category);
	void spend_from_wallet(const string& wallet_number, double summa, const string& category, const string& data);
	
	time_t convert_date(string& data);
	

	void daily_raport(const string& wallet_number);
	void weekly_raport(const string& wallet_number);
	void monthly_raport(const string& wallet_number);
};
