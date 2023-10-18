#pragma once
#include <iostream>
#include <fstream>
#include <map>

using namespace std;

class FrequencyDictionary
{
private:
	string file_name;
	map<string, int> words;
	
public:
	FrequencyDictionary(string input_file_name);

	const void show() const;
};

