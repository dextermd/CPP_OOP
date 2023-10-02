#include "WorkerStudent.h"

WorkerStudent::WorkerStudent() : Student(), Worker()
{
	this->study_days = 0;
	this->work_days = 0;
}

WorkerStudent::WorkerStudent(const MyString& name, const MyString& surname, const int age, const float height, const float weigh,
	const MyString& vuz, const MyArray& grade, const MyString& company, const float experience, const float salary,
	const int study_days, const int work_days) :
	Person(name, surname, age, height, weigh), // virtual Student, virtual Worker
	Student(name, surname, age, height, weigh, vuz, grade), 
	Worker(name, surname, age, height, weigh, company, experience, salary)
{
	this->study_days = study_days;
	this->work_days = work_days;
}

void WorkerStudent::show() const
{
	Student::show();
	cout << "Company		" << this->company;
	cout << "\nExperience	" << this->experience;
	cout << "\nSalary		" << this->salary;
	cout << "\nWork Days	" << this->work_days;
	cout << "\nStudy Days	" << this->study_days;


}

void WorkerStudent::init()
{
}

WorkerStudent::~WorkerStudent()
{
}
