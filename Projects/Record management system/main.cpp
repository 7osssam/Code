#include <iostream>
#include "Management.hpp"
#include <string>

// Overloading the >> operator to read the Option enum from the input stream.
std::istream& operator>>(std::istream& in, Option& option)
{
	int i;
	in >> i;
	option = static_cast<Option>(i);
	return in;
}

int main()
{
	Option option = Option::ADD_RECORD;

	std::cout << "Welcome to the record management system.\n";

	while (option != QUIT)
	{
		std::cout << "1. Add Record\n2. Fetch Record\n3. Quit\n";
		std::cin >> option;
		std::cin.ignore(); // Clear the newline character from the input buffer
		switch (option)
		{
			case Option::ADD_RECORD:
			{
				std::cout << "Enter name: ";
				std::string name;
				std::getline(std::cin, name); // Read the entire line, including spaces

				std::cout << "Enter age: ";
				int age;
				std::cin >> age;

				std::cin.ignore(); // Ignore the newline character in the input buffer
				std::cin.clear();
				AddRecord(name, age);
				break;
			}
			case Option::FETCH_RECORD:
			{
				std::cout << "Enter ID: ";
				int id;
				std::cin >> id;
				FetchRecord(id);
				break;
			}
			case Option::QUIT:
				std::cout << "Quitting...\n";
				break;
			default:
				std::cout << "----Invalid option----\n";
				break;
		}
	}
}
