#include "FrequencyDictionary.h"

FrequencyDictionary::FrequencyDictionary(string input_file_name)
{
    ifstream input_file(input_file_name);
    if (!input_file.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
        return;
    }

    string word;
    while (input_file >> word) 
    {
        word.erase(remove_if(word.begin(), word.end(), ispunct), word.end());
        words[word]++;
    }

    input_file.close();
}

const void FrequencyDictionary::show() const
{
    cout << "Слова и их количество повторений: \n" << endl;
    for (const auto& value : words) 
    {
        cout << value.first << " - " << value.second << endl;
    }
}

const void FrequencyDictionary::show_max() const
{
    cout << "Слова часто встречающиеся : \n" << endl;
    for (const auto& value : words)
    {
        if (value.second > 5)
        {
            cout << value.first << " - " << value.second << endl;
        }
    }
}

const void FrequencyDictionary::save_data_to_file()
{
    ofstream fout("FrequencyDictionary.txt");
    if (fout)
    {
        for (const auto& value : words)
        {
            fout << value.first << " - " << value.second << endl;
        }
        fout.close();
    }
    else {
        cout << "\nError Writing File!\n";
    }
}
