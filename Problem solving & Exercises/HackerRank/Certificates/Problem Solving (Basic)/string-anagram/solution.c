#include <stdio.h>
#include <string.h>

int stringAnagram(char **dictionary, int dictionaryCount, char **query, int queryCount)
{
	int result[queryCount];
	int i, j, k;

	// Iterate over each query
	for (i = 0; i < queryCount; i++)
	{
		result[i] = 0;
		int queryLen = strlen(query[i]);

		// Sort the characters of the query string
		char sortedQuery[queryLen + 1];
		strcpy(sortedQuery, query[i]);
		qsort(sortedQuery, queryLen, sizeof(char), strcmp);

		// Iterate over each word in the dictionary
		for (j = 0; j < dictionaryCount; j++)
		{
			int dictLen = strlen(dictionary[j]);

			// Check if the lengths of query and dictionary word are equal
			if (dictLen == queryLen)
			{
				// Sort the characters of the dictionary word
				char sortedDict[dictLen + 1];
				strcpy(sortedDict, dictionary[j]);
				qsort(sortedDict, dictLen, sizeof(char), strcmp);

				// Check if the sorted characters of query and dictionary word are equal
				if (strcmp(sortedQuery, sortedDict) == 0)
				{
					result[i]++;
				}
			}
		}
	}

	// Print the result
	for (k = 0; k < queryCount; k++)
	{
		printf("%d\n", result[k]);
	}

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
		scanf("%s", dictionary[i]);
	}

	int queryCount;
	scanf("%d", &queryCount);

	// Read the query strings
	char **query = (char **)malloc(queryCount * sizeof(char *));
	for (int i = 0; i < queryCount; i++)
	{
		query[i] = (char *)malloc(16 * sizeof(char));
		scanf("%s", query[i]);
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
