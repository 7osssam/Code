#include <iostream>
#include <string>

std::string insertSpace(const std::string& str)
{
	std::string result;
	// Loop through the string
	for (size_t i = 0; i < str.size(); ++i)
	{
		// Check if the current character is uppercase and the previous character is lowercase
		if (i > 0 && std::islower(str[i - 1]) && std::isupper(str[i]))
		{
			// Insert a space
			//result += ' '; // C style
			result.push_back(' ');
		}
		// if not insert the character as it is
		//result += str[i]; // C style
		result.push_back(str[i]);
	}
	return result;
}

int main()
{
	std::string str;
	std::cout << "Enter a string: ";
	std::getline(std::cin, str); // To read the entire line including spaces

	std::string result = insertSpace(str);

	std::cout << "Result: " << result << std::endl;

	return 0;
}
