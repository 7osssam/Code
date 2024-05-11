#include <iostream>
#include <string>
//#include <algorithm> // For std::reverse

std::string ReverseString(const std::string& str)
{
	std::string reversed_str;

	for (size_t i = 0; i <= str.size(); i++)
	{
		int index = str.size() - i;
		reversed_str.push_back(str[index]);
	}

	return reversed_str;
}

int main()
{
	std::string str;
	std::cout << "Enter a string: ";
	std::getline(std::cin, str); // To read the entire line including spaces

	// Alternative solution:
	// Using the reverse function from the algorithm library
	//std::reverse(str.begin(), str.end());

	std::string reversed_str = ReverseString(str);

	std::cout << "Reversed string: " << reversed_str << std::endl;

	return 0;
}
