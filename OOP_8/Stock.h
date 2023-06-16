#pragma once
class Stock
{
    char name[50];
    char* platform;
    int qty;
    double price;
    double total_price;

public:
    Stock();

    void show() const;

    ~Stock();

};

