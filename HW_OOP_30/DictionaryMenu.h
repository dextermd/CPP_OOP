#pragma once
#include <iostream>
#include <fstream>
#include "color.h"
#include <conio.h>
#include "Dictionary.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ENTER 13

using namespace std;

void show_menu(int key = -1) {
	key--;
	system("CLS");
	cout << endl << endl;
	char menu[6][250] = { "Add words... " , "Edit words... ", "Delete words... ", "Find words... ", "Show all... ", "Exit and Save" };

	for (int i = 0; i < 6; i++) {
		SetColor(15, 0);
		if (i == key) SetColor(0, 14);
		cout << "\t " << i + 1 << " " << menu[i];
		if (i == key) cout << " ->  ";
		cout << endl << endl;
		SetColor(7, 0);
	}
	cout << "\t =======================" << endl;
	SetColor(8);
	cout << "\tNavigation: UP key, DOWN key, ENTER to select" << endl;
	SetColor(7);
}


//- добавление, удаление, редактирование слов;
//-поиск слова, в случае успеха вывести перевод на два языка, в противном
//случае - сообщение;
//-вывод словаря на экран;
//-запись и чтение словаря в файл(двоичный).

void init_menu(Dictionary& data) {

	int keys = 1, menuorder = 1, exit = 1;
	string key;

	while (exit) {
		switch ((keys = _getch())) {

		case KEY_UP:
			if (menuorder == 0) menuorder = 1;
			if (menuorder == 1) menuorder = 6;
			else menuorder--;
			show_menu(menuorder);
			break;
		case KEY_DOWN:
			if (menuorder == 6) menuorder = 1;
			else
				menuorder++;
			show_menu(menuorder);
			break;
		case KEY_ENTER:
			system("CLS");
			switch (menuorder) {
			case 1:
				data.init();
				SetColor(8);
				cout << "\n\tEnter any keys to return back to menu" << endl;
				SetColor(15);
				_getch();
				show_menu(1);
				break;
			case 2:
				data.init_edit();
				SetColor(8);
				cout << "\n\tEnter any keys to return back to menu" << endl;
				SetColor(15);
				_getch();
				show_menu(2);
				break;
			case 3:
				cout << "\nВведите ключ для удаления: ";
				cin >> key;
				data.remove(key);
				SetColor(8);
				cout << "\n\tEnter any keys to return back to menu" << endl;
				SetColor(15);
				_getch();
				show_menu(3);
				break;
			case 4:
				cout << "\nВведите ключ для поиска: ";
				cin >> key;
				data.find_by_key(key);
				SetColor(8);
				cout << "\n\tEnter any keys to return back to menu" << endl;
				SetColor(15);
				_getch();
				show_menu(4);
				break;
			case 5:
				data.show();
				SetColor(8);
				cout << "\n\tEnter any keys to return back to menu" << endl;
				SetColor(15);
				_getch();
				show_menu(5);
				break;
			case 6:
				system("CLS");
				data.save_data_to_file();
				exit = 0;
				break;
			}
		}
	}
}