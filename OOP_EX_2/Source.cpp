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

	finance.topup_wallet("4200 0000 0000 0000", 1450);

	finance.show_wallers();
	finance.show_wallet_balance("4200 0000 0000 0000");

	finance.create_category("Пополнение");
	finance.create_category("Зарплата");
	finance.create_category("Налоги");
	finance.create_category("Комунальне");
	finance.create_category("Покупки продуктов и услуг");
	finance.create_category("Автомобильные расходы");

	//finance.spend_from_wallet("4200 0000 0000 0000", 500, "Автомобильные расходы");
	//finance.spend_from_wallet("4200 0000 0000 0000", 700, "Покупки продуктов и услуг");

	finance.spend_from_wallet("4200 0000 0000 0000", 30, "Покупки продуктов и услуг", "30.10.2023");
	finance.spend_from_wallet("4200 0000 0000 0000", 28, "Покупки продуктов и услуг", "28.10.2023");
	finance.spend_from_wallet("4200 0000 0000 0000", 24, "Комунальне", "24.10.2023");
	finance.spend_from_wallet("4200 0000 0000 0000", 23, "Налоги", "23.10.2023");
	finance.spend_from_wallet("4200 0000 0000 0000", 1, "Налоги", "1.10.2023");
	finance.spend_from_wallet("4200 0000 0000 0000", 12, "Налоги", "30.9.2023");

	finance.show_wallet_balance("4200 0000 0000 0000");

	//finance.daily_raport("4200 0000 0000 0000");
	//finance.weekly_raport("4200 0000 0000 0000");
	finance.monthly_raport("4200 0000 0000 0000");
	

	//finance.show_categories();
	


	//Создайте систему управления персональными финансами.
	//	Система должна иметь следующие возможности :
	//+ Наличие разных кошельков и карт(дебетовых / кредитных);
	//+ Пополнение кошельков и карт;
	//+ Внесение затрат. Каждая затрата относится к определенной категории;
	
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