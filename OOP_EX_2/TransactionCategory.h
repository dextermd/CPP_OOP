#pragma once
#include <iostream>

using namespace std;

class TransactionCategory
{
	string name;

public:
	TransactionCategory();
	TransactionCategory(const string category_name) : name(category_name) {}

	const void show_category() const;
	
	string get_category() { return name; };
	void set_category(const string& category) { name = category; };
};

