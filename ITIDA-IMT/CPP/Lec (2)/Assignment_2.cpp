#include <iostream>

void DiamondStarPattern(int rows)
{
	// Loop through rows
	for (int row = 1; row <= rows; ++row)
	{
		// Loop through spaces
		for (int space = 1; space <= rows - row; ++space)
		{
			// Print space
			std::cout << " ";
		}

		// Loop through stars
		for (int star = 1; star <= 2 * row - 1; ++star)
		{
			// Print star
			std::cout << "*";
		}

		std::cout << std::endl;
	}

	// Loop through rows
	for (int row = rows - 1; row >= 1; --row)
	{
		// Loop through spaces
		for (int space = 1; space <= rows - row; ++space)
		{
			// Print space
			std::cout << " ";
		}

		// Loop through stars
		for (int star = 1; star <= 2 * row - 1; ++star)
		{
			// Print star
			std::cout << "*";
		}

		std::cout << std::endl;
	}
}

int main()
{
	int rows;

	std::cout << "Enter number of rows (Half of the diamond): ";
	std::cin >> rows;

	DiamondStarPattern(rows);

	return 0;
}
