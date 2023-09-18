#pragma once

#include "colors.h"
#include <iostream>
#include <fstream>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ENTER 13

using namespace std;
// Menu
void show_menu(int key = -1) {
	key--;
	system("CLS");
	cout << endl << endl;
	char menu[4][250] = { "Register... " , "Signin... ", "Show account list... ", "Exit" };

	for (int i = 0; i < 4; i++) {
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

//- Регистрация
//− Вход в аккаунт
//− Список пользователей
//− Выход из программы

void init_menu(ListOneT<User>& data, User& user) {

	ifstream read_file("user.txt", ios::binary);
	if (read_file)
	{
		while (read_file >> user)
		{
			data.add_begin(user);
		}
		if (!read_file.eof()) // Проверяем, не достигнут ли конец файла
		{
			cout << "\nError reading file!";
		}
		read_file.close();
	}
	else {
		cout << "\nError reading file!";
	}

	int keys = 1, menuorder = 1, exit = 1;

	while (exit) {
		switch ((keys = _getch())) {

		case KEY_UP:
			if (menuorder == 0) menuorder = 1;
			if (menuorder == 1) menuorder = 7;
			else menuorder--;
			show_menu(menuorder);
			break;
		case KEY_DOWN:
			if (menuorder == 7) menuorder = 1;
			else
				menuorder++;
			show_menu(menuorder);
			break;
		case KEY_ENTER:
			system("CLS");
			switch (menuorder) {
			case 1:
				user.init(data);
				SetColor(8);
				cout << "\n\tEnter any keys to return back to menu" << endl;
				SetColor(15);
				_getch();
				show_menu(1);
				break;
			case 2:
				user.signin(data);
				SetColor(8);
				cout << "\n\tEnter any keys to return back to menu" << endl;
				SetColor(15);
				_getch();
				show_menu(2);
				break;
			case 3:
				if (!data.get_count())
					cout << "\nEmpty Data\n";
				data.show_user_login();
				SetColor(8);
				cout << "\n\tEnter any keys to return back to menu" << endl;
				SetColor(15);
				_getch();
				show_menu(3);
				break;
			case 4:
				system("CLS");
				exit = 0;
				break;
			}
		}
	}
}
