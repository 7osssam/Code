#include <iostream>

int main()
{
	int numbers[5];
	int max = 0;

	std::cout << "Enter 5 numbers: ";

	for (int i = 0; i < 5; i++)
	{
		std::cin >> numbers[i];
		if (numbers[i] > max)
		{
			max = numbers[i];
		}
	}

	std::cout << "The maximum number is: " << max << std::endl;

	return 0;
}
