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

	ListOne& operator=(const ListOne& obj);

	void add_end(const char& data);
	void show() const;
	void add_begin(const char& data);
	void pop_front();
	void pop_back();
	void pop_all();
	int get_index_by_element(const char data);
	char& get_element_by_index(const int index) const;
	int get_count() const { return count; }
	void add_element(const char a, const char b);

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


	~ListOne();

private:

};

