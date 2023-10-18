#include "FrequencyDictionary.h"

FrequencyDictionary::FrequencyDictionary(string input_file_name)
{
    ifstream input_file(input_file_name);
    if (!input_file.is_open()) {
        cout << "������ �������� �����!" << endl;
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
    cout << "����� � �� ���������� ����������:" << endl;
    for (const auto& value : words) 
    {
        cout << value.first << " - " << value.second << endl;
    }
}
