
#include <iostream>

using namespace std;
#include "StackD.h"

 
int StackD::count = 0; // инициализация статической переменной класса

StackD::StackD(int s) : size(s), top(0)
{
	/*size = s;
	top = 0;*/
	items = new int[size];
	count++;
}

StackD::StackD(const StackD& obj)
{
	this->size = obj.size;
	this->top = obj.top;
	this->count = obj.count;
	this->items = new int[this->size];

	if (this->items)
	{
		/*for (int i = 0; i < this->top; i++)
		{
			this->items[i] = obj.items[i];
		}*/

		memcpy(this->items, obj.items, sizeof(int) * obj.top);
		count++;
	}
}

//-------------------------------------------------
void StackD::show() const
{
	if (top == 0) { 
		cout << "\nstack is empty\n"; 
		return; 
	}
	int i;
	for ( i = 0; i < top - 1; i++)
		cout << items[i] << ", ";
	cout << items[i] << "!";
	
	cout << endl;
}

StackD& StackD::operator=(const StackD& obj)
{
	if (this == &obj)
		return *this;

	delete[] this->items;

	this->size = obj.size;
	this->top = obj.top;
	this->count = obj.count;

	this->items = new int[this->size];

	/*for (int i = 0; i <= this->top; i++)
	{
		this->items[i] = obj.items[i];
	}*/

	memcpy(this->items, obj.items, sizeof(int) * obj.top);

	return *this;
}



//-------------------------------------------------
//Добавление элемента в стек
bool StackD::push(const int & item)
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
bool StackD::pop(int & item)
{
	if (top > 0)
	{
		item = items[--top];
		return 1; //true
	}
	return 0; //false
}


