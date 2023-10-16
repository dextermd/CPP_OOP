#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>

#include "string to file.h"

using namespace std;

class StudentSTL {
	string surname;		// Агрегирование
	string name;
	int age;
	string vuz;
	vector<int> marks;
	list<string> subjects;// композиция

public:
	StudentSTL();
	StudentSTL(string surname, string name, int age, string vuz, vector<int> marks, list<string> subjects);

	int GetAge()const { return age; }
	double Average()const;
	string GetVuz()const { return vuz; };
	list<string> GetListSubjects()const { return subjects; }

	void TakeSubject(const string& s);

	friend ostream& operator << (ostream& out, const StudentSTL & st);
	friend istream& operator >> (istream& in, StudentSTL& st);
	
	friend bool operator<(const StudentSTL& a, const StudentSTL& b);

		
	//Перегрузка <<, >>  для записи объекта Student
	//	  в файл - C++

	friend ofstream& operator<<(ofstream& os, const StudentSTL& s);
	friend ifstream& operator>>(ifstream& is, StudentSTL& s);

	
};



