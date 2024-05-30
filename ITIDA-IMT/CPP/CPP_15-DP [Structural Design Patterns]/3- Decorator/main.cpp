#include <iostream>
#include <string>
#include <memory>

// Abstract Pizza class
class Pizza
{
public:
	virtual std::string getDescription() = 0;
	virtual double		getCost() = 0;
	virtual ~Pizza() = default; // Ensure proper cleanup of derived classes
};

// PlainPizza class
class PlainPizza : public Pizza
{
public:
	std::string getDescription() override
	{
		return "Plain Pizza";
	}

	double getCost() override
	{
		return 5.0;
	}
};

// Abstract PizzaDecorator class
class PizzaDecorator : public Pizza
{
protected:
	std::shared_ptr<Pizza> pizza;

public:
	PizzaDecorator(std::shared_ptr<Pizza> pizza) : pizza(std::move(pizza))
	{
	}
	virtual ~PizzaDecorator() = default; // Ensure proper cleanup of derived classes
};

// CheeseDecorator class
class CheeseDecorator : public PizzaDecorator
{
public:
	CheeseDecorator(std::shared_ptr<Pizza> pizza) : PizzaDecorator(std::move(pizza))
	{
	}

	std::string getDescription() override
	{
		return pizza->getDescription() + " + Cheese";
	}

	double getCost() override
	{
		return pizza->getCost() + 1.5;
	}
};

// PepperoniDecorator class
class PepperoniDecorator : public PizzaDecorator
{
public:
	PepperoniDecorator(std::shared_ptr<Pizza> pizza) : PizzaDecorator(std::move(pizza))
	{
	}

	std::string getDescription() override
	{
		return pizza->getDescription() + " + Pepperoni";
	}

	double getCost() override
	{
		return pizza->getCost() + 2.0;
	}
};

int main()
{
	std::shared_ptr<Pizza> pizza = std::make_shared<PlainPizza>();
	pizza = std::make_shared<CheeseDecorator>(pizza);
	pizza = std::make_shared<PepperoniDecorator>(pizza);

	std::cout << "Order: " << pizza->getDescription() << "\n";
	std::cout << "Cost: $" << pizza->getCost() << "\n";

	// No need to manually delete pizza, smart pointers handle it

	return 0;
}
