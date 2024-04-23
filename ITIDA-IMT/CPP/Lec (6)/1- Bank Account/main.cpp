#include <iostream>
#include <string>

#include "CheckingAccount.hpp"
#include "SavingsAccount.hpp"

int main()
{
	std::cout << "======savings======" << std::endl;
	SavingsAccount savings("123456", 1000.0, 0.05);
	savings.calculateInterest();
	savings.displayInfo();

	std::cout << "======checking======" << std::endl;
	CheckingAccount checking("654321", 2000.0, 10.0);
	checking.deductTransactionFee();
	checking.displayInfo();

	return 0;
}