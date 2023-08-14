#pragma once

#include <iostream>

using namespace std;

template<class Type, int sz = 10>
class StackDT
{
private:
	int size;									// размер
	Type* items;									// адрес стека
	int top;									// индекс вершины стека
public:
	StackDT();						// конструктор
	StackDT(const StackDT& obj);

	bool isempty() const { return top == 0; }
	bool isfull() const { return top == sz; }
	bool push(const Type& item);					// добавление элемента в стек
	bool pop(Type& item);						// извлечение элемента из стека
	void show() const;
	int getCount() const { return top; }		// текущее количество элементов стека


	StackDT& operator=(const StackDT& obj);

	~StackDT() { delete[] items; }		// деструктор
};


template<class Type, int sz>
StackDT<Type, sz>::StackDT() : size(sz), top(0)
{
	/*size = s;template<class Type, int sz>
	top = 0;*/
	items = new int[size];

}

template<class Type, int sz>
StackDT<Type, sz>::StackDT(const StackDT& obj)
{
	this->size = obj.size;
	this->top = obj.top;

	this->items = new Type[this->size];

	if (this->items)
	{
		for (int i = 0; i < this->top; i++)
		{
			this->items[i] = obj.items[i];
		}

		//memcpy(this->items, obj.items, sizeof(int) * obj.top);
	}
}

template<class Type, int sz>
void StackDT<Type, sz>::show() const
{
	if (top == 0) {
		cout << "\nstack is empty\n";
		return;
	}
	int i;
	for (i = 0; i < top - 1; i++)
		cout << items[i] << ", ";
	cout << items[i] << "!";

	cout << endl;
}

template<class Type, int sz>
StackDT<Type, sz>& StackDT<Type, sz>::operator=(const StackDT<Type, sz>& obj)
{
	if (this == &obj)
		return *this;

	delete[] this->items;

	this->size = obj.size;
	this->top = obj.top;

	this->items = new Type[this->size];

	for (int i = 0; i <= this->top; i++)
	{
		this->items[i] = obj.items[i];
	}

	// memcpy(this->items, obj.items, sizeof(int) * obj.top);

	return *this;
}



//-------------------------------------------------
//Добавление элемента в стек

template<class Type, int sz>
bool StackDT<Type, sz>::push(const Type& item)
{
	if (top < size)
	{
		items[top++] = item;
		return 1;
	}
	return 0;
}





//-------------------------------------------------
//Извлечение элемента из стека

template<class Type, int sz>
bool StackDT<Type, sz>::pop(Type& item)
{
	if (top > 0)
	{
		item = items[--top];
		return 1; //true
	}
	return 0; //false
}