#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include "MyArray.h"
#include "Student.h"
#include "Stack.h"
#include "StackD.h"
#include "Queue.h"
#include "QueueRing.h"
#include "QueuePriority.h"

using namespace std;



int main()
{

#if 0

	// Задание 1.
	/*
		В уже существующие классы MyArray и Student добавьте перегрузку операторов
		ввода с клавиатуры и вывода на экран.Продемонстрируйте работу операторов на примерах.
	*/

	MyArray arr(10, 1, 20), arr_two;

	cout << arr;
	//cin >> arr_two;
	//cout << arr_two;

	Student st, st2;

	cout << st;
	cin >> st2;
	cout << st2;

#endif 

#if 0

	// Задание 2.
	/*
		В уже существующие классы Очередь (Queue) и Стек(StackD) добавьте реализацию
		конструктора копирования и перегрузку оператора присваивания.
	*/



#endif 

#if 0

	// Задание 3.
	/*
		Реализуйте класс Очередь с приоритетным включением — на основе
		динамического массива целых значений. Каждый элемент при попадании в очередь сразу
		же располагается согласно своему приоритету. А в момент исключения - извлекается элемент из
		начала очереди. Реализуйте в классе конструктор копирования и перегрузку оператора
		присваивания. Продемонстрируйте работу класса на примерах.
	*/

#endif 

}