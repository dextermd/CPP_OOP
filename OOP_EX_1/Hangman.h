#pragma once
#include <iostream>
#include <fstream>
#include <conio.h>
#include<iomanip>
#include <map>
#include <set>
#include <vector>

using namespace std;

class Hangman
{
	vector<string> words;

public:
	Hangman(const string& filename = "words.txt");

	void read_words_from_file(const string& filename);
	const void show_all_words() const;
	int get_words_count();
	const string get_random_word() const;

};

