#include <iostream>
#include <string>
#include <memory>

// Mediator Interface
class Marketplace
{
public:
	virtual void sell(const std::string& product, float price) = 0;
	virtual void buy(const std::string& product) = 0;
};

// Colleague Interface
class User
{
public:
	virtual void sell(const std::string& product, float price) = 0;
	virtual void buy(const std::string& product) = 0;
};

// Concrete Colleague
class Seller : public User
{
private:
	std::shared_ptr<Marketplace> marketplace;

public:
	Seller(std::shared_ptr<Marketplace> marketplace) : marketplace(marketplace)
	{
	}

	void sell(const std::string& product, float price) override
	{
		marketplace->sell(product, price);
	}

	void buy(const std::string& product) override
	{
		std::cout << "Seller cannot buy products.\n";
	}
};

class Buyer : public User
{
private:
	std::shared_ptr<Marketplace> marketplace;

public:
	Buyer(std::shared_ptr<Marketplace> marketplace) : marketplace(marketplace)
	{
	}

	void sell(const std::string& product, float price) override
	{
		std::cout << "Buyer cannot sell products.\n";
	}

	void buy(const std::string& product) override
	{
		marketplace->buy(product);
	}
};

// Concrete Mediator
class OnlineMarketplace : public Marketplace
{
public:
	void sell(const std::string& product, float price) override
	{
		std::cout << "Product " << product << " is listed for sale at price " << price << ".\n";
	}

	void buy(const std::string& product) override
	{
		std::cout << "Product " << product << " is purchased.\n";
	}
};

int main()
{
	auto marketplace = std::make_shared<OnlineMarketplace>();

	Seller seller(marketplace);
	Buyer  buyer(marketplace);

	seller.sell("Book", 10.0f);
	buyer.buy("Book");

	return 0;
}