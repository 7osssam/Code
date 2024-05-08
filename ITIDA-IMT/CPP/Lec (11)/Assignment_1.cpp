#include <iostream>
#include <vector>
#include <numeric>
#include <array>

int main()
{
	std::vector<int> numbers = {10, 20, 30, 40, 50};

	numbers.push_back(60);

	std::cout << "After adding 60: " << std::endl;
	for (const auto& number: numbers)
	{
		std::cout << number << std::endl;
	}

	std::array<float, 5> grades;

	for (auto& grade: grades)
	{
		std::cout << "Enter a grade: ";
		std::cin >> grade;
	}

	float average = std::accumulate(grades.begin(), grades.end(), 0.0f) / grades.size();
	std::cout << "Average grade: " << average << std::endl;

	if (numbers.size() > 1)
	{
		numbers.erase(numbers.begin() + 1);
	}

	std::cout << "After removing the second element: " << std::endl;
	for (const auto& number: numbers)
	{
		std::cout << number << std::endl;
	}

	return 0;
}