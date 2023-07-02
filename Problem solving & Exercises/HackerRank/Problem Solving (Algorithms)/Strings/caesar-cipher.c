/*
 ? Link: https://www.hackerrank.com/challenges/caesar-cipher-1/problem
 * Difficulty: Easy
 * Name: Caesar Cipher
 *
 * Tags: Algorithms, Strings
 *
 * Notes:
 * - This problem is about shifting the letters of a string by a certain number of places in the alphabet.
 * - If the shift is greater than 26, then the shift is the remainder of the division of the shift by 26.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *caesarCipher(char *str, int k)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if ((str[i] >= 'a') && (str[i] <= 'z'))
		{
			if (str[i] + k > 'z')
			{
				str[i] = str[i] - (26 - k);
			}
			else
			{
				str[i] = str[i] + k;
			}
		}
		if ((str[i] >= 'A' && str[i] <= 'Z'))
		{
			if (str[i] + k > 'Z')
			{
				str[i] = str[i] - (26 - k);
			}
			else
			{
				str[i] = str[i] + k;
			}
		}
	}
	return str;
}

int main()
{
	int n;
	scanf("%d", &n);

	char *str = (char *)malloc(n * sizeof(char));
	char *encrypted = (char *)malloc(n * sizeof(char));
	scanf("%s", str);

	int k;
	scanf("%d", &k);

	while (k > 26)
	{
		k -= 26;
	}

	// printf("%d\n" , k); testing
	encrypted = caesarCipher(str, k);

	puts(encrypted);
	return 0;
}