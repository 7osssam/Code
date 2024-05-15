#include <iostream>
#include <string>
#include <vector>

// Vehicle Base Class
class Vehicle
{
protected:
	std::string model;
	std::string color;
	int			year;

public:
	Vehicle(const std::string& model, const std::string& color, int year) :
		model(model), color(color), year(year)
	{
	}
	std::string getModel() const
	{
		return model;
	}
	std::string getColor() const
	{
		return color;
	}
	int getYear() const
	{
		return year;
	}
	virtual double calculateRentalCost(int days) const = 0;
};

// Derived Classes
class Car : public Vehicle
{
public:
	Car(const std::string& model, const std::string& color, int year) : Vehicle(model, color, year)
	{
	}
	double calculateRentalCost(int days) const override
	{
		return days * 20.0; // $20 per day
	}
};

class Motorcycle : public Vehicle
{
public:
	Motorcycle(const std::string& model, const std::string& color, int year) : Vehicle(model, color, year)
	{
	}
	double calculateRentalCost(int days) const override
	{
		return days * 15.0; // $15 per day
	}
};

// New type of vehicle
class Truck : public Vehicle
{
public:
	Truck(const std::string& model, const std::string& color, int year) : Vehicle(model, color, year)
	{
	}
	double calculateRentalCost(int days) const override
	{
		return days * 30.0; // $30 per day
	}
};

class RentalSystem
{
public:
	double calculateTotalRentalCost(const std::vector<Vehicle*>& vehicles, int days)
	{
		double totalCost = 0.0;
		for (const auto& vehicle: vehicles)
		{
			totalCost += vehicle->calculateRentalCost(days);
		}
		return totalCost;
	}
};

int main()
{
	Car		   car("Toyota", "Red", 2020);
	Motorcycle motorcycle("Harley", "Black", 2019);

	std::vector<Vehicle*> vehicles = {&car, &motorcycle};

	RentalSystem rentalSystem;
	double		 totalCost = rentalSystem.calculateTotalRentalCost(vehicles, 5);

	std::cout << "Total Rental Cost: $" << totalCost << std::endl;

	// adding new type of vehicle
	std::cout << "Adding new type of vehicle" << std::endl;
	Truck truck("Ford", "White", 2021);
	vehicles.push_back(&truck);

	totalCost = rentalSystem.calculateTotalRentalCost(vehicles, 5);
	std::cout << "Total Rental Cost: $" << totalCost << std::endl;

	return 0;
}