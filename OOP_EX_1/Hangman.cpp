#include "Hangman.h"
#include <algorithm>
#include <cctype>
Hangman::Hangman()
{
    read_words_from_file();
}

const void Hangman::read_words_from_file()
{
    ifstream fin("hangman.bin", ios::binary);
    if (fin)
    {
        int len;
        int size;
        string encrypted_word;
        fin.read((char*)&size, sizeof(size));

        for (int i = 0; i < size; i++)
        {
            fin.read((char*)&len, sizeof(len));
            encrypted_word.resize(len);
            fin.read(const_cast<char*>(encrypted_word.c_str()), len);

            string decrypted_word = encrypted_word;
            encrypt_decrypt(decrypted_word);
            words.push_back(decrypted_word);
        }
        fin.close();
    }
    else {
        cout << "\nОшибка чтения из файла!\n";
    }
}

const void Hangman::read()
{
    ifstream input_file("words.txt");
    if (!input_file.is_open()) {
        return;
    }

    string word;
    while (input_file >> word)
    {
        words.push_back(word);
    }

    input_file.close();
}

const void Hangman::save_data_to_file()
{
    ofstream fout("hangman.bin", ios::binary);
    if (fout)
    {
        int size = get_words_count();
        fout.write((char*)&size, sizeof(size));

        int len;
        for (const auto& word : words)
        {
            string encrypt_word = word;
            encrypt_decrypt(encrypt_word);

            len = encrypt_word.length();
            fout.write((const char*)&len, sizeof(len));
            fout.write(encrypt_word.c_str(), len);
        }
        fout.close();
    }
    else {
        cout << "\nОшибка записи в файл!\n";
    }
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

const string Hangman::get_random_word()
{
    int max_word_count = get_words_count();
    srand(time(0));
    if (max_word_count) {
        int rand_num = rand() % max_word_count + 1;
        return words[rand_num];
    }
    else {
        throw "\nНет слов в файле!";
    }
}

int Hangman::get_word_char_count(const string& word)
{
    return word.size();
}



void Hangman::encrypt_decrypt(string& word)
{
    for (int i = 0; i < word.size(); ++i) {
        word[i] = word[i] ^ KEY[i % KEY.size()];
    }
}

void Hangman::guessed_word_init(int size)
{
    for (int i = 0; i < size; i++)
    {
        guessed_word.push_back('*');
    }
}

bool Hangman::is_guessed()
{
    string guessed_word_str(guessed_word.begin(), guessed_word.end());
    return (word == guessed_word_str) ? true : false;
}

void Hangman::guessed_word_init(char& letter)
{
    search
    int find = word.find()
    if (found > -1)
    {
        cout << "Вы угадали букву.";
        for (int i = 0; i < word.size(); ++i) {
            if (word[i] == letter) {
                guessed_word[i] = letter;
            }
            else if (word[i] == toupper(letter))
            {
                guessed_word[i] = toupper(letter);
            }
        }
    }
    else {
        cout << "Вы не угадали букву.";
    }

}

const void Hangman::show_guessed_word() const
{
    cout << "\nЗагаданное слово: ";
    for (const auto& value : guessed_word) {
        cout << '[' << value << ']';
    }
    
}

void Hangman::start_game()
{
    word = get_random_word();

    word_size = word.size();
    guessed_word_init(word_size);

    do
    {
        cout << word;
        show_guessed_word();
        cout << "\nУгадайте букву: ";
        char letter;
        cin >> letter;
        system("cls");
        guessed_word_init(letter);
        
    } while (!is_guessed());

    cout << endl << endl;
}


