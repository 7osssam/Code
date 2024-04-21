#ifndef BANKACCOUNT_HPP
#define BANKACCOUNT_HPP

#include <string>
#include <iostream>
class BankAccount
{
private:
	int			accountNumber;
	std::string accountHolder;
	std::string accountType;
	double		accountBalance{};

public:
	// Default constructor
	BankAccount(int accountNumber, const std::string& accountHolder, const std::string& accountType,
				double accountBalance) :
		accountNumber(accountNumber), accountHolder(accountHolder), accountType(accountType),
		accountBalance(accountBalance)
	{
	}

	void			   deposit(double amount);
	bool			   withdraw(double amount);
	int				   getAccountNumber() const;
	const std::string& getAccountHolder() const;
	const std::string& getAccountType() const;
	double			   getAccountBalance() const;
	void			   displayAccountInfo() const;
};

#endif // BANKACCOUNT_HPP
