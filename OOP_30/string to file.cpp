#include<iostream>
#include<conio.h>
#include<fstream>
#include "string to file.h"


using namespace std;


ofstream& operator << (ofstream& out, const string& st)
{
		
	int len = st.length();
	out.write((const char*)&len, sizeof(len)); // Запись длины, приведение Си
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
//-----------------------------------------------------------------

ofstream& operator << (ofstream& out, const vector<int>& arr)
{
	int s = arr.size();
	out.write((const char*)&s, sizeof(s));
	out.write((const char*)&arr[0], arr.size() * sizeof(arr[0]));
	return out;
}


//-----------------------------------------------------------------
ifstream& operator >> (ifstream& in, vector<int>& arr)
{
	int s;
	in.read((char*)&s, sizeof(s));
	arr.resize(s);
	in.read((char*)&arr[0], arr.size() * sizeof(int));
	return in;
}

//-----------------------------------------------------------------
ofstream& operator << (ofstream& out, const list<string>& lst)
{
	int s = lst.size();
	out.write((const char*)&s, sizeof(s));
	for (auto v : lst)
	{
		out << v;
	}
	return out;
}

//-----------------------------------------------------------------
ifstream& operator >> (ifstream& in, list<string>& lst)
{
	int s;
	in.read((char*)&s, sizeof(s));
	string tmp;
	for (int i = 0; i < s; i++)
	{
		in >> tmp;
		lst.push_back(tmp);
	}
	return in;
}