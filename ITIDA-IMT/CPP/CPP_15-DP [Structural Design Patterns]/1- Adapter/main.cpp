#include <iostream>

// Target interface
class Printer
{
private:
	/* data */
public:
	virtual void printDocument() = 0;
};

// Adoptee class
class LegacyPrinter
{
private:
	/* data */
public:
	void LegacyPrint()
	{
		std::cout << "Printing document in legacy printer" << std::endl;
	}
};

// Adapter class
class LegacyPrinterAdapter : public Printer
{
private:
	LegacyPrinter legacyPrinter;

public:
	void printDocument() override
	{
		legacyPrinter.LegacyPrint();
	}
};

// Adoptee class
class NewPrinter
{
private:
	/* data */
public:
	void NewPrint()
	{
		std::cout << "Printing document in new printer" << std::endl;
	}
};

// Adapter class
class NewPrinterAdapter : public Printer
{
private:
	NewPrinter newPrinter;

public:
	void printDocument() override
	{
		newPrinter.NewPrint();
	}
};

void printDocument(Printer& printer)
{
	printer.printDocument();
}

int main()
{
	LegacyPrinterAdapter legacyPrinterAdapter;
	
	printDocument(legacyPrinterAdapter);

	NewPrinterAdapter newPrinterAdapter;
	printDocument(newPrinterAdapter);

	return 0;
}