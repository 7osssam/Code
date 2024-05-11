#ifndef __BANKACCOUNTFACTORY_H__
#define __BANKACCOUNTFACTORY_H__

#include "CheckingAccount.hpp"
#include "SavingsAccount.hpp"

enum class AccountType
{
	Checking,
	Savings,
	Unknown
};

class BankAccountFactory
{
public:
	static BankAccount* createAccount(AccountType type, int accountNumber, std::string accountHolder,
									  double balance, double transactionFee = 0.0, double interestRate = 0.0)
	{
		switch (type)
		{
			case AccountType::Checking:
				return new CheckingAccount(accountNumber, accountHolder, balance, transactionFee);
			case AccountType::Savings:
				return new SavingsAccount(accountNumber, accountHolder, balance, interestRate);
			default:
				return nullptr;
		}
	}
};

#endif // __BANKACCOUNTFACTORY_H__