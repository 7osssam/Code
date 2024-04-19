#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

void removeDuplicates(std::vector<int>& numbers)
{
	std::vector<int> uniqueNumbers;

	// Sort numbers
	std::sort(numbers.begin(), numbers.end());

	// Using iterator
	for (auto it = numbers.begin(); it != numbers.end(); ++it)
	{
		// If the current element is not equal to the next element
		// and the next element is not the end of the vector
		if ((it + 1) == numbers.end() || *it != *(it + 1))
		{
			uniqueNumbers.push_back(*it);
		}
	}

	numbers = uniqueNumbers;

	// Resizes the vector to avoid memory leaks
	numbers.resize(uniqueNumbers.size());
}

void testRemoveDuplicates()
{
	// Test Case 1
	std::vector<int> numbers = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
	std::vector<int> expected = {1, 2, 3, 4, 5};
	removeDuplicates(numbers);
	assert(numbers == expected);

	// Test Case 2
	numbers = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	expected = {1};
	removeDuplicates(numbers);
	assert(numbers == expected);

	// Test Case 3
	numbers = {1, 2, 3, 4, 5};
	expected = {1, 2, 3, 4, 5};
	removeDuplicates(numbers);
	assert(numbers == expected);

	// Test Case 4
	numbers = {1, 2, 3, 4, 5, 5, 4, 3, 2, 1};
	expected = {1, 2, 3, 4, 5};
	removeDuplicates(numbers);
	assert(numbers == expected);

	std::cout << "====== All tests passed ======" << std::endl;
}

int main()
{
	// @unit test
	testRemoveDuplicates();

	std::vector<int> numbers;
	int				 num;

	int size;
	std::cout << "Enter the size of the array: ";
	std::cin >> size;

	std::cout << "Enter the elements of the array: ";
	for (int i = 0; i < size; ++i)
	{
		std::cin >> num;
		numbers.push_back(num);
	}

	removeDuplicates(numbers);

	for (const auto& num: numbers)
	{
		std::cout << num << " ";
	}

	std::cout << std::endl;

	return 0;
}