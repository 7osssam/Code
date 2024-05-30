#include <iostream>
#include <string>

// Product
class Car
{
private:
	std::string Make;
	std::string Model;
	std::string Year;
	std::string Color;

public:
	// setters
	void setMake(std::string str)
	{
		Make = str;
	}
	void setModel(std::string str)
	{
		Model = str;
	}
	void setYear(std::string str)
	{
		Year = str;
	}
	void setColor(std::string str)
	{
		Color = str;
	}

	void showCar()
	{
		std::cout << "==========================" << std::endl;
		std::cout << "Make " << Make << std::endl;
		std::cout << "Model " << Model << std::endl;
		std::cout << "Year " << Year << std::endl;
		std::cout << "Color " << Color << std::endl;
		std::cout << "==========================" << std::endl;
	}
};
// Builder abstract
class CarBuilderAbstract
{
private:
public:
	virtual void BuildMake() = 0;
	virtual void BuildModel() = 0;
	virtual void BuildYear() = 0;
	virtual void BuildColor() = 0;
	virtual Car	 GetProduct() = 0;
};

// Concraete builder for product
class SedanBuilder : public CarBuilderAbstract
{
private:
	Car Product;

public:
	void BuildMake() override
	{
		Product.setMake("Toyota");
	}
	void BuildModel() override
	{
		Product.setModel("Corolla");
	}

	void BuildYear() override
	{
		Product.setYear("2021");
	}

	void BuildColor() override
	{
		Product.setColor("Black");
	}

	Car GetProduct() override
	{
		return Product;
	}
};

// Concraete builder for product
class SUVBuiler : public CarBuilderAbstract
{
private:
	Car Product;

public:
	void BuildMake() override
	{
		Product.setMake("BMW");
	}
	void BuildModel() override
	{
		Product.setModel("X6");
	}

	void BuildYear() override
	{
		Product.setYear("2024");
	}

	void BuildColor() override
	{
		Product.setColor("Black");
	}

	Car GetProduct() override
	{
		return Product;
	}
};

// Director (optinal)
class CarManufacturer
{
private:
	/* data */
public:
	Car designCar(CarBuilderAbstract& builder)
	{
		builder.BuildMake();
		builder.BuildModel();
		builder.BuildYear();
		builder.BuildColor();

		return builder.GetProduct();
	}
};

int main()
{
	CarManufacturer car_manufacturer;

	SedanBuilder sedan_builder;
	auto		 sedan = car_manufacturer.designCar(sedan_builder);
	sedan.showCar();

	// New car builder
	SUVBuiler suv_builder;
	auto	  suv = car_manufacturer.designCar(suv_builder);
	suv.showCar();

	return 0;
}