#include "FinanceManager.h"
#include <ctime>
#include <chrono>

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

void FinanceManager::show_wallet_balance(const string& wallet_number)
{
    auto found = wallets.find(wallet_number);
    if (found != wallets.end())
    {
        cout << endl << wallets[wallet_number].get_balance() << endl;
    }
    else {
        cout << "\n��� ������ ��������";
    }

    
}

void FinanceManager::spend_from_wallet(const string& wallet_number, double summa, const string& category)
{
    auto walletIt = wallets.find(wallet_number);
    auto categoryIt = find_if(categories.begin(), categories.end(), [&category](TransactionCategory& _category) { return _category.get_category() == category; });

    if (walletIt != wallets.end() && categoryIt != categories.end()) {
        time_t currentTime = time(nullptr);
        walletIt->second.pay(summa, *categoryIt, currentTime);
    }
    else {
        cout << "������� ��� ��������� �� �������." << endl;
    }
}

void FinanceManager::spend_from_wallet(const string& wallet_number, double summa, const string& category, const string& data)
{
    string tmp_data = data;
    auto walletIt = wallets.find(wallet_number);
    auto categoryIt = find_if(categories.begin(), categories.end(), [&category](TransactionCategory& _category) { return _category.get_category() == category; });

    if (walletIt != wallets.end() && categoryIt != categories.end()) {
        walletIt->second.pay(summa, *categoryIt, convert_date(tmp_data));
    }
    else {
        cout << "������� ��� ��������� �� �������." << endl;
    }
}

time_t FinanceManager::convert_date(string& data)
{
    int day, month, year;
    sscanf_s(data.c_str(), "%d.%d.%d", &day, &month, &year);

    struct tm timeinfo = {};
    timeinfo.tm_mday = day;
    timeinfo.tm_mon = month - 1; 
    timeinfo.tm_year = year - 1900; 

    time_t datetime = mktime(&timeinfo);

    return datetime;
}

void FinanceManager::daily_raport(const string& wallet_number)
{
    // �������� ������� ���� � �����
    time_t currentTime;
    struct tm localTimeInfo;
    time(&currentTime);
    localtime_s(&localTimeInfo, &currentTime);
    int currentDay = localTimeInfo.tm_mday;

    double totalSpent = 0;
    cout << "������� ����� ��� �������� " << wallet_number << " �� " << currentDay << " �����:" << endl;

    auto walletIt = wallets.find(wallet_number);
    if (walletIt != wallets.end()) {
        // ���������� ���������� � ������� ��, ������� ���� ��������� � ������� ����
        for (const auto& transaction : walletIt->second.getTransactions()) {
            const time_t transactionTime = transaction.get_datetime();
            struct tm transactionTimeInfo;
            localtime_s(&transactionTimeInfo, &transactionTime);
            if (transactionTimeInfo.tm_mday == currentDay) {
                cout << "�����: " << transaction.get_summa() << ", ���������: " << transaction.getCategory().get_category() << endl;
                totalSpent += transaction.get_summa();
            }
        }

        cout << "����� ���������: " << totalSpent << endl;
    }
    else {
        cout << "������� �� ������." << endl;
    }
}

void FinanceManager::weekly_raport(const string& wallet_number)
{
    // �������� ������� ���� � �����
    time_t currentTime;
    time(&currentTime);

    // ���������� ������ ������� ������ (�����������)
    struct tm localTimeInfo;
    localtime_s(&localTimeInfo, &currentTime);

    // ������������� ������ ������ (�����������)
    localTimeInfo.tm_wday = 1; // �����������
    localTimeInfo.tm_hour = 0;
    localTimeInfo.tm_min = 0;
    localTimeInfo.tm_sec = 0;
    time_t startOfWeek = mktime(&localTimeInfo);

    // ������������� ����� ������ (�����������)
    localTimeInfo.tm_wday = 7; // �����������
    localTimeInfo.tm_hour = 23;
    localTimeInfo.tm_min = 59;
    localTimeInfo.tm_sec = 59;
    time_t endOfWeek = mktime(&localTimeInfo);

    double totalSpent = 0;
    cout << "����� ��� �������� " << wallet_number << endl;

    auto walletIt = wallets.find(wallet_number);
    if (walletIt != wallets.end()) {
        // ���������� ���������� � ������� ��, ������� ���� ��������� � �������� ������� ������
        for (const auto& transaction : walletIt->second.getTransactions()) {
            time_t transactionTime = transaction.get_datetime();
            if (transactionTime >= startOfWeek && transactionTime <= endOfWeek) {
                cout << "�����: " << transaction.get_summa() << ", ���������: " << transaction.getCategory().get_category() << endl;
                totalSpent += transaction.get_summa();
            }
        }

        cout << "����� ���������: " << totalSpent << endl;
    }
    else {
        cout << "������� �� ������." << endl;
    }
}


void getMonthRange(time_t& startOfMonth, time_t& endOfMonth) {
    time_t now = time(nullptr);
    struct tm timeinfo;
    localtime_s(&timeinfo, &now);

    // ������������� ������ ���� ������
    timeinfo.tm_mday = 1;
    timeinfo.tm_hour = 0;
    timeinfo.tm_min = 0;
    timeinfo.tm_sec = 0;
    startOfMonth = mktime(&timeinfo);

    // ������������� ��������� ���� ������
    timeinfo.tm_mon++;
    timeinfo.tm_mday = 0;
    timeinfo.tm_hour = 23;
    timeinfo.tm_min = 59;
    timeinfo.tm_sec = 59;
    endOfMonth = mktime(&timeinfo);
}

void FinanceManager::monthly_raport(const string& wallet_number)
{
    time_t startOfMonth, endOfMonth;
    getMonthRange(startOfMonth, endOfMonth);

    std::cout << "����� ��� �������� " << wallet_number << " �� ������� �����:" << std::endl;

    auto walletIt = wallets.find(wallet_number);
    if (walletIt != wallets.end()) {
        double totalSpent = 0;
        for (const auto& transaction : walletIt->second.getTransactions()) {
            time_t transactionTime = transaction.get_datetime();
            if (transactionTime >= startOfMonth && transactionTime <= endOfMonth) {
                std::cout << "�����: " << transaction.get_summa() << ", ���������: " << transaction.getCategory().get_category() << std::endl;
                totalSpent += transaction.get_summa();
            }
        }
        std::cout << "����� ���������: " << totalSpent << std::endl;
    }
    else {
        std::cout << "������� �� ������." << std::endl;
    }
}

