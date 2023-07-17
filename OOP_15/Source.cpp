#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include "Coord.h"
#include "Stock.h"
#include "Rectangle.h"
#include "Car.h"
#include "Truck.h"
#include "tv.h"
#include "function.h"
#include "MyString.h"
#include "Stack.h"
#include "StackD.h"
#include "Queue.h"
#include "QueueRing.h"
#include "QueuePriority.h"

using namespace std;



int main()
{
#if 1
	// Очередь с приоритетом

	/*
	Виды:
	1. Очередь с приоритетным включением — последовательность
	элементов очереди является строго упорядоченной.
	Каждый элемент при попадании в очередь сразу же располагается
	согласно своего приоритета. А в момент исключения элемента просто
	извлекается элемент из начала.

	2. Очередь с приоритетным исключением — элемент добавляется
	в конец очереди, а при извлечении осуществляется
	самого приоритетного элемента, который впоследтвии удаляется из очереди.

	*/
	
	QueuePriority qp(10);

	qp.Add(63, 0);
	qp.Add(23, 3);
	qp.Add(16, 2);
	qp.Add(63, 9);
	qp.Add(77, 5);

	int result;
	qp.Show();
	qp.Extract(result);
	cout << "\nResult = " << result;
	qp.Show();

	while (!qp.IsEmpty())
	{
		qp.Extract(result);
		cout << "\nResult = " << result;
		qp.Show();
	}

	qp.Show();

#endif

#if 0

	/*
		Кольцевая очередь
		Реализация на динамическом массиве
	*/

	QueueRing qr(12);

	qr.Add(55);
	qr.Add(-5);
	qr.Add(123);
	qr.Add(59);
	qr.Add(94);

	qr.Show();

	for (int i = 0; i < 6; i++)
	{
		qr.Extract();
		qr.Show();
	}


#endif

#if 0
	// Очередь

	Queue q(25);
	q.Add(12);
	q.Add(-2);
	q.Add(3);
	q.Add(30);
	q.Add(150);

	q.Show();


	int result;
	result = q.Extract();
	cout << "\nИзвлечение значаний: " << result << endl;

	q.Show();

	while (!q.IsEmpty())
	{
		result = q.Extract();
		cout << "\nИзвлечение значаний: " << result << endl;
		q.Show();
	}

	q.Show();

	result = q.Extract();
	cout << "\nИзвлечение значений: " << result << endl;

#endif

#if 0
	/*
		Реализация на динамическом массиве
	*/
	StackD sd(6);
	sd.push(25);
	sd.push(-2);
	sd.push(30);
	sd.push(15);
	sd.show();

	int result;

	while (!sd.isempty())
	{
		sd.pop(result);
		cout << result << "   ";
	}

	cout << endl << endl;

#endif 

#if 0
	/*
	Стек — динамическая структура данных, представляющая из
	себя упорядоченный набор элементов, в которой добавление новых
	элементов и удаление существующих производится с одного конца,
	называемого вершиной стека.

	Действует принцип LIFO (Last In First Out),
	т.е. «последний пришёл первый ушёл»
	*/

	Stack st;
	st.Show();
	st.Push('+');
	st.Push('@');
	st.Push('a');
	st.Push('#');
	st.Show();

	cout << "\nКоличество элементов стека: " << st.GetCount() << endl;

	char result = st.Pop();
	cout << "\nИзвлечение элементов: " << result << endl;

	cout << endl << endl;

	cout << "\nКоличество элементов стека: " << st.GetCount() << endl;


	while (!st.IsEmpty())
	{
		result = st.Pop();
		cout << result << endl;
	}

#endif 


}