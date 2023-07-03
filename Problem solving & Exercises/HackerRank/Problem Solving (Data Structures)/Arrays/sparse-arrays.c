/*
 ? Link: https://www.hackerrank.com/challenges/sparse-arrays/problem
 * Difficulty: Medium
 * Name: Sparse Arrays
 *
 * Tags: Data Structures, Arrays
 *
 * Summary:
 * Given an array of strings, return an array of the counts of each string in the original array.
 */

#include <stdio.h>
#include <stdlib.h> /* for calloc(), malloc(), realloc() */
#include <string.h> /* for strcmp() */

int *matchingStrings(int stringList_count, char **stringList, int queries_count, char **queries, int *result_count)
{
	*result_count = queries_count;

	int *result = calloc(queries_count, sizeof(int)); // use calloc to initialize the array with zeros

	// count the number of occurrences of each query in the string list
	for (int i = 0; i < queries_count; i++)
	{
		for (int j = 0; j < stringList_count; j++)
		{
			// if the query is found in the string list, increment the result array
			if (strcmp(queries[i], stringList[j]) == 0)
			{
				result[i]++;
			}
		}
	}

	return result;
}

int main()
{
	int stringList_count;
	scanf("%d", &stringList_count);

	// allocate memory for the string list (array of strings)
	char **stringList = malloc(stringList_count * sizeof(char *));

	for (int i = 0; i < stringList_count; i++)
	{
		stringList[i] = malloc(10240 * sizeof(char)); // 10240 is the maximum length of a string

		scanf("%s", stringList[i]);
	}

	int queries_count;
	scanf("%d", &queries_count);

	// allocate memory for the queries (array of strings)
	char **queries = malloc(queries_count * sizeof(char *));

	for (int i = 0; i < queries_count; i++)
	{
		queries[i] = malloc(10240 * sizeof(char));

		scanf("%s", queries[i]);
	}

	int res_count;
	int *res = matchingStrings(stringList_count, stringList, queries_count, queries, &res_count);

	for (int i = 0; i < res_count; i++)
	{
		// print the result array
		printf("%d\n", res[i]);
	}

	return 0;
}