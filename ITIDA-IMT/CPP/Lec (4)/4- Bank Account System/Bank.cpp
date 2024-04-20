#include "Bank.hpp"
#include <iostream>

void Bank::addAccount(const BankAccount& account)
{
	accounts.push_back(account);
}

double Bank::getTotalBalance() const
{
	double totalBalance = 0.0;
	for (const auto& account: accounts)
	{
		totalBalance += account.getAccountBalance();
	}
	return totalBalance;
}

void Bank::displayAllAccounts() const
{
	std::cout << "All Accounts:\n";
	for (const auto& account: accounts)
	{
		std::cout << "==================================" << std::endl;
		account.displayAccountInfo();
		std::cout << "==================================" << std::endl;
	}
}

static bool compareAccountNumbers(const BankAccount& a, const BankAccount& b)
{
	return a.getAccountNumber() < b.getAccountNumber();
}

void Bank::SortAccounts()
{
	std::sort(accounts.begin(), accounts.end(), compareAccountNumbers);
}

// getter for accounts
const std::vector<BankAccount>& Bank::getAccounts() const
{
	return accounts;
}