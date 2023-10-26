#include "FinanceManager.h"
#include <cstdarg>

void FinanceManager::add_vallet(const string& name, const string& number)
{
    Wallet wallet;
    wallet.set_name(name);
    wallet.set_number(number);
    wallet.set_balance(0);
    wallets[number] = wallet;
}

const void FinanceManager::show_wallers() const
{
    for (const auto& wallet : wallets)
    {
        wallet.second.show_wallet();
    }
}

const void FinanceManager::show_categories() const
{
    for (const auto& category : categories)
    {
        cout << endl;
        category.show_category();
    }
}

void FinanceManager::create_category(const string& category)
{
    categories.push_back(category);
}

void FinanceManager::topup_wallet(const string& wallet_number, double summa)
{
    double balance = wallets[wallet_number].get_balance();
    balance += summa;
    wallets[wallet_number].set_balance(balance);
}
