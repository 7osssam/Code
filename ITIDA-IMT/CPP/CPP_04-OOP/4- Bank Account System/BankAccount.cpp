#include <iostream>
#include "BankAccount.hpp"

// Setters and Getters
int BankAccount::getAccountNumber() const
{
	return accountNumber;
}

const std::string& BankAccount::getAccountHolder() const
{
	return accountHolder;
}

const std::string& BankAccount::getAccountType() const
{
	return accountType;
}

double BankAccount::getAccountBalance() const
{
	return accountBalance;
}

// Service functions
void BankAccount::deposit(double amount)
{
	if (amount > 0)
	{
		accountBalance += amount;
		std::cout << "Deposit of $" << amount << " successful\n";
	}
	else
	{
		std::cerr << "Error: Deposit amount must be greater than zero\n";
	}
}

bool BankAccount::withdraw(double amount)
{
	if (amount > 0)
	{
		if (accountBalance >= amount)
		{
			accountBalance -= amount;
			std::cout << "Withdrawal of $" << amount << " successful\n";
			return true;
		}
		else
		{
			std::cerr << "Error: Insufficient funds\n";
		}
	}
	else
	{
		std::cerr << "Error: Withdrawal amount must be greater than zero\n";
	}
	return false;
}

void BankAccount::displayAccountInfo() const
{
	std::cout << "Account Number: " << accountNumber << std::endl;
	std::cout << "Account Holder: " << accountHolder << std::endl;
	std::cout << "Account Type: " << accountType << std::endl;
	std::cout << "Account Balance: $" << accountBalance << std::endl;
}
