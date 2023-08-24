#pragma once

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

	void push_back(const int& add);
	void show() const;
	void show(bool direction = true) const;
	int get_count() const { return this->count; };

	~ListTwo();

};

