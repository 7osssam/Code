#ifndef __CHECKINGACCOUNT_H__
#define __CHECKINGACCOUNT_H__

#include "BankAccount.hpp" // Base class

class CheckingAccount : public BankAccount
{
private:
	double transactionFee;

public:
	CheckingAccount(std::string accountNumber, double balance, double transactionFee) :
		BankAccount(accountNumber, balance), transactionFee(transactionFee)
	{
	}

	void deductTransactionFee()
	{
		balance -= transactionFee;
	}

	void displayInfo() override
	{
		BankAccount::displayInfo(); // print account number and balance info
		std::cout << "============" << std::endl;
		std::cout << "Transaction Fee: " << transactionFee << std::endl;
	}
};
#endif // __CHECKINGACCOUNT_H__