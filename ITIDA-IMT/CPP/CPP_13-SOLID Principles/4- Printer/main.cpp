#include <iostream>

class Printer
{
public:
	virtual void print() const = 0;
};

class InkjetPrinter : public Printer
{
public:
	void print() const override
	{
		std::cout << "Printing using an inkjet printer." << std::endl;
	}
};

class LaserPrinter : public Printer
{
public:
	void print() const override
	{
		std::cout << "Printing using a laser printer." << std::endl;
	}
};

int main()
{
	InkjetPrinter inkjetPrinter;
	LaserPrinter  laserPrinter;
	inkjetPrinter.print();
	laserPrinter.print();
	return 0;
}