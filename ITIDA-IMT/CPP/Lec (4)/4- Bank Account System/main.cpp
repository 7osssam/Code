#include "Bank.hpp"
#include <iostream>
#include <string>
#include <cassert>

enum Option
{
	CREATE_ACCOUNT = 1,
	DEPOSIT_FUNDS,
	WITHDRAW_FUNDS,
	TOTAL_BALANCE,
	DISPLAY_ACCOUNTS,
	EXIT
};

void displayMenu()
{
	std::cout << "Menu:\n";
	std::cout << "1. Create an account\n";
	std::cout << "2. Deposit funds\n";
	std::cout << "3. Withdraw funds\n";
	std::cout << "4. Total balance\n";
	std::cout << "5. Display all accounts\n";
	std::cout << "6. Exit\n";
}

void HandleCreateAccount(Bank& bank_account)
{
	int			accountNumber;
	std::string accountHolder, accountType;
	double		accountBalance;

	std::cout << "Enter account number: ";
	std::cin >> accountNumber;
	std::cin.ignore(); // Clear newline from the input buffer

	std::cout << "Enter account holder: ";
	std::getline(std::cin, accountHolder);

	std::cout << "Enter account type: ";
	std::cin >> accountType;

	std::cout << "Enter initial account balance: ";
	std::cin >> accountBalance;

	BankAccount account(accountNumber, accountHolder, accountType, accountBalance);
	bank_account.addAccount(account);
	std::cout << "Account created successfully\n";

	// Sort the accounts by account number for better display and searching
	bank_account.SortAccounts();
}

void HandleDepositFunds(Bank& bank_account)
{
	int	   accountNumber;
	double amount;

	std::cout << "Enter account number: ";
	std::cin >> accountNumber;

	// Find the account by account number
	bool found = false;
	for (BankAccount& acc: bank_account.getAccounts())
	{
		if (acc.getAccountNumber() == accountNumber)
		{
			std::cout << "Enter deposit amount: ";
			std::cin >> amount;
			std::cin.ignore(); // Clear newline from the input buffer

			acc.deposit(amount);
			found = true;
			break;
		}
	}
	if (!found)
	{
		std::cerr << "Error: Account not found\n";
	}
}

void HandleWithdrawFunds(Bank& bank_account)
{
	int	   accountNumber;
	double amount;

	std::cout << "Enter account number: ";
	std::cin >> accountNumber;

	// Find the account by account number
	bool found = false;
	for (auto& acc: bank_account.getAccounts())
	{
		if (acc.getAccountNumber() == accountNumber)
		{
			std::cout << "Enter withdrawal amount: ";
			std::cin >> amount;
			std::cin.ignore(); // Clear newline from the input buffer

			if (acc.withdraw(amount))
			{
				std::cout << "Withdrawal successful\n";
			}
			found = true;
			break;
		}
	}
	if (!found)
	{
		std::cerr << "Error: Account not found\n";
	}
}

void test_BankAccountSystem()
{
	Bank bank_account = Bank{};

	double acc1_amount = 1000.0;
	double acc2_amount = 2000.0;

	double TotalBalance = 0.0;

	double deposit_test = 0.0;
	double withdraw_test = 0.0;

	// Test creating an account
	BankAccount account1{123, "Hossam", "SILVER", acc1_amount};

	assert(account1.getAccountBalance() == acc1_amount);

	// Test depositing funds
	deposit_test = 500.0;
	account1.deposit(deposit_test);
	acc1_amount += deposit_test;
	assert(account1.getAccountBalance() == acc1_amount);

	// Test withdrawing funds
	withdraw_test = 300.0;
	account1.withdraw(withdraw_test);
	acc1_amount -= withdraw_test;
	assert(account1.getAccountBalance() == acc1_amount);

	// Test adding an account to the bank and getting total balance
	bank_account.addAccount(account1);
	TotalBalance = acc1_amount;
	assert(bank_account.getTotalBalance() == TotalBalance);

	// Test creating another account
	BankAccount account2{456, "Kareem", "GOLD", acc2_amount};
	bank_account.addAccount(account2);
	TotalBalance += acc2_amount;
	assert(bank_account.getTotalBalance() == TotalBalance);

	// Test sorting accounts --> extra test
	bank_account.SortAccounts();
	const auto& accounts = bank_account.getAccounts();
	assert(accounts[0].getAccountNumber() == 123);
	assert(accounts[1].getAccountNumber() == 456);

	std::cout << "===== All tests passed =====\n";
}

int main()
{
	test_BankAccountSystem();
	Bank bank_account{};
	int	 choice;
	//Option choice; --> need opterator overloading for enum class

	do
	{
		displayMenu();
		std::cout << "Enter your choice: ";
		std::cin >> choice;
		std::cin.ignore(); // Clear newline from the input buffer

		switch (choice)
		{
			case Option::CREATE_ACCOUNT:
			{
				HandleCreateAccount(bank_account);
				break;
			}
			case Option::DEPOSIT_FUNDS:
			{
				HandleDepositFunds(bank_account);
				break;
			}
			case Option::WITHDRAW_FUNDS:
			{
				HandleWithdrawFunds(bank_account);
				break;
			}
			case Option::TOTAL_BALANCE:
			{
				std::cout << "Total balance of all accounts: $" << bank_account.getTotalBalance()
						  << std::endl;
				break;
			}
			case Option::DISPLAY_ACCOUNTS:
			{
				bank_account.displayAllAccounts();
				break;
			}
			case Option::EXIT:
				std::cout << "Exiting program...\n";
				break;
			default:
				std::cerr << "Invalid choice. Please try again.\n";
		}
	} while (choice != Option::EXIT);

	return 0;
}
