#include <iostream>
#include <string>
#include <sstream>
#include <cctype> 
#include "ListOneT.h"
#include "StackD.h"

using namespace std;

int main()
{
#if 0
	// Задание 1. 
	// Удалить из строки символы в заданном диапазоне позиций, которые вводятся с клавиатуры. Осуществить проверку переданного диапазона
	
	string str = "Remove characters from the string in the specified range of positions that are entered from the keyboard. Check the transmitted range.";
	int start = 1;
	int end = 10;

	if (start >= 0 && end < str.length() && start <= end)
	{
		str.erase(start - 1, end - start + 1);
	}
	else {
		cout << "Некорректные индексы для удаления" << endl;
	}

	cout << "Результат: " << str << endl;


#endif

#if 0
	// Задание 2. 
	// Найти все вхождения символа - цифры в строку, вывести символ и его позицию в строке, посчитать количество.

	string str = "Year of birth 1998, day 17, month 5";


	for (int i = 0; i < str.length(); i++)
	{
		
		if (str[i] >= '0' && str[i] <= '9')
		{
			cout << "цифра " << str[i] << " в позиции : " << i << endl;
		}
	}

#endif
	
#if 0

	/*
	Задание 3.
	Для строки заменить все вхождения подстроки на другую строку.Например:
		Исходная строка :  The old man and old sea
		Замена : old на young
		Строка после замены : The young man and young sea
	*/

	string str = "The old man and old sea";
	string old = "old";
	string young = "young";

	int pos = 0;
	while ((pos = str.find(old, pos)) != string::npos)
	{
		str.replace(pos, old.length(), young);
		pos += young.length();
	}
	cout << "Result: " << str << std::endl;

#endif

#if 0
	// Задание 4.
	// В строке удалить все вхождения подстроки.Строку и подстроку можно инициализировать на этапе разработки или вводить с клавиатуры.

	string str = "The old man and old sea";
	string sub_string = "old";

	int pos = str.find(sub_string);
	while (pos != string::npos) 
	{
		str.erase(pos, sub_string.length());
		pos = str.find(sub_string);
	}

	cout << "Result: " << str << endl;

#endif

#if 0

	// Задание 5. 
	// Выделить из строки все слова(лексемы) без возможного знака препинания и вывести их на экран(с новой строки).Пример работы программы :
	/*
		Исходная строка : Я свой дом нарисовал, облака и дождик.Мне никто не помогал, я уже...
			Я
			свой
			дом
			нарисовал
			облака
			и
			дождик
			Мне
			никто
			не
			помогал
			я
			уже
	*/

	string str = "Я свой дом нарисовал, облака и дождик.Мне никто не помогал, я уже...";

	for (int i = 0; i < str.length(); i++)
	{
		if (iswpunct(str[i]))
		{
			str[i] = ' ';
		}
	}

	istringstream ss(str);
	string word;

	while (ss >> word) 
	{
		cout << word << endl;
	}
	

#endif

#if 0
	/*
	Задание 6. 
		Добавьте в уже написанные классы(два - три класса на выбор) механизм обработки
		исключений.На ваш выбор генерируйте исключения в случае ошибок.Например,
		нехватка памяти, попытка удаления из пустого списка, деление на нуль, неверная
		дата и т.д.Продемонстрируйте на примерах работу кода.
	*/

#endif

}
