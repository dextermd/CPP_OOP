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

ListOne::ListOne(ListOne&& obj)
{
	this->head = obj.head;
	this->count = obj.count;

	obj.head = nullptr;
	obj.count = 0;
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

ListOne& ListOne::operator=(ListOne&& obj)
{
	if (this == &obj)
		return *this;

	this->pop_all();

	this->head = obj.head;
	this->count = obj.count;

	obj.head = nullptr;
	obj.count = 0;

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

void ListOne::pop_by_index(const int index)
{
	if (!this->head || index < 1)
		return;
	
	if (index == 1) {
		Element* temp = this->head;
		this->head = this->head->next;
		delete temp; 
		count--;
		return;
	}
	
	Element* prev = nullptr;
	Element* temp = this->head;
	int tnum = 1;

	while (temp && tnum < index) {
		prev = temp;
		temp = temp->next;
		tnum++;
	}

	if (!temp) {
		return;  
	}

	prev->next = temp->next;
	delete temp; 
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

int ListOne::get_index_by_element(const char data)
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

void ListOne::add_element(const char a, const char b)
{
	if (this->containe(a))
	{
		Element* tmp = this->head;
		while (tmp->data != a)
		{
			tmp = tmp->next;
		}
		
		Element* add = new Element;
		add->data = b;
		add->next = nullptr;

		add->next = tmp->next;
		tmp->next = add;
		count++;
	}

	return;
}

void ListOne::add_do_element(const char item, const char data)
{
	if (!this->containe(item))
		return;

	Element* add = new Element;
	add->data = data;

	if (this->head->data == item) 
	{
		add->next = this->head;
		this->head = add;
		count++;
		return;
	}

	Element* tmp = this->head;
	while (tmp->next && tmp->next->data != item)
	{
		tmp = tmp->next;
	}

	if (tmp->next)
	{
		add->next = tmp->next;
		tmp->next = add;
		count++;
	}
}

void ListOne::add_do_by_index(const int index, const char data)
{
	int tnum = 2;
	if (index > this->count || index < 1) {
		cout << "\nIndex incorrect!\n";
		return;
	}

	Element* add = new Element;
	add->data = data;

	if (index == 1)
	{
		add->next = this->head;
		this->head = add;
		count++;
		return;
	}

	Element* tmp = this->head;
	while (index != tnum)
	{
		++tnum;
		tmp = tmp->next;
	}

	if (tmp->next)
	{
		add->next = tmp->next;
		tmp->next = add;
		count++;
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

istream& operator>>(std::istream& in, ListOne& obj)
{
	Element* add = new Element;
	cout << "\nInput data: ";
	in >> add->data;
	add->next = nullptr;

	Element* current = obj.head;

	if (obj.head)
	{
		while (current->next != nullptr)
		{
			current = current->next;
		}
		current->next = add;
	}
	else { 
		obj.head = add;
	}
	obj.count++;

	return in;
}
