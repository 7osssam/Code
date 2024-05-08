#include <iostream>
#include <string>
#include <vector>

#include "BankAccountFactory.hpp"

int main()
{
	// Create a vector of BankAccount pointers
	std::vector<BankAccount*> accounts;
	accounts.push_back(BankAccountFactory::createAccount(AccountType::Checking, 1001, "John Doe", 1000, 1.0));
	accounts.push_back(BankAccountFactory::createAccount(AccountType::Savings, 2001, "Jane Doe", 2000, 0.05));

	// Why using auto&& here?
	// Because we are iterating over a vector of pointers, and we want to avoid copying the pointers
	// auto&& is a universal reference, which can bind to both lvalues and rvalues
	// It is used to avoid copying the pointers
	for (auto&& account: accounts)
	{
		std::cout << "_____________________" << std::endl;
		account->displayInfo();
		std::cout << "_____________________" << std::endl;
	}

	return 0;
}