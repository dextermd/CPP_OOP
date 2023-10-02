#pragma once
#include "Person.h"

/*Написать производный класс Служащий(Worker) от класса Человек, поля:
-компания(MyString)
- стаж
- зарплата
Методы :
-конструкторы по умолчанию и с параметрами
- метод вывода данных на экран
- метод инициализации объекта с клавиатуры
- деструктор*/ 

class Worker : virtual public Person
{
private:

protected:
	MyString company;
	float experience;
	float salary;

public:
	Worker();
	Worker(const MyString& name, const MyString& surname, const int age, const float height, const float weight, const MyString company, const float experience, const float salary);

	void show() const override;
	void init()override;

	~Worker();

};

