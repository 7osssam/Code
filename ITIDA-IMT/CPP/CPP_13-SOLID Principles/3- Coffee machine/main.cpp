#include <iostream>

class Coffee
{
public:
	virtual std::string brew() const = 0;
};

class Espresso : public Coffee
{
public:
	std::string brew() const override
	{
		return "Brewing an espresso.";
	}
};

class Americano : public Coffee
{
public:
	std::string brew() const override
	{
		return "Brewing an Americano.";
	}
};

class CoffeeMachine
{
public:
	void brewCoffee(const Coffee& coffee)
	{
		std::cout << coffee.brew() << std::endl;
	}
};

int main()
{
	Espresso	  espresso;
	Americano	  coffee;
	CoffeeMachine machine;
	machine.brewCoffee(coffee);
	machine.brewCoffee(espresso);
	return 0;
}