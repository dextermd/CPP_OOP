#include "function.h"
#include "stdarg.h"

int summa(int k, ...)
{
	int* ptr = &k;
	int summa = 0;
	while (k)
	{
		ptr++;
		summa += *ptr;
		k--;
	}

	return summa;
}

double summa_double(int k, ...)
{
	int* ptr = &k;
	ptr++;
	double* ptrd = (double *)ptr;

	double summa = 0.;

	for (; k--;ptrd++)
	{
		summa += *ptrd;
	}

	return summa;
}

int summa_int(int k, ...)
{
	int* ptr = &k;
	int summa = 0;

	while (*ptr)
	{
		summa += *ptr;
		ptr++;
	}

	return summa;

}


double AnyType(int count, bool typeof, ...)
{
	int sumi = 0;      //сумма для целочисленных параметров
	double sumd = 0.0; //сумма для вещественных параметров



	// Переменная типа va_list (переопределённый char*) 
	// хранит указатель на список параметров  функции.

	va_list arg_ptr;    //Создаём указатель на список параметров
	//получаем этот указатель, отталкиваясь от первого фактического параметра



	va_start(arg_ptr, count);



	//пропускаем второй фактический параметр
	va_arg(arg_ptr, bool);



	//count раз считываем последующие параметры
	while (count--) {
		//если typeof - true, то считываем параметры типа int
		//если typeof - false, то считываем параметры типа double
		(typeof) ? sumi += va_arg(arg_ptr, int) :
			sumd += va_arg(arg_ptr, double);
	}
	va_end(arg_ptr);//закрываем список параметров



	//если typeof - true, то показываем сумму типа int
	//если typeof - false, то показываем сумму типа double

	return (typeof ? sumi : sumd);
}

/*
1.-------------------------------------------
void va_start( va_list arg_ptr, prev_param );

Первый параметр — созданная заранее переменная
типа va_list, в неё запишется указатель на список параметров,
созданный данной функцией.


Второй параметр нашей функции, что бы va_list могла
от чего-то оттолкнуться при связывании arg_ptr и
списка.



2.-------------------------------------------
Анализируем параметры с помощью многократного
вызова функции:
type va_arg( va_list arg_ptr, type );



Данная функция получает параметр из списка,
указатель на который передан в неё в качестве первого
параметра, и переставляет этот указатель на следующий элемент.




3.-------------------------------------------
Заканчиваем анализ параметров и очищаем внутренний указатель,
устанавливая его в нуль с помощью
функции:
void va_end( va_list arg_ptr );
*/