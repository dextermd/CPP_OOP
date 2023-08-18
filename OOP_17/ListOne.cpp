#include "ListOne.h"
#include <string.h>
#include <iostream>
using namespace std;

ListOne::ListOne()
{
	this->head = nullptr;
	this->count = 0;
}

ListOne::ListOne(const ListOne& obj)
{
	this->head = nullptr;
	Element* temp = obj.head;

	while (temp)
	{
		this->add_end(temp->data);	
		temp = temp->next;
	}
	this->count = obj.count;
	delete temp;
	temp = nullptr;
}

void ListOne::add_end(const char& data)
{
	// Создание нового элемента
	Element* add = new Element;
	add->data = data;
	add->next = nullptr;

	Element* current = this->head;

	if (this->head)  // Если список не пустой
	{
		while (current->next != nullptr) // Пока не добрались до последнего элемента списка
		{
			current = current->next;
		}
		current->next = add; // связь
	}
	else { // Если списк пуст
		this->head = add;
	}
	count++;
}

void ListOne::show() const
{
	if (!this->head)
	{
		cout << "\nList is Empty\n";
		return;
	}

	Element* current = this->head;

	// Вариант 1
	for (int i = 0; i < this->count; i++)
	{
		cout << current->data << "  ";
		current = current->next; // Переход на следующий элемент
	}

	// Вариант 2
	/*while (current)
	{
		cout << current->data << "  "; 
		current = current->next; // Переход на следующий элемент
	}*/

	cout << endl;
}

void ListOne::add_begin(const char& data)
{
	Element* add = new Element;
	add->data = data;
	add->next = nullptr;

	if (!this->head)
	{
		this->head = add;
	}
	else {
		add->next = this->head;
		this->head = add;
	}
	count++;
}

void ListOne::pop_front()
{
	if (this->head)
	{
		Element* temp = this->head;
		this->head = this->head->next;
		delete temp;
		count--;

	}
}



bool ListOne::containe(const char& data) const
{
	if (!this->head) // Если список пуст
		return false;
	
	Element* current = this->head;
	while (current)
	{
		if (current->data == data)
		{
			return true;
		}
		current = current->next;
	}

	return false;
}

ListOne::~ListOne()
{
	Element* current = this->head;
	Element* prev_current = this->head;

	while (current)
	{
		current = current->next;
		delete prev_current;
		prev_current = current;
		count--;
	}
	this->head = nullptr;
}
