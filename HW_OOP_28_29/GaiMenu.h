#pragma once

#include <iostream>
#include <fstream>
#include "color.h"
#include "GaiData.h"
#include <conio.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ENTER 13

using namespace std;


void show_menu_gai(int key = -1) {
	key--;
	system("CLS");
	cout << endl << endl;
	char menu[4][250] = { "Entering data... " , "Display information... ", "Displaying information about car number... ", "Exit and Save" };

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


void init_menu_gai(GaiData data) {

	int keys = 1, menuorder = 1, exit = 1;
	string number;

	while (exit) {
		switch ((keys = _getch())) {

		case KEY_UP:
			if (menuorder == 0) menuorder = 1;
			if (menuorder == 1) menuorder = 4;
			else menuorder--;
			show_menu_gai(menuorder);
			break;
		case KEY_DOWN:
			if (menuorder == 4) menuorder = 1;
			else
				menuorder++;
			show_menu_gai(menuorder);
			break;
		case KEY_ENTER:
			system("CLS");
			switch (menuorder) {
			case 1:
				data.add();
				SetColor(8);
				cout << "\n\tEnter any keys to return back to menu" << endl;
				SetColor(15);
				_getch();
				show_menu_gai(1);
				break;
			case 2:
				data.show();
				SetColor(8);
				cout << "\n\tEnter any keys to return back to menu" << endl;
				SetColor(15);
				_getch();
				show_menu_gai(2);
				break;
			case 3:
				cout << "\nEnter car number: ";
				cin >> number;
				data.show_by_number(number);
				SetColor(8);
				cout << "\n\tEnter any keys to return back to menu" << endl;
				SetColor(15);
				_getch();
				show_menu_gai(3);
				break;
			case 4:
				system("CLS");
				data.save_data_to_file();
				data.save_data_from_user();
				exit = 0;
				break;
			}
		}
	}
}

