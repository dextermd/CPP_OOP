#pragma once
#include <iostream>
#include <fstream>
#include <map>

using namespace std;

class Dictionary
{
private:
	map<string, pair<string, string>> words;

public:

	void add(const string& key, const string& ru, const string& en);
	void init();
	void init_edit();
	void remove(const string& key);
	const void show() const;
	const void find_by_key(const string& key) const;
	void edit(const string& key, const string& ru, const string& en);
	const void save_data_to_file();
	const void read_data_from_file();
};

