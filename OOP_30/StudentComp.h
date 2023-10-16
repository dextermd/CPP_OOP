#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <List>

class StudentComp {

	std::string surname;
	std::string name;
	int age;
	std::string vuz;
	std::vector<int> marks;
	std::list<std::string> subjects;

public:
	StudentComp();
	StudentComp(const std::string &surname, const std::string& name, const int& age,
		const std::string& vuz, const std::vector<int>& marks, const std::list<std::string> &subjects);

	void take_subject(const std::string& sub);

	int get_age()const { return age; }
	double get_average()const;
	bool save_txt(std::ofstream& f);

	friend std::ostream& operator<<(std::ostream& out, const StudentComp& st);

	friend std::ofstream& operator<<(std::ofstream& fout, const StudentComp& obj);
	friend std::ifstream& operator>>(std::ifstream& fit, StudentComp& obj);

	friend bool operator<(const StudentComp& a, const StudentComp& b);


	//bool operator<(const StudentComp& a);

	

};
