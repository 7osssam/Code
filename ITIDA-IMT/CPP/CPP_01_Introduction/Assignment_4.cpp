// Simple Binary Search Algorithm

#include <iostream>

int main()
{
	int numbers[10];
	std::cout << "Enter 10 numbers: ";
	for (int i = 0; i < 10; i++)
	{
		std::cin >> numbers[i];
	}

	int input;
	std::cout << "Enter a number to search: ";
	std::cin >> input;

	bool found = false;
	for (int i = 0; i < 10; i++)
	{
		if (numbers[i] == input)
		{
			std::cout << "Number " << input << " found at position: " << i + 1 << std::endl;
			found = true;
			break;
		}
	}

	if (!found)
	{
		std::cout << "Number not exist" << std::endl;
	}

	return 0;
}
