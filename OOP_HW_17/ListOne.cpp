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

ListOne& ListOne::operator=(const ListOne& obj)
{
	this->pop_all();
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

	return *this;
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

void ListOne::pop_back()
{
	if (!this->head)
		return;

	if (!this->head->next) {
		delete this->head;
		this->head = nullptr;
		count--;
		return;
	}

	Element* temp = this->head;
	while (temp->next && temp->next->next)
	{
		temp = temp->next;
	}
	
	delete temp->next;
	temp->next = nullptr;
	count--;

}

void ListOne::pop_all()
{
	while (this->head) {
		Element* temp = this->head;
		this->head = this->head->next;
		delete temp;
		temp = nullptr;
		count--;
	}
}

int ListOne::get_index_by_element(const char& data)
{
	int tnum = 0;

	if (!this->head) {
		return -1;
	}

	Element* temp = this->head;

	while (temp)
	{
		tnum++;
		if(temp->data == data)
		{
			return tnum;
		}
		temp = temp->next;
	}

	delete temp;
	temp = nullptr;
	return -1;
}

char& ListOne::get_element_by_index(const int index) const
{
	char empty = '\0';
	int tnum = 1;
	if (!this->head)
	{
		return empty;
	}
	if (this->head && index == 1) {
		return this->head->data;
	}

	Element* temp = this->head;

	if (index <= this->count && index > 0)
	{
		while (temp)
		{
			temp = temp->next;
			tnum++;
			if (tnum == index)
			{
				return temp->data;
			}
		}
	} else{
		return empty;
	}

	delete temp;
	temp = nullptr;
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
			cout << "\nAdress = " << &current << endl;
			return true;
		}
		current = current->next;
	}

	cout << "\nAdress = " << &current << endl;
	return false;
}

bool ListOne::operator==(const ListOne& obj) const
{
	Element* ltemp = this->head;
	Element* rtemp = obj.head;

	if (this->count != obj.count)
	{
		return false;
	}

	while (ltemp && rtemp)
	{
		if (ltemp->data != rtemp->data)
		{
			return false;
		}
		ltemp = ltemp->next;
		rtemp = rtemp->next;
	}
	return true;
}

bool ListOne::operator!=(const ListOne& obj) const
{
	Element* ltemp = this->head;
	Element* rtemp = obj.head;

	if (this->count != obj.count)
	{
		return true;
	}

	while (ltemp && rtemp)
	{
		if (ltemp->data != rtemp->data)
		{
			return true;
		}
		ltemp = ltemp->next;
		rtemp = rtemp->next;
	}
	return false;
}

bool ListOne::operator<=(const ListOne& obj) const
{
	Element* ltemp = this->head;
	Element* rtemp = obj.head;

	if (this->count > obj.count)
	{
		return false;
	}

	while (ltemp && rtemp)
	{
		if (ltemp->data > rtemp->data)
		{
			return false;
		}
		ltemp = ltemp->next;
		rtemp = rtemp->next;
	}

	return true;
}

bool ListOne::operator>=(const ListOne& obj) const
{
	Element* ltemp = this->head;
	Element* rtemp = obj.head;

	if (this->count < obj.count)
	{
		return false;
	}

	while (ltemp && rtemp)
	{
		if (ltemp->data < rtemp->data)
		{
			return false;
		}
		ltemp = ltemp->next;
		rtemp = rtemp->next;
	}

	return true;
}

bool ListOne::operator>(const ListOne& obj) const
{
	return this->count > obj.count ?  true : false;
}

bool ListOne::operator<(const ListOne& obj) const
{
	return this->count < obj.count ? true : false;
}

ListOne& ListOne::operator+(const ListOne& obj) const
{
	ListOne* result = new ListOne;
	result->head = nullptr;
	Element* temp = this->head;

	while (temp)
	{
		result->add_end(temp->data);
		temp = temp->next;
	}

	temp = obj.head;

	while (temp)
	{
		result->add_end(temp->data);
		temp = temp->next;
	}

	result->count = this->count + obj.count;
	delete temp;
	temp = nullptr;

	return *result;
}

ListOne ListOne::operator-() const
{
	ListOne result;

	Element* temp = head;
	while (temp) {
		result.add_begin(temp->data);
		temp = temp->next;
	}

	return result;
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

ostream& operator<<(ostream& out, const ListOne& obj)
{
	if (!obj.head)
	{
		out << "\nList is Empty\n";
		return out;
	}

	Element* tmp = obj.head;

	for (int i = 0; i < obj.count; i++)
	{
		out << tmp->data << "  ";
		tmp = tmp->next;
	}

	out << endl;
	return out;
}
