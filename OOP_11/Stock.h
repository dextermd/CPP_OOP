#pragma once
class Stock
{
    char name[50];
    char* platform;
    int qty;
    double price;
    double total_price;

public:
    // Stock(); // Конструктор
    Stock() : Stock("No Name", "No Platform", 0, 0) {}; // Делегирующий Конструктор
    Stock(const char* name, const char* platform, int qty, double price); // Конструктор с параметрами
    Stock(const Stock& obj); // Конструктор копирования

    void show() const;

    void set_name(const char* name);
    const char* get_name() const { return name; };

    void set_platform(const char* platform);
    const char* get_platform() const { return platform; };

    void set_qty(const int qty);
    int get_qty() const { return qty; };

    void set_price(const double price);
    double get_price() const { return price; };

    double get_total_price() const { return total_price; };

    void buy_stock(int qty);

    bool sell_stock(int qty);

    void init();

    ~Stock();

};

