﻿#pragma once
#include <string.h>
#include <iostream>
#include <assert.h>
#include <fstream>
#include "MyString.h"


using namespace std;



template<class T>
struct ElementType {
	T data;						// Полезные данные
	ElementType<T>* next;		// Адрес следующего элемента
};

template<class T>
class ListOneT {
	ElementType<T>* head;
	int count;

public:
	ListOneT();
	ListOneT(const ListOneT& obj);

	ListOneT& operator=(const ListOneT& obj);

	void add_end(const T& data);
	void show() const;
	void show_user_login() const;
	void add_begin(const T& data);
	void pop_front();
	void pop_back();
	void pop_all();
	int get_index_by_element(const T data);
	T& get_element_by_index(const int index) const;
	int get_count() const { return count; }
	void add_element(const T a, const T b);

	T get_by_pos(const int& index) const;

	void save_to_binary_file(FILE* f);
	void read_from_binary_file(FILE* f);

	void save_to_file_plus(std::ostream& fout) const;

	bool containe(const T& data) const;

	bool user_login_exist(MyString& login);
	bool user_login_correct(MyString& login);
	bool user_password_correct(MyString& password);

	bool operator==(const ListOneT& obj) const;
	bool operator!=(const ListOneT& obj) const;
	bool operator<=(const ListOneT& obj) const;
	bool operator>=(const ListOneT& obj) const;
	bool operator>(const ListOneT& obj) const;
	bool operator<(const ListOneT& obj) const;

	ListOneT& operator+(const ListOneT& obj) const;
	ListOneT operator-() const;


	friend ostream& operator<<(ostream& out, const ListOneT& obj);

	// Перегрузка оператора << для вывода в файл
	friend std::ostream& operator<<(std::ofstream& out, const ListOneT<T>& obj) {

		ElementType<T>* e = obj.head;
		int c = obj.get_count();
		out.write((char*)&c, sizeof(c));

		while (e != nullptr)
		{
			out.write((char*)&(e->data), sizeof(e->data));
			e = e->next;
		}
		return out;
	}

	// Перегрузка оператора >> для чтения из файла
	friend std::istream& operator>>(std::ifstream& in, ListOneT<T>& obj) {

		obj.pop_all();

		int k;
		T tmp;

		in.read((char*)&k, sizeof(k));

		while (k)
		{
			in.read((char*)&tmp, sizeof(tmp));
			obj.add_end(tmp);
			k--;
		}

		return in;
	}


	~ListOneT();

private:

};

template<class T>
ListOneT<T>::ListOneT()
{
	this->head = nullptr;
	this->count = 0;
}

template<class T>
ListOneT<T>::ListOneT(const ListOneT<T>& obj)
{
	this->head = nullptr;
	ElementType<T>* temp = obj.head;

	while (temp)
	{
		this->add_end(temp->data);
		temp = temp->next;
	}
	this->count = obj.count;
	delete temp;
	temp = nullptr;
}

template<class T>
ListOneT<T>& ListOneT<T>::operator=(const ListOneT& obj)
{
	this->pop_all();
	this->head = nullptr;
	ElementType<T>* temp = obj.head;

	while (temp)
	{
		this->add_end(temp->data);
		temp = temp->next;
	}
	this->count = obj.count;
	return *this;
}

template<class T>
void ListOneT<T>::add_end(const T& data)
{
	// Создание нового элемента
	ElementType<T>* add = new ElementType<T>;
	add->data = data;
	add->next = nullptr;

	ElementType<T>* current = this->head;

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

template<class T>
void ListOneT<T>::show() const
{
	if (!this->head)
	{
		throw "List is Empty\n";
		return;
	}

	ElementType<T>* current = this->head;

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

template<class T>
inline void ListOneT<T>::show_user_login() const
{
	if (!this->head)
	{
		cout << "List is Empty\n";
		return;
	}

	ElementType<T>* current = this->head;

	for (int i = 0; i < this->count; i++)
	{
		cout << i + 1 << ". " << current->data.get_login() << endl;
		current = current->next; // Переход на следующий элемент
	}

}

template<class T>
void ListOneT<T>::add_begin(const T& data)
{
	ElementType<T>* add = new ElementType<T>;
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

template<class T>
void ListOneT<T>::pop_front()
{
	if (this->head)
	{
		ElementType<T>* temp = this->head;
		this->head = this->head->next;
		delete temp;
		count--;
	}
}

template<class T>
void ListOneT<T>::pop_back()
{
	if (!this->head)
		return;

	if (!this->head->next) {
		delete this->head;
		this->head = nullptr;
		count--;
		return;
	}

	ElementType<T>* temp = this->head;
	while (temp->next && temp->next->next)
	{
		temp = temp->next;
	}

	delete temp->next;
	temp->next = nullptr;
	count--;

}

template<class T>
void ListOneT<T>::pop_all()
{
	while (this->head) {
		ElementType<T>* temp = this->head;
		this->head = this->head->next;
		delete temp;
		temp = nullptr;
		count--;
	}
}

template<class T>
int ListOneT<T>::get_index_by_element(const T data)
{
	int tnum = 0;

	if (!this->head) {
		return -1;
	}

	ElementType<T>* temp = this->head;

	while (temp)
	{
		tnum++;
		if (temp->data == data)
		{
			return tnum;
		}
		temp = temp->next;
	}

	delete temp;
	temp = nullptr;
	return -1;
}


template<class T>
T& ListOneT<T>::get_element_by_index(const int index) const
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

	ElementType<T>* temp = this->head;

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
	}
	else {
		return empty;
	}

	delete temp;
	temp = nullptr;
}

template<class T>
void ListOneT<T>::add_element(const T a, const T b)
{
	if (this->containe(a))
	{
		ElementType<T>* tmp = this->head;
		while (tmp->data != a)
		{
			tmp = tmp->next;
		}

		ElementType<T>* add = new ElementType<T>;
		add->data = b;
		add->next = nullptr;

		add->next = tmp->next;
		tmp->next = add;
		count++;
	}

	return;
}

template<class T>
T ListOneT<T>::get_by_pos(const int& index) const
{

	assert(index >= 1 && index <= this->count);

	ElementType<T>* current = this->head;
	int cnt = 1;
	while (cnt != index)
	{
		current = current->next;
		cnt++;
	}
	return current->data;	
}


template<class T>
bool ListOneT<T>::containe(const T& data) const
{
	if (!this->head) // Если список пуст
		return false;

	ElementType<T>* current = this->head;
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

template<class T>
bool ListOneT<T>::user_login_exist(MyString& login)
{
	if (!this->head) // Если список пуст
		return false;

	ElementType<T>* current = this->head;
	while (current)
	{
		if (current->data.get_login() == login)
		{
			cout << "\nError login exist! Enter another login please!" << endl;
			return true;
		}
		current = current->next;
	}
	return false;
}

template<class T>
bool ListOneT<T>::user_login_correct(MyString& login)
{
	if (!this->head) // Если список пуст
		return false;

	ElementType<T>* current = this->head;
	while (current)
	{
		if (current->data.get_login() == login)
		{
			return true;
		}
		current = current->next;
	}
	return false;
}

template<class T>
inline bool ListOneT<T>::user_password_correct(MyString& password)
{
	if (!this->head) // Если список пуст
		return false;

	ElementType<T>* current = this->head;
	while (current)
	{
		if (current->data.get_password() == password)
		{
			current->data.show();
			return true;
		}
		current = current->next;
	}
	cout << "\nLogin Incorrect!";
	return false;
}

template<class T>
bool ListOneT<T>::operator==(const ListOneT<T>& obj) const
{
	ElementType<T>* ltemp = this->head;
	ElementType<T>* rtemp = obj.head;

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

template<class T>
bool ListOneT<T>::operator!=(const ListOneT& obj) const
{
	ElementType<T>* ltemp = this->head;
	ElementType<T>* rtemp = obj.head;

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

template<class T>
bool ListOneT<T>::operator<=(const ListOneT& obj) const
{
	ElementType<T>* ltemp = this->head;
	ElementType<T>* rtemp = obj.head;

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

template<class T>
bool ListOneT<T>::operator>=(const ListOneT& obj) const
{
	ElementType<T>* ltemp = this->head;
	ElementType<T>* rtemp = obj.head;

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

template<class T>
bool ListOneT<T>::operator>(const ListOneT& obj) const
{
	return this->count > obj.count ? true : false;
}

template<class T>
bool ListOneT<T>::operator<(const ListOneT& obj) const
{
	return this->count < obj.count ? true : false;
}

template<class T>
ListOneT<T>& ListOneT<T>::operator+(const ListOneT& obj) const
{
	ListOneT* result = new ListOneT;
	result->head = nullptr;
	ElementType<T>* temp = this->head;

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

template<class T>
ListOneT<T> ListOneT<T>::operator-() const
{
	ListOneT result;

	ElementType<T>* temp = head;
	while (temp) {
		result.add_begin(temp->data);
		temp = temp->next;
	}

	return result;
}


template<class T>
ListOneT<T>::~ListOneT()
{
	ElementType<T>* current = this->head;
	ElementType<T>* prev_current = this->head;

	while (current)
	{
		current = current->next;
		delete prev_current;
		prev_current = current;
		count--;
	}
	this->head = nullptr;
}

template<class T>
ostream& operator<<(ostream& out, const ListOneT<T>& obj)
{
	if (!obj.head)
	{
		out << "\nList is Empty\n";
		return out;
	}

	ElementType<T>* tmp = obj.head;

	for (int i = 0; i < obj.count; i++)
	{
		out << tmp->data << "  ";
		tmp = tmp->next;
	}

	out << endl;
	return out;
}


template<class T>
void ListOneT<T>::save_to_binary_file(FILE* f)
{
	fwrite(&this->count, sizeof(int), 1, f);
	ElementType<T>* e = head;

	while (e != nullptr)
	{
		(e->data).save_to_binary_file(f);// save_to_binary_file должен быть у Type
		e = e->next;
	}
}

template<class T>
void ListOneT<T>::read_from_binary_file(FILE* f)
{

	//this->DeleteAll();
	this->~ListOneT();
	int k;
	T tmp;

	fread(&k, sizeof(int), 1, f);
	while (k)
	{
		tmp.read_from_binary_file(f);// read_to_binary_file должен быть у Type
		this->add_end(tmp);
		k--;
	}
}

template<class T>
void ListOneT<T>::save_to_file_plus(std::ostream& fout) const
{
	ElementType<T>* e = head;

	while (e != nullptr)
	{
		fout << e->data << " ";
		e = e->next;
	}
}