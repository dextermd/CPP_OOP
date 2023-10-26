#include <iostream>
#include <conio.h>
#include<iomanip>
#include <map>
#include <set>
#include <vector>
#include "FinanceManager.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	//setlocale(LC_ALL, "ru_RU.utf8");

	FinanceManager finance;
	finance.add_vallet("Debit", "4100 0000 0000 0000");
	finance.add_vallet("Credit", "4200 0000 0000 0000");
	finance.show_wallers();
	finance.create_category("Пополнение");
	finance.create_category("Зарплата");
	finance.create_category("Покупки продуктов и услуг");
	finance.create_category("Автомобильные расходы");
	finance.create_category("Налоги");
	finance.show_categories();
	


	//Создайте систему управления персональными финансами.
	//	Система должна иметь следующие возможности :
	//■ Наличие разных кошельков и карт(дебетовых / кредитных);
	//■ Пополнение кошельков и карт;
	//■ Внесение затрат. Каждая затрата относится к определенной категории;
	
	//■ Формирование отчетов по затратам и категориям :
	//• день;
	//• неделя;
	//• месяц.
	
	//	■ Формирование рейтингов по максимальным суммам :
	//• ТОП - 3 затрат :
	//	ӽ неделя;
	//ӽ месяц.
	//	• ТОП - 3 категорий:
	//ӽ неделя;
	//ӽ месяц.

}