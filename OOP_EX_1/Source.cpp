#include <iostream>
#include <conio.h>
#include<iomanip>
#include <map>
#include <set>
#include <vector>
#include "Hangman.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	//setlocale(LC_ALL, "ru_RU.utf8");

	Hangman hangman;
	hangman.show_all_words();
}


//Создайте консольную версию игры «Виселица».
//Важно:
//■ Слово выбирается компьютером из списка слов.
//■ Список слов находится в файле в зашифрованном виде.
//■ По завершении игры на экран выводится статистика игры :
//• количество времени;
//• количество попыток;
//• искомое слово;
//• буквы игрока.