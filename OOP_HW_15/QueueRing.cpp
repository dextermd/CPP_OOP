
#include <iostream>

using namespace std;

#include "QueueRing.h"

//------------------------------------------------------
QueueRing::QueueRing(int m)
{
	MaxLength = m;            //получаем размер
	w = new int[MaxLength];   //создаем очередь
	Length = 0;			//Изначально очередь пуста
}

QueueRing::QueueRing(const QueueRing& obj)
{
	this->MaxLength = obj.MaxLength;
	this->Length = obj.Length;

	this->w = new int[this->Length];
	if (this->w)
	{
		for (int i = 0; i < this->Length; i++)
		{
			this->w[i] = obj.w[i];
		}
	}
}

//------------------------------------------------------
QueueRing::~QueueRing()
{
	delete[]w;			//удаление очереди
}

//------------------------------------------------------
void QueueRing::Show()const {
	if (!IsEmpty())
	{
		cout << "\n-----------------------------------\n";
		//демонстрация очереди
		for (int i = 0; i < Length; i++) {
			cout << w[i] << " ";
		}
		cout << "\n-------------------------------------\n";
	}
	else cout << "\nОчередь пуста\n";
}

QueueRing& QueueRing::operator=(const QueueRing& obj)
{
	if (this == &obj)
		return *this;


	if (this->Length != obj.Length)
	{
		this->Length = obj.Length;
		this->MaxLength = obj.MaxLength;

		delete[] this->w;
		this->w = new int[this->Length];
	}

	for (int i = 0; i < this->Length; i++)
	{
		this->w[i] = obj.w[i];
	}

	return *this;
}





//------------------------------------------------------
void QueueRing::Clear()
{
	Length = 0;	//Эффективная "очистка" очереди
}

//------------------------------------------------------
bool QueueRing::IsEmpty()const
{
	return Length == 0;
}

//------------------------------------------------------
bool QueueRing::IsFull()const
{
	return Length == MaxLength;
}

//------------------------------------------------------
int QueueRing::GetCount()const
{
	//Количество присутствующих в очереди элементов
	return Length;
}

//------------------------------------------------------
void QueueRing::Add(int c)
{
	//Если в очереди есть свободное место,
	//то увеличиваем количество
	//значений и вставляем новый элемент
	if (!IsFull())
		w[Length++] = c;
}

//------------------------------------------------------
bool QueueRing::Extract()
{
	//Если в очереди есть элементы, то возвращаем тот,
	//который вошел первым и сдвигаем очередь
	if (!IsEmpty()) {
		
		int temp = w[0];                  //запомнить первый
		
		for (int i = 1; i < Length; i++) //сдвинуть все элементы
			w[i - 1] = w[i];
		//забрасываем первый "вытолкнутый" элемент в конец
		w[Length - 1] = temp;
		return 1;
	}
	else return 0;
}