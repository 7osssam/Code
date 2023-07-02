/*
 ? Link: https://www.hackerrank.com/challenges/three-month-preparation-kit-camel-case/problem
 * Difficulty: Hard
 * Name:  CamelCase 4
 *
 * Tags: Algorithms, Strings
 *
 * Examples:
 * S;M;plasticCup() 		--> plastic cup
 * C;V;mobile phone 		--> mobilePhone
 * C;C;coffee machine 		--> CoffeeMachine
 * S;C;LargeSoftwareBook 	--> large software book
 * C;M;white sheet of paper --> whiteSheetOfPaper()
 * S;V;pictureFrame 		--> picture frame
 *
 * Notes:
 * S = split mode
 * C = combine mode
 *
 * V = variable -> lowerCamelCase
 * M = method 	-> lowerCamelCase + ()
 * C = class 	-> UpperCamelCase
 */
#include <stdio.h>
#include <string.h>

char *splitMode(char *str)
{
	static char CleanStr[100];
	int position = 0;
	int i = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + 32;
			if (i != 0)
			{
				CleanStr[position] = ' ';
				position++;
			}
		}
		if (str[i] == '(')
		{
			break;
		}
		CleanStr[position] = str[i];
		position++;
	}
	CleanStr[position] = '\0';

	return CleanStr;
}

char *combineMode(char *str, char type)
{
	static char CleanStr[100];
	int position = 0;
	int i = 0;

	if (type == 'C')
	{
		str[0] = str[0] - 32;
	}

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ')
		{
			i++;
			str[i] = str[i] - 32;
		}

		CleanStr[position] = str[i];
		position++;
	}

	if (type == 'M')
	{
		position = position - 1; // Adjust position by 1

		CleanStr[position++] = '('; // Add '(' before space
		CleanStr[position++] = ')'; // Add ')' after space
	}

	CleanStr[position] = '\0';

	return CleanStr;
}

int main()
{
	char str[100];
	char CleanStr[100];

	while (gets(str) != NULL) // fgets is not working
	{

		char operation = str[0]; // S or C
		char type = str[2];		 // M or C or V

		// copying in cleanStr
		int i = 0;
		int position = 4;
		while (str[position] != '\0')
		{
			CleanStr[i] = str[position];
			i++;
			position++;
		}
		CleanStr[i] = '\0'; // null at the end

		char *returnChar = NULL;

		if (operation == 'S') // split
		{
			returnChar = splitMode(CleanStr);
		}
		else if (operation == 'C') // combine
		{
			returnChar = combineMode(CleanStr, type);
		}

		puts(returnChar); // print the string
	}

	return 0;
}
