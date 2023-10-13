#pragma once

#include <fstream>
using namespace std;

//----------------------------------------------------------------------------------
// Глобальная перегрузка для записи в двоичный файл

ofstream& operator << (ofstream& out, const string& st)
{
	int len = st.length();

	out.write((const char*)&len, sizeof(len)); // Запись длины, приведение Си
	// или
	//fout.write(reinterpret_cast<const char*>(&len), sizeof(len));// Запись длины, приведение С++
	out.write(st.c_str(), len);  // Запись данных

	return out;
}

ifstream& operator >> (ifstream& in, string& str)
{
	int len;								// Переменная для длины
	in.read((char*)&len, sizeof(len));		// Чтение длины записанной строки
	str.resize(len);
	in.read(const_cast<char*>(str.c_str()), len);// снятие const
	return in;
}


