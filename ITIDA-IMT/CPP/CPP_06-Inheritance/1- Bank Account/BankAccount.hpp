#ifndef __BANKACCOUNT_H__
#define __BANKACCOUNT_H__

#include <iostream>

class BankAccount
{
protected:
	std::string accountNumber;
	double		balance;

public:
	BankAccount(std::string accountNumber, double balance) : accountNumber(accountNumber), balance(balance)
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
		std::cout << "Account Number: " << accountNumber << "\nBalance: " << balance << std::endl;
	}
};

#endif // __BANKACCOUNT_H__