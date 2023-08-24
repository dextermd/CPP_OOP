#include "ListTwo.h"
#include <iostream>

using namespace std;

ListTwo::ListTwo()
{
	this->head = this->tail = nullptr;
	this->count = 0;
}

void ListTwo::push_back(const int& add)
{
	Node* tmp = new Node(add);
	
	if (this->head) // Если список пуст
	{
		this->tail->next = tmp;
		tmp->prev = this->tail;
		this->tail = tmp;
	}
	else { // Если в списке один элемент
		this->head = tmp;
		this->tail = tmp;
	}
	this->count++;
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

void ListTwo::show(bool direction) const
{
	if (!this->head)
	{
		cout << "\nList is Empty\n";
		return;
	}

	if (direction)
	{
		Node* current = this->head;

		while (current)
		{
			cout << current->data << "  ";
			current = current->next;
		}
		cout << endl;
	}
	else {
		Node* current = this->tail;

		while (current)
		{
			cout << current->data << "  ";
			current = current->prev;
		}
		cout << endl;
	}

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
