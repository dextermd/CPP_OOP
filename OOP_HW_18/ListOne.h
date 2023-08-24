#pragma once

#include <iostream>

using namespace std;

struct Element{
	char data;			// Полезные данные
	Element* next;		// Адрес следующего элемента
};

class ListOne{
	Element* head;
	int count;
public:
	ListOne();
	ListOne(const ListOne& obj);
	ListOne(ListOne&& obj); // Конструктор перемещения

	ListOne& operator=(const ListOne& obj);
	ListOne& operator=(ListOne&& obj); // Оператор = с перемещением без глубокого копирования

	void add_end(const char& data);
	void show() const;
	void add_begin(const char& data);
	void pop_front();
	void pop_back();
	void pop_by_index(const int index);
	void pop_all();
	int get_index_by_element(const char data);
	char& get_element_by_index(const int index) const;
	int get_count() const { return count; }
	void add_element(const char a, const char b);
	void add_do_element(const char item, const char data);
	void add_do_by_index(const int index, const char data);

	bool containe(const char& data) const;

	bool operator==(const ListOne& obj) const;
	bool operator!=(const ListOne& obj) const;
	bool operator<=(const ListOne& obj) const;
	bool operator>=(const ListOne& obj) const;
	bool operator>(const ListOne& obj) const;
	bool operator<(const ListOne& obj) const;

	ListOne& operator+(const ListOne& obj) const;
	ListOne operator-() const;


	friend ostream& operator<<(ostream& out, const ListOne& obj);
	friend istream& operator>>(std::istream& in, ListOne& obj);

	~ListOne();

private:

};

