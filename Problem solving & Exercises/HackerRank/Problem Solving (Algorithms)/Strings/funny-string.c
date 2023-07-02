/*
 ? Link: https://www.hackerrank.com/challenges/funny-string/problem
 * Difficulty: Easy
 * Name: Funny String
 *
 * Tags: Algorithms, Strings
 *
 * Notes:
 * if the absolute difference between the ASCII values of the characters in
 * the reverse of the string is the same as the absolute difference between the ASCII values
 * of the characters in the original string, then it is funny. Otherwise, it is not.
 *
 */

#include <math.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *funnyString(char *s)
{
	int i = 0;
	int FunnyFlag = 1;
	int size = strlen(s);
	char OGs[size + 1];

	strcpy(OGs, s);

	while (i < (size / 2))
	{
		char temp = s[i];
		s[i] = s[size - 1 - i];
		s[size - 1 - i] = temp;

		i++;
	}

	i = 0;
	while (i < size - 1)
	{
		if (abs(OGs[i] - OGs[i + 1]) != abs(s[i] - s[i + 1]))
		{
			FunnyFlag = 0;
		}
		i++;
	}

	if (FunnyFlag == 0)
	{
		return "Not Funny";
	}
	else
	{
		return "Funny";
	}
}

int main()
{
	int q;
	scanf("%d", &q);

	for (int q_itr = 0; q_itr < q; q_itr++)
	{
		char *s = (char *)malloc(512000 * sizeof(char));

		scanf("%s", s);

		char *result = funnyString(s);

		printf("%s\n", result);
	}

	return 0;
}
