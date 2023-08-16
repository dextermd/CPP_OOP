#pragma once

using namespace std;

template<class Type>
class QueueT
{
	Type* w;               //Очередь 
	int MaxLength;         //Максимальный размер очереди
	int Length;            //Текущий размер очереди
public:
	QueueT(int m = 10);          //Конструктор
	QueueT(const QueueT& obj);

	~QueueT();                   //Деструктор


	void Add(Type c);            //Добавление элемента
	Type Extract();              //Извлечение элемента
	void Clear();               //Очистка очереди
	bool IsEmpty()const;             //Проверка существования элементов в очереди
	bool IsFull()const;              //Проверка на переполнение очереди
	int GetCount()const;             //Количество элементов в очереди
	void Show()const;                //Вывод очереди на экран

	QueueT& operator=(const QueueT& obj);

	QueueT& operator=(QueueT&& obj);
};

template<class Type>
QueueT<Type>::QueueT(int m)			          //Конструктор
{
	MaxLength = m;             //получаем размер
	w = new Type[MaxLength];    //создаем очередь
	Length = 0;                //Изначально очередь пуста
}

template<class Type>
QueueT<Type>::QueueT(const QueueT<Type>& obj)
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
QueueT<Type>::~QueueT()						  //Деструктор
{
	delete[]w;  //удаление очереди
}


//-----------------------------------------------------
template<class Type>
void QueueT<Type>::Show()const {
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
QueueT<Type>& QueueT<Type>::operator=(const QueueT& obj)
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
QueueT<Type>& QueueT<Type>::operator=(QueueT&& obj)
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
void QueueT<Type>::Clear()
{
	Length = 0;			//Эффективная "очистка" очереди
}
//-----------------------------------------------------

template<class Type>
bool QueueT<Type>::IsEmpty()const
{
	return Length == 0;
}

//-----------------------------------------------------
template<class Type>
bool QueueT<Type>::IsFull()const
{
	return Length == MaxLength;
}

//-----------------------------------------------------

template<class Type>
int QueueT<Type>::GetCount()	const		//Количество присутствующих в очереди элементов
{
	return Length;
}

//-----------------------------------------------------

template<class Type>
void QueueT<Type>::Add(Type c)
{
	//Если в очереди есть свободное место,
	//то увеличиваем количество
	//значений и добавляем новый элемент
	if (!IsFull())
		w[Length++] = c;
}
//-----------------------------------------------------
template<class Type>
Type QueueT<Type>::Extract()
{
	//Если в очереди есть элементы, то возвращаем тот,
	//который вошел первым и сдвигаем очередь
	if (!IsEmpty())
	{
		Type temp = w[0];                 //запомнить первый
		for (int i = 1; i < Length; i++) //сдвинуть все элементы
			w[i - 1] = w[i];

		Length--;						 //уменьшить количество
		return temp;					 //вернуть первый(нулевой)
	}
}