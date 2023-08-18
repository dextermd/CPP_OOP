#pragma once

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

	void add_end(const char& data);
	void show() const;
	void add_begin(const char& data);
	void pop_front();
	int get_count() const { return count; }

	bool containe(const char& data) const;




	~ListOne();

private:

};

