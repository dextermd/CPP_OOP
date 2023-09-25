#pragma once
#include "MyString.h"

using namespace std;

class Person
{
private:

protected:
    MyString name;
    MyString surname;
    int      age;
    float    height;
    float    weight;

public:
    Person();
    Person(const MyString& name, const MyString& surname, const int age, const float height, const float weight);

    virtual void show() const;
    virtual void init();

    virtual ~Person();

};

