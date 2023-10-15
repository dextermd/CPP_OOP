#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <fstream>
#include <Windows.h>
#include <array>
#include <vector>
#include <algorithm>
#include <list>
#include <csignal>
#include "Train.h"
#include "IRSSystem.h"
#include "Menu.h"
#include "Ticket.h"
#include "GaiData.h"
#include "GaiMenu.h"


using namespace std;

int main()
{
	//setlocale(LC_ALL, "Russian");
	setlocale(LC_ALL, "ru_RU.utf8");

#if 0
	/* Задание 1. 
		Напишите программу «Автоматизированная информационная система ЖД
		вокзала».
		Система содержит сведения об отправлении поездов дальнего следования.
		Для каждого поезда указываем : 
			+ номер, 
			+ время отправления, 
			+ станцию назначения.
		Для строк используйте класс string.

		Обеспечить операции и организовать меню :
			+ Ввод данных в систему;
			+ Вывод информации о всех поездах;
			+ Вывод информации о запрашиваемом поезде;
			+ Выход из программы.
		Использовать контейнерный класс vector.
			+ Реализуйте возможность записи информации двоичный файл и считывание из файла с
			возможностью инициализации нового объекта.
			+ Реализуйте запись информации о расписании движения в текстовый файл с
			оформлением для публикации пользователю.*/


	IRSSystem system_file;
	system_file.read_data_from_file();
	show_menu(1);
	init_menu(system_file);

#endif

#if 1

	/*Задание 2. 
		Реализуйте базу данных ГАИ по штрафным квитанциям с помощью бинарного
			дерева, используйте контейнер set.
			Реализуйте пользовательский класс «Квитанция» Ключом
			будет служить номер автомашины, значением узла — список правонарушений.Если квитанция
			добавляется в первый раз, то в дереве появляется новый узел, а в списке данные
			по правонарушению; если нет, то данные заносятся в существующий список.

			Необходимо также реализовать следующие операции :
				− Дополнение базы данных с клавиатуры;
				− Полный вывод базы данных на экран;
				− Вывод информации по номеру машины;
				− Сохраняйте и загружайте информацию из двоичного файла;
				− Сохранить полную информацию по базе данных в текстовом файле.
			Продемонстрируйте работу программы.Реализуйте меню пользователя.*/

	//Ticket t("FRT 741", { "Crash" });
	//Ticket t1("AAN 579", { "Speed", "Drift", "Crash" });
	//Ticket t2("GGP 199", { "Speed", "Crash" });
	//Ticket t3("SDF 656", { "Drift", "Crash" });
	//Ticket t4("POI 888", { "Speed" });
	//Ticket t5("DBL 666", { "Parking", "Drift", "Speed", "Crash" });

	//GaiData gai_data(t), read_gai;
	//gai_data.add(t1);
	//gai_data.add(t2);
	//gai_data.add(t3);
	//gai_data.add(t4);
	//gai_data.add(t5);

	//gai_data.show();

	//cout << "\nRead Gai__________________________________________\n";
	//read_gai.read_data_from_file();
	//read_gai.show();


	GaiData data;
	data.read_data_from_file();
	show_menu_gai(1);
	init_menu_gai(data);


#endif



}

