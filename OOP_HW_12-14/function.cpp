#include "function.h"
#include "stdarg.h"
#include <iostream>

double summa(int count, bool typeof, ...)
{
	int sumi = 0;      // сумма для целочисленных параметров
	double sumd = 0.0; // сумма для вещественных параметров



	// Переменная типа va_list (переопределённый char*) 
	// хранит указатель на список параметров  функции.

	va_list arg_ptr;    //Создаём указатель на список параметров
	//получаем этот указатель, отталкиваясь от первого фактического параметра


	va_start(arg_ptr, count);



	//пропускаем второй фактический параметр
	va_arg(arg_ptr, bool);

	//count раз считываем последующие параметры
	while (count--)
	{
		if (typeof)
		{
			// Сумма для целочисленных параметров
			int value = va_arg(arg_ptr, int);
			sumi += value;
		}
		else
		{
			// Сумма для вещественных параметров
			double value = va_arg(arg_ptr, double);
			sumd += value;
		}
	}

	va_end(arg_ptr);//закрываем список параметров

	//std::cout << sumd << "," << sumi << "     ";



	//если typeof - true, то показываем сумму типа int
	//если typeof - false, то показываем сумму типа double

	return (typeof ? sumi : sumd);
}
