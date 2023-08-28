#pragma once

#include <iostream>

using namespace std;

template<class T>
struct NodeType {
	T data;
	NodeType<T>* next;
	NodeType<T>* prev;

	NodeType() {
		this->data = 0;
		this->next = this->prev = nullptr;
	}

	NodeType(T _data) {
		this->data = _data;
		this->next = this->prev = nullptr;
	}
};

template<class T>
class ListTwoT {

	NodeType<T>* head;
	NodeType<T>* tail;
	int count;

public:
	ListTwoT();
	ListTwoT(const ListTwoT& obj);
	ListTwoT(ListTwoT&& obj);

	ListTwoT& operator=(const ListTwoT& obj); // Оператор = с перемещением c глубоким копированием
	ListTwoT& operator=(ListTwoT&& obj); // Оператор = с перемещением без глубокого копирования

	void pop_all();
	void pop_front();
	void pop_back();
	void add_begin(const T& data);
	void push_back(const T& add);
	void add_by_element(const T a, const T data);
	void show() const;
	//void show(bool direction = true) const;
	bool cmp_incr(const int& a, const int& b) { return a > b; };
	int get_count() const { return this->count; };
	bool containe(const T& data) const;

	ListTwoT& operator+(const ListTwoT& obj) const;
	friend ostream& operator<< <T>(ostream& out, const ListTwoT& obj);
	friend istream& operator>> <T>(std::istream& in, ListTwoT& obj);

	~ListTwoT();

};

template<class T>
ListTwoT<T>::ListTwoT()
{
	this->head = this->tail = nullptr;
	this->count = 0;
}

template<class T>
ListTwoT<T>::ListTwoT(const ListTwoT& obj)
{
	this->head = nullptr;
	NodeType<T>* temp = obj.head;

	while (temp)
	{
		this->push_back(temp->data);
		temp = temp->next;
	}
	this->count = obj.count;
	delete temp;
	temp = nullptr;
}

template<class T>
ListTwoT<T>::ListTwoT(ListTwoT&& obj)
{
	this->head = obj.head;
	this->tail = obj.tail;
	this->count = obj.count;

	obj.head = nullptr;
	obj.tail = nullptr;
	obj.count = 0;
}

template<class T>
ListTwoT<T>& ListTwoT<T>::operator=(const ListTwoT& obj)
{
	this->pop_all();
	this->head = nullptr;
	this->tail = nullptr;

	NodeType<T>* temp = obj.head;

	while (temp)
	{
		this->push_back(temp->data);
		temp = temp->next;
	}
	this->count = obj.count;
	delete temp;
	temp = nullptr;

	return *this;
}

template<class T>
ListTwoT<T>& ListTwoT<T>::operator=(ListTwoT&& obj)
{
	if (this == &obj)
		return *this;

	this->pop_all();

	this->head = obj.head;
	this->tail = obj.tail;
	this->count = obj.count;

	obj.head = nullptr;
	obj.tail = nullptr;
	obj.count = 0;

	return *this;
}

template<class T>
void ListTwoT<T>::pop_all()
{
	while (this->head) {
		NodeType<T>* temp = this->head;
		this->head = this->head->next;
		delete temp;
		temp = nullptr;
		count--;
	}
}

template<class T>
void ListTwoT<T>::pop_front()
{
	if (this->head)
	{
		NodeType<T>* temp = this->head;
		this->head = this->head->next;
		delete temp;
		count--;
	}
}

template<class T>
void ListTwoT<T>::pop_back()
{
	if (!this->head)
		return;

	NodeType<T>* temp = this->head;
	while (temp->next && temp->next->next)
	{
		temp = temp->next;
	}

	delete temp->next;
	temp->next = nullptr;
	this->tail = temp;
	count--;
}

template<class T>
void ListTwoT<T>::add_begin(const T& data)
{
	NodeType<T>* add = new NodeType<T>(data);

	if (!this->head)
	{
		this->head = add;
		this->tail = add;
	}
	else {
		this->head->prev = add;
		add->next = this->head;
		this->head = add;

	}
	this->count++;
}

template<class T>
void ListTwoT<T>::push_back(const T& add)
{
	NodeType<T>* tmp = new NodeType<T>(add);

	if (this->head)
	{
		this->tail->next = tmp;
		tmp->prev = this->tail;
		this->tail = tmp;
	}
	else {
		this->head = tmp;
		this->tail = tmp;
	}
	this->count++;
}

template<class T>
void ListTwoT<T>::add_by_element(const T a, const T data)
{
	if (this->containe(a))
	{

		NodeType<T>* current = this->head;
		NodeType<T>* add = new NodeType<T>(data);

		if (this->tail->data == a)
		{
			this->tail->next = add;
			add->prev = this->tail;
			this->tail = add;
			count++;
			return;
		}
		while (current->data != a)
		{
			current = current->next;
		}

		add->prev = current;
		add->next = current->next;
		current->next = add;
		count++;
	}

	return;
}

template<class T>
void ListTwoT<T>::show() const
{
	if (!this->head)
	{
		cout << "\nList is Empty\n";
		return;
	}
	NodeType<T>* current = this->head;

	while (current)
	{
		cout << current->data << "  ";
		current = current->next;
	}
	cout << endl;

}


//template<class T>
//void ListTwoT<T>::show(bool direction) const
//{
//	if (!this->head)
//	{
//		cout << "\nList is Empty\n";
//		return;
//	}
//
//	if (direction)
//	{
//		NodeType<T>* current = this->head;
//
//		while (current)
//		{
//			cout << current->data << "  ";
//			current = current->next;
//		}
//		cout << endl;
//	}
//	else {
//		NodeType<T>* current = this->tail;
//
//		while (current)
//		{
//			cout << current->data << "  ";
//			current = current->prev;
//		}
//		cout << endl;
//	}
//
//}

template<class T>
bool ListTwoT<T>::containe(const T& data) const
{
	if (!this->head) // Если список пуст
		return false;

	NodeType<T>* tmp = this->head;
	while (tmp)
	{
		if (tmp->data == data)
		{
			return true;
		}
		tmp = tmp->next;
	}
	return false;
}

template<class T>
ListTwoT<T>& ListTwoT<T>::operator+(const ListTwoT& obj) const
{
	ListTwoT* result = new ListTwoT;
	result->head = nullptr;
	result->tail = nullptr;
	NodeType<T>* temp = this->head;

	while (temp)
	{
		result->push_back(temp->data);
		temp = temp->next;
	}

	temp = obj.head;

	while (temp)
	{
		result->push_back(temp->data);
		temp = temp->next;
	}

	result->count = this->count + obj.count;
	delete temp;
	temp = nullptr;

	return *result;
}

template<class T>
ListTwoT<T>::~ListTwoT()
{
	NodeType<T>* current = this->head;
	NodeType<T>* prev_current = this->head;

	while (current)
	{
		current = current->next;
		delete prev_current;
		prev_current = current;
		count--;
	}
	this->head = this->tail = nullptr;
}

template<class T>
ostream& operator<<(ostream& out, const ListTwoT<T>& obj)
{
	if (!obj.head)
	{
		out << "\nList is Empty\n";
		return out;
	}

	NodeType<T>* tmp = obj.head;

	for (int i = 0; i < obj.count; i++)
	{
		out << tmp->data << "  ";
		tmp = tmp->next;
	}

	out << endl;
	return out;
}

template<class T>
istream& operator>>(std::istream& in, ListTwoT<T>& obj)
{
	NodeType<T>* add = new NodeType<T>;
	cout << "\nInput data: ";
	in >> add->data;
	add->next = nullptr;

	NodeType<T>* current = obj.head;

	if (obj.head)
	{
		while (current->next != nullptr)
		{
			current = current->next;
		}
		current->next = add;
		obj.tail = add;
	}
	else {
		obj.head = add;
		obj.tail = add;
	}
	obj.count++;

	return in;
}

