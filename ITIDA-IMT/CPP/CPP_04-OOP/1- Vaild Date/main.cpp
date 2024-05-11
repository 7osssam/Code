#include "DateClass.hpp"
#include <iostream>
#include <cassert>

// Unit tests for the is_valid() function
void testDateValidation()
{
	// Valid dates
	assert(Date(1, 1, 2022).is_valid());   // First day of the year
	assert(Date(31, 1, 2022).is_valid());  // Last day of January
	assert(Date(28, 2, 2021).is_valid());  // Last day of February (non-leap year)
	assert(Date(29, 2, 2020).is_valid());  // Last day of February (leap year)
	assert(Date(30, 4, 2022).is_valid());  // Last day of April
	assert(Date(31, 12, 2022).is_valid()); // Last day of the year

	// Invalid dates
	assert(!Date(0, 1, 2022).is_valid());  // Day is less than 1
	assert(!Date(32, 1, 2022).is_valid()); // Day is greater than 31
	assert(!Date(29, 2, 2021).is_valid()); // February 29 in a non-leap year
	assert(!Date(31, 4, 2022).is_valid()); // April 31
	assert(!Date(29, 2, 1900).is_valid()); // February 29 in a year not divisible by 4
	assert(!Date(29, 2, 2100).is_valid()); // February 29 in a year divisible by 100 but not 400

	std::cout << "==== All tests passed ====\n";
}

int main()
{
	testDateValidation();
	Date date;
	int	 day, month, year;

	std::cout << "Input day: ";
	std::cin >> day;
	date.set_day(day);

	std::cout << "Input month: ";
	std::cin >> month;
	date.set_month(month);

	std::cout << "Input year: ";
	std::cin >> year;
	date.set_year(year);

	std::cout << "Date: " << date.get_day() << "/" << date.get_month() << "/" << date.get_year() << "\n";

	if (date.is_valid())
	{
		std::cout << "The date is valid.\n";
	}
	else
	{
		std::cout << "The date is not valid.\n";
	}

	return 0;
}
