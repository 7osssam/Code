#ifndef BANKACCOUNT_HPP
#define BANKACCOUNT_HPP

#include <string>

class BankAccount
{
private:
	int			accountNumber;
	std::string accountHolder;
	std::string accountType;
	double		accountBalance;

public:
	BankAccount(int accountNumber = 0, const std::string& accountHolder = "",
				const std::string& accountType = "", double accountBalance = 0.0);
	void			   deposit(double& amount);
	bool			   withdraw(double& amount);
	int				   getAccountNumber() const;
	const std::string& getAccountHolder() const;
	const std::string& getAccountType() const;
	double			   getAccountBalance() const;
	void			   displayAccountInfo() const;
};

#endif // BANKACCOUNT_HPP
