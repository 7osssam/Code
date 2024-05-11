#include <iostream>

void NumberTrianglePattern(int rows)
{
	// Loop through rows
	for (int row = 1; row <= rows; ++row)
	{
		// Loop through columns
		for (int column = 1; column <= row; ++column)
		{
			// Print the column number
			std::cout << column << " ";
		}

		std::cout << std::endl;
	}
}

int main()
{
	int rows;

	std::cout << "Enter number of rows: ";
	std::cin >> rows;

	NumberTrianglePattern(rows);

	return 0;
}
