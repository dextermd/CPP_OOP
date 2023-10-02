#pragma once
#include "Student.h"
#include "Worker.h"

class WorkerStudent : public Student, public Worker
{
	int study_days;
	int work_days;

public:
	WorkerStudent();
	WorkerStudent(const MyString& name, const MyString& surname, const int age, const float height, const float weigh,
		const MyString& vuz, const MyArray& grade, const MyString& company, const float experience, const float salary,
		const int study_days, const int work_days);

	void show() const override;
	void init() override;

	~WorkerStudent();
};
