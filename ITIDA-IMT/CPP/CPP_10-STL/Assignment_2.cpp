#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cassert>

// Function to find the maximum element in a vector
int findMaxElement(const std::vector<int>& vec)
{
	auto pos = std::max_element(std::begin(vec), std::end(vec));
	return *pos;
}

// Function to reverse a vector
std::vector<char> reverseVector(const std::vector<char>& vec)
{
	std::vector<char> reversed(vec);
	std::reverse(reversed.begin(), reversed.end());
	return reversed;
}

// Function to remove duplicates from a vector
std::vector<std::string> removeDuplicates(std::vector<std::string> vec)
{
	std::sort(std::begin(vec), std::end(vec));
	//vec.erase(std::unique(vec.begin(), vec.end()), vec.end());

	auto pos = std::unique(std::begin(vec), std::end(vec));
	vec.erase(pos, std::end(vec));
	return vec;
}

// Function to count occurrences of a value in a vector
int countOccurrences(const std::vector<int>& vec, int value)
{
	auto n = std::count(std::begin(vec), std::end(vec), value);
	return n;
	// return static_cast<int>(n);
}

// Function to sort a vector in ascending order
void sortVector(std::vector<float>& vec)
{
	std::sort(std::begin(vec), std::end(vec));
}

// Function to find the median of a vector
float findMedian(std::vector<int> vec)
{
	float median = 0.0f;
	std::sort(std::begin(vec), std::end(vec));
	int middleIndex = vec.size() / 2;

	// if even number of elements return the average of the two middle elements.
	if (vec.size() % 2 == 0)
	{
		// middleIndex - 1 is the first middle element and middleIndex is the second middle element.
		// The average of the two middle elements is the median.
		median = (vec[middleIndex - 1] + vec[middleIndex]) / 2.0;
	}
	else
	{
		median = vec[middleIndex];
	}
	return median;
}

void test_findMaxElement()
{
	std::vector<int> vec1 = {3, 5, 2, 8, 1, 9};
	assert(findMaxElement(vec1) == 9);

	std::cout << "====== Testing findMaxElement() Passed ======" << std::endl;
}

void test_reverseVector()
{
	std::vector<char> vec1 = {'a', 'b', 'c', 'd', 'e'};
	std::vector<char> reversed = reverseVector(vec1);
	std::vector<char> expected = {'e', 'd', 'c', 'b', 'a'};
	assert(reversed == expected);

	std::cout << "====== Testing reverseVector() Passed ======" << std::endl;
}

void test_removeDuplicates()
{
	std::vector<std::string> vec1 = {"apple", "banana", "apple", "orange", "banana", "kiwi"};
	std::vector<std::string> result = removeDuplicates(vec1);
	std::vector<std::string> expected = {"apple", "banana", "kiwi", "orange"};
	assert(result == expected);

	std::cout << "====== Testing removeDuplicates() Passed ======" << std::endl;
}

void test_countOccurrences()
{
	std::vector<int> vec1 = {3, 5, 2, 8, 1, 9, 3, 3, 5, 3};
	assert(countOccurrences(vec1, 3) == 4);

	std::cout << "====== Testing countOccurrences() Passed ======" << std::endl;
}

void test_sortVector()
{
	std::vector<float> vec1 = {3.5f, 5.2f, 2.8f, 8.1f, 9.9f};
	sortVector(vec1);
	std::vector<float> expected = {2.8f, 3.5f, 5.2f, 8.1f, 9.9f};
	assert(vec1 == expected);

	std::cout << "====== Testing sortVector() Passed ======" << std::endl;
}

void test_findMedian()
{
	std::vector<int> vec1 = {3, 5, 2, 8, 1, 9};
	assert(findMedian(vec1) == 4.0f);

	std::vector<int> vec2 = {3, 5, 2, 8, 1, 9, 4};
	assert(findMedian(vec2) == 4.0f);

	std::cout << "====== Testing findMedian() Passed ======" << std::endl;
}

int main()
{
	test_findMaxElement();
	test_reverseVector();
	test_removeDuplicates();
	test_countOccurrences();
	test_sortVector();
	test_findMedian();

	return 0;
}