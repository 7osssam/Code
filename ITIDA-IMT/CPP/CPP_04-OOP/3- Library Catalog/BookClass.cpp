#include <iostream>
#include "BookClass.hpp"

void Book::display_info() const
{
	std::cout << std::endl;
	std::cout << "Title: " << title << std::endl;
	std::cout << "Author: " << author << std::endl;
	std::cout << "Year: " << year << std::endl;
	std::cout << std::endl;
}