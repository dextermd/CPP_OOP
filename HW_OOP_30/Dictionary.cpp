#include "Dictionary.h"
#include <iomanip>

void Dictionary::add(const string& key, const string& ru, const string& en)
{
	words[key] = make_pair(ru, en);
}

void Dictionary::init()
{
	string key, ru, ro;
	cout << "\nВведите слово на английском: ";
	cin >> key;
	cout << "\nВведите перевод на ru: ";
	cin >> ru;
	cout << "\nВведите перевод на ro: ";
	cin >> ro;
	add(key, ru, ro);
}

void Dictionary::init_edit()
{
	string key, ru, ro;
	cout << "\nВведите ключ для редактирования: ";
	cin >> key;
	cout << "\nВведите новое значение ru: ";
	cin >> ru;
	cout << "\nВведите новое значение ro: ";
	cin >> ro;
	edit(key, ru, ro);
}

void Dictionary::remove(const string& key)
{
	auto it = words.find(key);
	if (it != words.end()) {
		words.erase(it);
	}
	else {
		cout << "\nВ словаре нет ключа " << key << ".\n";
	}

}

const void Dictionary::show() const
{
	cout << "__________________________________________\n";
	cout << left << setw(10) << "eng" << setw(10) << "ru" << setw(10) << "ro" << setw(10);
	cout << endl;
	for (const auto& value : words) {
		cout << left << endl << value.first << setw(10) << value.second.first << setw(10) << value.second.second << setw(10);
	}
	cout << endl;
}

const void Dictionary::find_by_key(const string& key) const
{
	auto it = words.find(key);
	if (it != words.end()) {
		cout << "\nПеревод: ru - " << it->second.first << ", ro - " << it->second.second << endl;
	}
	else {
		cout << "\nВ словаре нет ключа " << key << ".\n";
	}
}

void Dictionary::edit(const string& key, const string& ru, const string& en)
{
	auto it = words.find(key);
	if (it != words.end()) {
		it->second.first = ru;
		it->second.second = en;
	}
	else {
		cout << "\nВ словаре нет ключа " << key << ".\n";
	}
}

const void Dictionary::save_data_to_file()
{
	ofstream fout("Dictionary.txt", ios::binary);
	if (fout)
	{
		int size = words.size();
		fout.write((char*)&size, sizeof(size));

		int len;
		for (const auto& value : words)
		{
			len = value.first.length();
			fout.write((const char*)&len, sizeof(len));
			fout.write(value.first.c_str(), len);

			len = value.second.first.length();
			fout.write((const char*)&len, sizeof(len));
			fout.write(value.second.first.c_str(), len);

			len = value.second.second.length();
			fout.write((const char*)&len, sizeof(len));
			fout.write(value.second.second.c_str(), len);
		}
		fout.close();
	}
	else {
		cout << "\nError Writing File!\n";
	}
}

const void Dictionary::read_data_from_file()
{
	ifstream fin("Dictionary.txt", ios::binary);
	if (fin)
	{
		int len;
		int size;
		fin.read((char*)&size, sizeof(size));
		string key;
		string ru;
		string ro;
		for (int i = 0; i < size; i++)
		{
			fin.read((char*)&len, sizeof(len));
			key.resize(len);
			fin.read(const_cast<char*>(key.c_str()), len);

			fin.read((char*)&len, sizeof(len));
			ru.resize(len);
			fin.read(const_cast<char*>(ru.c_str()), len);

			fin.read((char*)&len, sizeof(len));
			ro.resize(len);
			fin.read(const_cast<char*>(ro.c_str()), len);

			add(key, ru, ro);
		}
		fin.close();
	}
	else {
		cout << "\nError Reading File!\n";
	}
}
