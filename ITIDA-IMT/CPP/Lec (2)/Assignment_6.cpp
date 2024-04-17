#include <iostream>
#include <vector>
#include <cctype>

// pass by reference to modify the original vector
std::vector<std::string> capitalizeFirstChar(std::vector<std::string>& vect)
{
	// loop through the vector of strings
	for (auto& str: vect)
	{
		// if the string is not empty
		if (str.size() > 0)
		{
			// capitalize the first character
			str[0] = std::toupper(str[0]);
		}
	}
	return vect;
}

int main()
{
	std::string line;
	std::cout << "Enter a line of text: ";
	std::getline(std::cin, line);

	// this is like an array of strings that stores the words of the line
	std::vector<std::string> words;

	// loop through the line and store the words in the vector
	for (size_t i = 0; i < line.size(); i++)
	{
		std::string Temp_word;

		// while the character is not a space and we haven't reached the end of the line
		while (line[i] != ' ' && i < line.size())
		{
			// Temp_word += line[i];
			Temp_word.push_back(line[i]); // push the character to the Temp_word

			i++;
		}
		words.push_back(Temp_word);		  // push the Temp_word to the words vector
	}

	words = capitalizeFirstChar(words);

	std::cout << "Capitalized words: ";
	// loop through the vector of strings and print the words
	for (const auto& str: words)
	{
		std::cout << str << " ";
	}
	std::cout << std::endl;

	return 0;
}
