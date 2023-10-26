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
	string word;
	int counts;
	int word_size;
	double seconds;
	vector<char> guessed_word;
	vector<int> guessed_word_index;
	const string KEY = "W4pV6mC1sN3xG8k";

public:
	Hangman();

	const void read_words_from_file();
	const void read();
	const void save_data_to_file();
	const void show_all_words() const;
	int get_words_count();
	int get_word_char_count(const string& word);
	const string get_random_word();
	void encrypt_decrypt(string& word);
	void guessed_word_init(int size);
	void guessed_word_init(char& letter);
	const void show_guessed_word() const;
	const void show_game_stats() const;
	const void show_letters() const;
	bool is_guessed();

	void start_game();
	

};

