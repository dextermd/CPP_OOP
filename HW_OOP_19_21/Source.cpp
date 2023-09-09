#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include "MyString.h"
#include "MyTree.h"
#include "EnRoTree.h"
#include "colors.h"

using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ENTER 13



// Menu
void showmenu(int key = -1) {
	key--;
	system("CLS");
	cout << endl << endl;
	char menu[7][250] = { "Add... " , "Search... ", "Show all... ", "Save to txt file", "Save to binary file", "Read from binary file", "Exit" };

	for (int i = 0; i < 7; i++) {
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

int main()
{

#if 0
	/*
		Задание 1. Для уже существующего класса Бинарного дерева поиска(MyTree) реализуйте методы для :
		+ записи данных дерева в текстовый файл;
		+ записи данных дерева в бинарный файл;
		+ чтения данных из бинарного файла с инициализацией другого дерева.
	*/

	MyTree t;

	t.Show();
	cout << endl;

	t.Add(25);
	t.Add(4);
	t.Add(33);
	t.Add(335);
	t.Add(678);
	t.Add(135);
	t.Add(663);
	t.Add(144);
	t.Add(15);
	t.Add(17);
	t.Add(50);

	t.Show();
	cout << endl;

	FILE* file;
	errno_t err;

	// Write
	err = fopen_s(&file, "text.txt", "w");
	if (!err)
	{
		t.save_txt(file);
		fclose(file);
		cout << endl;
	}

	// Write Binary
	err = fopen_s(&file, "binary.txt", "wb");
	if (!err)
	{
		t.save_to_binary_file(file);
		fclose(file);
		cout << endl;
	}

	// Write Binary
	MyTree c;
	err = fopen_s(&file, "binary.txt", "rb");
	if (!err)
	{
		c.read_from_binary_file(file);
		fclose(file);
	}
	cout << "\nC = ";
	c.Show();
	cout << "\nCount ==== " << c.getCount();

#endif

#if 0
	/*
		Задание 2. Реализуйте англо - русский словарь с помощью бинарного дерева поиска.Ключом
		будет служить слово на английском, значением узла – перевод слова на русский.Для слов
		использовать уже существующий класс «Строка / MyString».Организуйте следующий
		функционал класса :
		+ добавление данных в словарь;
		+ поиск английского слова, в случае наличия слова в словаре – дать перевод, а в случае отсутствия – сообщение;
		+ запись словаря в текстовый файл;
		+ запись данных словаря в двоичный файл;
		+ считывание словаря из двоичного файла(с инициализацией дерева).
	*/

	FILE* file;
	errno_t err;
	EnRoTree object, object_copy;
	int keys = 1, menuorder = 1, exit = 1;

	showmenu(1);

	while (exit) {

		switch ((keys = _getch())) {

		case KEY_UP:
			if (menuorder == 0) menuorder = 1;
			if (menuorder == 1) menuorder = 7;
			else menuorder--;
			showmenu(menuorder);
			break;
		case KEY_DOWN:
			if (menuorder == 7) menuorder = 1;
			else
				menuorder++;
			showmenu(menuorder);
			break;
		case KEY_ENTER:
			system("CLS");
			switch (menuorder) {
			case 1:
				object.Add();
				SetColor(8);
				cout << "\n\tEnter any keys to return back to menu" << endl;
				SetColor(15);
				_getch();
				showmenu(1);
				break;
			case 2:
				object.search();
				SetColor(8);
				cout << "\n\tEnter any keys to return back to menu" << endl;
				SetColor(15);
				_getch();
				showmenu(2);
				break;
			case 3:
				object.Show();
				SetColor(8);
				cout << "\n\tEnter any keys to return back to menu" << endl;
				SetColor(15);
				_getch();
				showmenu(3);
				break;
			case 4:
				err = fopen_s(&file, "str.txt", "w");
				if (!err)
				{
					object.save_txt(file);
					fclose(file);
					printf("\nThe tree is written to a file\n");
				}
				SetColor(8);
				cout << "\n\tEnter any keys to return back to menu" << endl;
				SetColor(15);
				_getch();
				showmenu(4);
				break;

			case 5:
				err = fopen_s(&file, "str_bynary.txt", "wb");
				if (!err)
				{
					object.save_to_binary_file(file);
					fclose(file);
					printf("\nThe tree is written to a binary file\n");
				}
				SetColor(8);
				cout << "\n\tEnter any keys to return back to menu" << endl;
				SetColor(15);
				_getch();
				showmenu(5);
				break;

			case 6:
				err = fopen_s(&file, "str_bynary.txt", "rb");
				if (!err)
				{
					object_copy.read_from_binary_file(file);
					fclose(file);
					printf("\nThe tree is read from the binary file:\n");
				}
				object_copy.Show();
				cout << "\nNumber of tree elements after reading: " << object_copy.getCount() << endl;

				SetColor(8);
				cout << "\n\tEnter any keys to return back to menu" << endl;
				SetColor(15);
				_getch();
				showmenu(6);
				break;

			case 7:
				system("CLS");
				exit = 0;
				break;
			}
		}
	}

#endif

}