#ifndef __BANKACCOUNT_H__
#define __BANKACCOUNT_H__

#include <iostream>

class BankAccount
{
protected:
	int			accountNumber;
	std::string accountHolder;
	double		balance;

public:
	BankAccount(int accountNumber, std::string accountHolder, double balance) :
		accountNumber(accountNumber), accountHolder(accountHolder), balance(balance)
	{
	}

	void deposit(double amount)
	{
		balance += amount;
	}

	void withdraw(double amount)
	{
		balance -= amount;
	}

	virtual void displayInfo() // virtual function to be overridden by derived classes
	{
		std::cout << "Account Number: " << accountNumber << std::endl;
		std::cout << "Account Holder: " << accountHolder << std::endl;
		std::cout << "Balance: " << balance << std::endl;
	}
};

#endif // __BANKACCOUNT_H__