#pragma once
﻿
#include <iostream>

using namespace std;

template<class Type>
class QueueTemplate
{
	Type* w;               //Очередь 
	int MaxLength;         //Максимальный размер очереди
	int Length;            //Текущий размер очереди
public:
	QueueTemplate(int m = 10);          //Конструктор
	QueueTemplate(const QueueTemplate& obj);

	~QueueTemplate();                   //Деструктор


	void Add(Type c);            //Добавление элемента
	int Extract();              //Извлечение элемента
	void Clear();               //Очистка очереди
	bool IsEmpty()const;             //Проверка существования элементов в очереди
	bool IsFull()const;              //Проверка на переполнение очереди
	int GetCount()const;             //Количество элементов в очереди
	void Show()const;                //Вывод очереди на экран

	QueueTemplate& operator=(const QueueTemplate& obj);

	QueueTemplate& operator=(QueueTemplate&& obj);
};

template<class Type>
QueueTemplate<Type>::QueueTemplate(int m)			          //Конструктор
{
	MaxLength = m;             //получаем размер
	w = new Type[MaxLength];    //создаем очередь
	Length = 0;                //Изначально очередь пуста
}

template<class Type>
QueueTemplate<Type>::QueueTemplate(const QueueTemplate& obj)
{
	this->MaxLength = obj.MaxLength;
	this->Length = obj.Length;

	this->w = new Type[this->Length];
	if (this->w)
	{
		for (int i = 0; i < this->Length; i++)
		{
			this->w[i] = obj.w[i];
		}
	}
}

//-----------------------------------------------------
template<class Type>
QueueTemplate<Type>::~QueueTemplate()						  //Деструктор
{
	delete[]w;  //удаление очереди
}


//-----------------------------------------------------
template<class Type>
void QueueTemplate<Type>::Show()const {
	if (!IsEmpty())
	{
		cout << "\n-----------------------------------\n";
		//демонстрация очереди
		for (int i = 0; i < Length; i++) {
			cout << w[i] << " ";
		}
		cout << "\n-----------------------------------\n";
	}
	else cout << "\nОчередь пуста\n";
}

template<class Type>
QueueTemplate<Type>& QueueTemplate<Type>::operator=(const QueueTemplate& obj)
{
	if (this == &obj)
		return *this;


	if (this->Length != obj.Length)
	{
		this->Length = obj.Length;
		this->MaxLength = obj.MaxLength;

		delete[] this->w;
		this->w = new Type[this->Length];
	}

	for (int i = 0; i < this->Length; i++)
	{
		this->w[i] = obj.w[i];
	}

	return *this;
}

template<class Type>
QueueTemplate<Type>& QueueTemplate<Type>::operator=(QueueTemplate&& obj)
{
	if (this == &obj)
		return *this;

	if (this->w)
		delete[] this->w;

	this->Length = obj.Length;
	this->MaxLength = obj.MaxLength;
	this->w = obj.w;

	obj.Length = 0;
	obj.MaxLength = 0;
	obj.w = nullptr;

	return *this;
}

//-----------------------------------------------------

template<class Type>
void QueueTemplate<Type>::Clear()
{
	Length = 0;			//Эффективная "очистка" очереди
}
//-----------------------------------------------------

template<class Type>
bool QueueTemplate<Type>::IsEmpty()const
{
	return Length == 0;
}

//-----------------------------------------------------
template<class Type>
bool QueueTemplate<Type>::IsFull()const
{
	return Length == MaxLength;
}

//-----------------------------------------------------

template<class Type>
int QueueTemplate<Type>::GetCount()	const		//Количество присутствующих в очереди элементов
{
	return Length;
}

//-----------------------------------------------------

template<class Type>
void QueueTemplate<Type>::Add(Type c)
{
	//Если в очереди есть свободное место,
	//то увеличиваем количество
	//значений и добавляем новый элемент
	if (!IsFull())
		w[Length++] = c;
}
//-----------------------------------------------------
template<class Type>
int QueueTemplate<Type>::Extract()
{
	//Если в очереди есть элементы, то возвращаем тот,
	//который вошел первым и сдвигаем очередь
	if (!IsEmpty())
	{
		int temp = w[0];                 //запомнить первый
		for (int i = 1; i < Length; i++) //сдвинуть все элементы
			w[i - 1] = w[i];

		Length--;						 //уменьшить количество
		return temp;					 //вернуть первый(нулевой)
	}
	else return -1;						 //Если в очереди элементов нет
}