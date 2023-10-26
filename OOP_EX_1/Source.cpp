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
	hangman.start_game();
}
