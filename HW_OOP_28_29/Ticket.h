#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Ticket
{
public:
    string car_number;
    vector<string> penality;

    Ticket();
    Ticket(const string& car_number);
    Ticket(const string& car_number, vector<string> pen);

    void add();

    void add_penality(const string& penality);

    const void show() const;

    bool operator<(const Ticket& other) const;

};

