#ifndef __SAVINGSACCOUNT_H__
#define __SAVINGSACCOUNT_H__

#include "BankAccount.hpp" // Base class

class SavingsAccount : public BankAccount
{
private:
	double interestRate;

public:
	SavingsAccount(std::string accountNumber, double balance, double interestRate) :
		BankAccount(accountNumber, balance), interestRate(interestRate)
	{
	}

	void calculateInterest()
	{
		balance += balance * interestRate;
	}

	void displayInfo() override
	{
		BankAccount::displayInfo(); // print account number and balance info
		std::cout << "============" << std::endl;
		std::cout << "Interest Rate: " << interestRate << std::endl;
	}
};
#endif // __SAVINGSACCOUNT_H__