
#include "../Bank.hpp"
#include <cassert>

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
	BankAccount account3{100, "Ahmed", "SILVER", 500.0};
	bank_account.addAccount(account3);
	bank_account.SortAccounts();
	const auto& accounts = bank_account.getAccounts();
	assert(accounts[0].getAccountNumber() == 100);
	assert(accounts[1].getAccountNumber() == 123);
	assert(accounts[2].getAccountNumber() == 456);

	std::cout << "\n===== All tests passed =====\n";
}

int main()
{
	test_BankAccountSystem();

	return 0;
}