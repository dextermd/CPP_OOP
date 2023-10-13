#pragma once
#include <string>
using namespace std;

class Person {

protected:
	string name;
	string surname;
	int age;
	float rost;
	float ves;
public:
	//Person();
	Person(string n="no", string sn="no", int a=0, float r=0, float v=0);

	void set_name(char *n);
	void set_age(int a);
	void set_rv(float r, float v);

	int get_age()const { return age; }

	virtual void show()const;         
	virtual void init();

	bool operator<(const Person& p1)const;
	bool operator>(const Person& p1)const;
	
	virtual ~Person();   
};
