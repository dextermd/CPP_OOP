#include "ListTwo.h"
#include <iostream>

using namespace std;

ListTwo::ListTwo()
{
	this->head = this->tail = nullptr;
	this->count = 0;
}

ListTwo::ListTwo(const ListTwo& obj)
{
	this->head = nullptr;
	Node* temp = obj.head;

	while (temp)
	{
		this->push_back(temp->data);
		temp = temp->next;
	}
	this->count = obj.count;
	delete temp;
	temp = nullptr;
}

ListTwo::ListTwo(ListTwo&& obj)
{
	this->head = obj.head;
	this->tail = obj.tail;
	this->count = obj.count;

	obj.head = nullptr;
	obj.tail = nullptr;
	obj.count = 0;
}

ListTwo& ListTwo::operator=(const ListTwo& obj)
{
	this->pop_all();
	this->head = nullptr;
	this->tail = nullptr;

	Node* temp = obj.head;

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

ListTwo& ListTwo::operator=(ListTwo&& obj)
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

void ListTwo::pop_all()
{
	while (this->head) {
		Node* temp = this->head;
		this->head = this->head->next;
		delete temp;
		temp = nullptr;
		count--;
	}
}

void ListTwo::pop_front()
{
	if (this->head)
	{
		Node* temp = this->head;
		this->head = this->head->next;
		delete temp;
		count--;
	}
}

void ListTwo::pop_back()
{
	if (!this->head) 
		return;
	
	Node* temp = this->head;
	while (temp->next && temp->next->next)
	{
		temp = temp->next;
	}

	delete temp->next;
	temp->next = nullptr;
	this->tail = temp;
	count--;
}

void ListTwo::add_begin(const int& data)
{
	Node* add = new Node(data);

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

void ListTwo::push_back(const int& add)
{
	Node* tmp = new Node(add);
	
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

void ListTwo::add_by_element(const int a, const int data)
{
	if (this->containe(a))
	{

		Node* current = this->head;
		Node* add = new Node(data);

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

		/*this->tail->next = add;
		add->prev = this->tail;
		this->tail = add;*/
		add->prev = current;
		add->next = current->next;
		current->next = add;
		count++;
	}

	return;
}

void ListTwo::show() const
{
	if (!this->head)
	{
		cout << "\nList is Empty\n";
		return;
	}
	Node* current = this->head;

	while (current)
	{
		cout << current->data << "  ";
		current = current->next; 
	}
	cout << endl;

}

//void ListTwo::show(bool direction) const
//{
//	if (!this->head)
//	{
//		cout << "\nList is Empty\n";
//		return;
//	}
//
//	if (direction)
//	{
//		Node* current = this->head;
//
//		while (current)
//		{
//			cout << current->data << "  ";
//			current = current->next;
//		}
//		cout << endl;
//	}
//	else {
//		Node* current = this->tail;
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

bool ListTwo::containe(const int& data) const
{
	if (!this->head) // Если список пуст
		return false;

	Node* tmp = this->head;
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

ListTwo& ListTwo::operator+(const ListTwo& obj) const
{
	ListTwo* result = new ListTwo;
	result->head = nullptr;
	result->tail = nullptr;
	Node* temp = this->head;

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

ListTwo::~ListTwo()
{
	Node* current = this->head;
	Node* prev_current = this->head;

	while (current)
	{
		current = current->next;
		delete prev_current;
		prev_current = current;
		count--;
		//cout << "*** " << count;
	}
	this->head = this->tail = nullptr;
}

ostream& operator<<(ostream& out, const ListTwo& obj)
{
	if (!obj.head)
	{
		out << "\nList is Empty\n";
		return out;
	}

	Node* tmp = obj.head;

	for (int i = 0; i < obj.count; i++)
	{
		out << tmp->data << "  ";
		tmp = tmp->next;
	}

	out << endl;
	return out;
}

istream& operator>>(std::istream& in, ListTwo& obj)
{
	Node* add = new Node;
	cout << "\nInput data: ";
	in >> add->data;
	add->next = nullptr;

	Node* current = obj.head;

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
