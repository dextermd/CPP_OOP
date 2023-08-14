#pragma once

#include <iostream>

using namespace std;

template<class Type>
class StackDTemplate
{
private:
	static const int MAX = 10;
	static int count;
	int size;										// размер
	Type* items;									// адрес стека
	int top;										// индекс вершины стека
public:
	StackDTemplate(int s = MAX);							// конструктор
	StackDTemplate(const StackDTemplate& obj);

	bool isempty() const { return top == 0; }
	bool isfull() const { return top == size; }
	bool push(const Type& item);					// добавление элемента в стек
	bool pop(Type& item);							// извлечение элемента из стека
	void show() const;
	int getCount() const { return top; }				// текущее количество элементов стека
	static int getCountAll() { return count; }

	StackDTemplate& operator=(const StackDTemplate& obj);

	StackDTemplate& operator=(StackDTemplate&& obj);

	/*friend ostream& operator<<(ostream& out, const StackDTemplate& obj)
	{
		for (int i = 0; i < obj.top; i++)
		{
			out << obj.items[i] << "  ";
		}
		return out;
	}*/

	friend ostream& operator<< <Type>(ostream& out, const StackDTemplate& obj);

	~StackDTemplate() { count--; delete[] items; }			// деструктор
};


// Реализация класса ********************************************************************************

template<class Type>
int StackDTemplate<Type>::count = 0; // инициализация статической переменной класса


template<class Type>
ostream& operator<<(ostream& out, const StackDTemplate<Type>& obj)
{
	for (int i = 0; i < obj.top; i++)
	{
		out << obj.items[i] << "  ";
	}
	return out;
}

template<class Type>
StackDTemplate<Type>::StackDTemplate(int s) : size(s), top(0)
{
	/*size = s;
	top = 0;*/
	items = new Type[size];
	count++;
}

template<class Type>
StackDTemplate<Type>::StackDTemplate(const StackDTemplate& obj)
{
	this->size = obj.size;
	this->top = obj.top;
	this->count = obj.count;
	this->items = new Type[this->size];

	if (this->items)
	{
		for (int i = 0; i < this->top; i++)
		{
			this->items[i] = obj.items[i];
		}

		//memcpy(this->items, obj.items, sizeof(this->size) * obj.top); // C шаблонам не работает так как разный размер  sizeof(Type)

		count++;
	}
}


template<class Type>
void StackDTemplate<Type>::show() const
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

template<class Type>
StackDTemplate<Type>& StackDTemplate<Type>::operator=(const StackDTemplate& obj)
{
	if (this == &obj)
		return *this;

	delete[] this->items;

	this->size = obj.size;
	this->top = obj.top;
	this->count = obj.count;

	this->items = new Type[this->size];

	for (int i = 0; i <= this->top; i++)
	{
		this->items[i] = obj.items[i];
	}

	// memcpy(this->items, obj.items, sizeof(Type) * obj.top); // C шаблонам не работает так как разный размер  sizeof(Type)

	return *this;
}



//-------------------------------------------------
//Добавление элемента в стек

template<class Type>
bool StackDTemplate<Type>::push(const Type& item)
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

template<class Type>
bool StackDTemplate<Type>::pop(Type& item)
{
	if (top > 0)
	{
		item = items[--top];
		return 1; //true
	}
	return 0; //false
}


