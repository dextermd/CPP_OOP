#include "Hangman.h"



Hangman::Hangman(const string& filename)
{
    read_words_from_file(filename);
}

void Hangman::read_words_from_file(const string& filename)
{
    ifstream input_file(filename);
    if (!input_file.is_open()) {
        cout << "\nОшибка чтения файла!" << endl;
        return;
    }

    string word;
    while (input_file >> word)
    {
        words.push_back(word);
    }

    input_file.close();
}

const void Hangman::show_all_words() const
{
    for (const auto& word : words)
        cout << word << " ";
}

int Hangman::get_words_count()
{
    return words.size();
}

const string Hangman::get_random_word() const
{
    srand(time(0));
    rand = 
    int random_word_index = 
}
