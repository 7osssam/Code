#include <iostream>
#include <string>

#include "LibraryCatalog.hpp"

enum Options
{
	ADD_BOOK = 1,
	SEARCH_BY_AUTHOR,
	DISPLAY_CATALOG,
	QUIT
};

void get_valid_year(int& year)
{
	while (true)
	{
		std::cin >> year;
		if (year < 0)
		{
			std::cout << "Invalid year. Please enter a valid year: ";
		}
		else
		{
			break;
		}
	}
}

int main()
{
	LibraryCatalog catalog;
	int			   choice;
	//Options choice;
	do
	{
		std::cout << "1. Add book\n2. Search by author\n3. Display catalog\n4. Quit\n";
		std::cin >> choice;
		std::cin.ignore(); // ignore the newline character
		switch (choice)
		{
			case ADD_BOOK:
			{
				std::string title{};
				std::string author{};
				int			year{};

				std::cout << "Enter title: ";
				std::getline(std::cin, title);

				std::cout << "Enter author: ";
				std::getline(std::cin, author);

				std::cout << "Enter year: ";
				get_valid_year(year);

				catalog.add_book(title, author, year);
				break;
			}
			case SEARCH_BY_AUTHOR:
			{
				std::string author;
				std::cout << "Enter author: ";
				std::cin >> author;
				catalog.search_by_author(author);
				break;
			}
			case DISPLAY_CATALOG:
				catalog.display_catalog();
				break;
			case QUIT:
				break;
			default:
				std::cout << "Invalid choice.\n";
		}
	} while (choice != QUIT);
	return 0;
}