#include <iostream>
#include <thread>
#include <mutex>

class BankAccount
{
protected:
	double	   balance_;
	std::mutex BankAccountMutex_;

public:
	BankAccount(double balance) : balance_(balance)
	{
	}

	void deposit(double amount)
	{
		std::lock_guard<std::mutex> lock(BankAccountMutex_);
		std::cout << "Thread ID: " << std::this_thread::get_id() << '\n';
		std::cout << __func__ << " " << amount << '\n';
		balance_ += amount;
	}

	void withdraw(double amount)
	{
		std::lock_guard<std::mutex> lock(BankAccountMutex_);
		std::cout << "Thread ID: " << std::this_thread::get_id() << '\n';
		std::cout << __func__ << " " << amount << '\n';

		if (balance_ >= amount)
		{
			balance_ -= amount;
		}
		else
		{
			std::cerr << "Error: Not enough balance\n";
		}
	}

	double getBalance() const
	{
		//std::lock_guard<std::mutex> lock(BankAccountMutex_);
		return balance_;
	}
};

class testclass
{
private:
	/* data */
	int		   a_;
	std::mutex testMutex_{};

public:
	testclass(int a) : a_(a)
	{
	}
	~testclass()
	{
	}

	void print(int num)
	{
		// lock
		std::lock_guard<std::mutex> lock{testMutex_};
		std::cout << "a: " << a_ << " num: " << num << std::endl;
		// id
		std::cout << "Thread ID: " << std::this_thread::get_id() << std::endl;
	}
};

int main()
{
	// a bank account with 1000 balance as initial amount
	BankAccount account{1000};

	std::thread depositThread(&BankAccount::deposit, &account, 500);
	std::thread depositThread_2(&BankAccount::deposit, &account, 350);

	std::thread withdrawThread(&BankAccount::withdraw, &account, 50);
	std::thread withdrawThread_2(&BankAccount::withdraw, &account, 100);

	depositThread.join();
	withdrawThread.join();
	depositThread_2.join();
	withdrawThread_2.join();

	// Final balance should be 1000 + 500 + 350 - 50 - 100 = 1700
	std::cout << "Final balance: " << account.getBalance() << '\n';

	return 0;
}