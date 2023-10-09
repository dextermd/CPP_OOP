#pragma once
#include <iostream>
#include <fstream>

using namespace std;

ofstream& operator << (ofstream& out, const string& st)
{
	int len = st.length();
	out.write((const char*)&len, sizeof(len));
	out.write(st.c_str(), len);
	return out;
}

ifstream& operator >> (ifstream& in, string& str)
{
	int len;
	in.read((char*)&len, sizeof(len));
	str.resize(len);
	in.read(const_cast<char*>(str.c_str()), len);
	return in;
}