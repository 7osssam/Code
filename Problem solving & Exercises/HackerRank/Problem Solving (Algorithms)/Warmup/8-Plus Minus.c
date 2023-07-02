/*
 ? Link: https://www.hackerrank.com/challenges/plus-minus/problem
 * Difficulty: Easy
 * Name: Plus Minus
 *
 * Tags: Algorithms, Warmup
 *
 * Summary:
 * print the ratio of positive, negative and zero elements in an array
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int arr_size;
	scanf("%d", &arr_size);

	// dynamic array allocation for
	signed int *arr = (signed int *)malloc(arr_size * sizeof(int));

	// scan array elements
	for (int i = 0; i < arr_size; i++)
	{
		scanf("%d", &arr[i]);
	}

	int zero = 0, positive = 0, negative = 0; // zero, positive and negative numbers counters

	for (int i = 0; i < arr_size; i++)
	{
		if (arr[i] > 0)
		{
			positive++;
			continue; // skip the rest of the loop
		}
		if (arr[i] == 0)
		{
			zero++;
			continue; // skip the rest of the loop
		}

		if (arr[i] < 0)
		{
			negative++;
			continue; // skip the rest of the loop
		}
	}
	// print the ratios of positive, negative and zero numbers
	// we need to cast the result to float to get the correct ratio
	printf("%.6f\n%.6f\n%.6f\n", (float)positive / arr_size, (float)negative / arr_size, (float)zero / arr_size);

	return 0;
}
