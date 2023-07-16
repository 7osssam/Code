#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to count the frequency of characters in a string
void countCharacters(const char *str, int *freq)
{
	while (*str)
	{
		freq[*str - 'a']++; // Increment the frequency of the corresponding character
		str++;
	}
}

int stringAnagram(char **dictionary, int dictionaryCount, char **query, int queryCount)
{
	int *result = (int *)calloc(queryCount, sizeof(int));

	// Precompute character frequencies for each word in the dictionary
	int **dictFreq = (int **)malloc(dictionaryCount * sizeof(int *));
	for (int i = 0; i < dictionaryCount; i++)
	{
		dictFreq[i] = (int *)calloc(26, sizeof(int));
		countCharacters(dictionary[i], dictFreq[i]);
	}

	// Iterate over each query
	for (int i = 0; i < queryCount; i++)
	{
		int queryLen = strlen(query[i]);
		int *queryFreq = (int *)calloc(26, sizeof(int));
		countCharacters(query[i], queryFreq);

		// Iterate over each word in the dictionary
		for (int j = 0; j < dictionaryCount; j++)
		{
			// Check if the lengths of query and dictionary word are equal
			if (strlen(dictionary[j]) == queryLen)
			{
				// Compare character frequencies
				int k;
				for (k = 0; k < 26; k++)
				{
					if (dictFreq[j][k] != queryFreq[k])
						break;
				}

				if (k == 26)
					result[i]++; // Increment the result counter if the words are anagrams
			}
		}

		free(queryFreq);
	}

	// Print the result
	for (int i = 0; i < queryCount; i++)
	{
		printf("%d\n", result[i]);
	}

	free(result);

	// Free the allocated memory
	for (int i = 0; i < dictionaryCount; i++)
	{
		free(dictFreq[i]);
	}
	free(dictFreq);

	return 0;
}

int main()
{
	int dictionaryCount;
	scanf("%d", &dictionaryCount);

	// Read the dictionary strings
	char **dictionary = (char **)malloc(dictionaryCount * sizeof(char *));
	for (int i = 0; i < dictionaryCount; i++)
	{
		dictionary[i] = (char *)malloc(16 * sizeof(char));
		scanf("%15s", dictionary[i]);
	}

	int queryCount;
	scanf("%d", &queryCount);

	// Read the query strings
	char **query = (char **)malloc(queryCount * sizeof(char *));
	for (int i = 0; i < queryCount; i++)
	{
		query[i] = (char *)malloc(16 * sizeof(char));
		scanf("%15s", query[i]);
	}

	// Call the stringAnagram function
	stringAnagram(dictionary, dictionaryCount, query, queryCount);

	// Free the allocated memory
	for (int i = 0; i < dictionaryCount; i++)
	{
		free(dictionary[i]);
	}
	free(dictionary);

	for (int i = 0; i < queryCount; i++)
	{
		free(query[i]);
	}
	free(query);

	return 0;
}
