#include <iostream>

#include <string>
#include <list>
#include <numeric>

#include "StudentSTL.h"
#include "string to file.h"

using namespace std;


StudentSTL::StudentSTL()
{
	surname = "no name";
	name = "name";
	age = 0;
	vuz = "no vuz";
	//marks = 3;
}

StudentSTL::StudentSTL(string surname, string name, int age, string vuz, vector<int> marks,
	               list<string> subjects)
{
	this->surname = surname;
	this->name = name;
	this->age = age;
	this->vuz = vuz;
	this->marks = marks;
	this->subjects = subjects;
}

ostream& operator << (ostream& out, const StudentSTL& st)
{
	out << "\nФамилия:          " << st.surname
		<< "\nИмя:              " << st.name
		<< "\nВозраст:          " << st.age
		<< "\nВУЗ:              " << st.vuz
		<< "\nКол-во оценок:    " << st.marks.size()
		<< "\nОценки:           ";
	for (auto v : st.marks)
	{
		cout << v << " ";
	}
	cout << "\nСредний балл:    " << st.Average();
	cout << "\nКол-во предметов: " << st.subjects.size()
		<< "\nПредметы:      ";
	for (auto v : st.subjects)
	{
		cout << v << "   ";
	}
	return out;
}

istream& operator>>(istream& in, StudentSTL& st)
{
	cout << "\nВведи данные студента: \n";
	cout << "Фамилия:          ";
	in >> st.surname;
	cout << "\nИмя:             ";
	//in >> st.name;
	getline(in, st.name);
	cout << "\nВозраст:         ";
	in >> st.age;
	in.get();
	cout << "\nВУЗ:             ";
	in >> st.vuz;
	cout << "\nКол-во оценок:   ";
	int s;
	in >> s;
	st.marks.resize(s);// Перераспределение памяти для нового количества оценок
	cout << "\nОценки:          ";
	for (auto& v : st.marks)
	{
		cin >> v;
	}
	cout << "\nКол-во предметов:";
	in >> s;
	in.get();
	cout << "\nПредметы:        \n";
	string sub;
	for (int p = 1; p <= s; p++)
	{
		cout << p << " : ";
		getline(in, sub);
		st.subjects.push_back(sub);
	}
	return in;
}

void StudentSTL::TakeSubject(const string& s)
{
	subjects.push_back(s);
}


bool operator<(const StudentSTL& a, const StudentSTL& b)
{
	return a.surname < b.surname;
}


double StudentSTL::Average()const {
	
	if (!marks.size()) return 0.;
	double tmp = 0;
	for (auto val : marks)
		tmp += val;
	tmp /= marks.size();
	return tmp;

	/*double tmp = accumulate(marks.begin(), marks.end(), 0);
	return tmp/marks.size();*/
}


//----------------------------------------------------------
ofstream& operator<<(ofstream& os, const StudentSTL& st)
{
	os << st.surname << st.name;
	os.write((char*)&st.age, sizeof(st.age));
	os << st.vuz;
	os << st.marks;
	os << st.subjects;

	return os;
}

//----------------------------------------------------------
ifstream& operator>>(ifstream& is, StudentSTL& st)
{
	is >> st.surname >> st.name;
	is.read((char*)&st.age, sizeof(st.age));
	is >> st.vuz;
	is >> st.marks;
	is >> st.subjects;
	return is;
}