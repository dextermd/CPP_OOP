#pragma once

#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
	Node* prev;

	Node() {
		this->data = 0;
		this->next = this->prev = nullptr;
	}

	Node(int _data) {
		this->data = _data;
		this->next = this->prev = nullptr;
	}
};

class ListTwo {

	Node* head;
	Node* tail;
	int count;

public:
	ListTwo();
	ListTwo(const ListTwo& obj);
	ListTwo(ListTwo&& obj);

	ListTwo& operator=(const ListTwo& obj); // Оператор = с перемещением c глубоким копированием
	ListTwo& operator=(ListTwo&& obj); // Оператор = с перемещением без глубокого копирования

	void pop_all();
	void pop_front();
	void pop_back();
	void add_begin(const int& data);
	void push_back(const int& add);
	void add_by_element(const int a, const int data);
	void show() const;
	//void show(bool direction = true) const;
	int get_count() const { return this->count; };
	bool containe(const int& data) const;
	bool cmp_incr(const int& a, const int& b) { return a > b; };

	ListTwo& operator+(const ListTwo& obj) const;
	friend ostream& operator<<(ostream& out, const ListTwo& obj);
	friend istream& operator>>(std::istream& in, ListTwo& obj);

	~ListTwo();

};

