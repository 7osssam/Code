/*
 ? Link: https://www.hackerrank.com/challenges/divisible-sum-pairs/problem
 * Difficulty: Easy
 * Name: Divisible Sum Pairs
 *
 * Tags: Algorithms, Implementation
 *
 *
 */
#include <stdio.h>

int divisibleSumPairs(int n, int k, int const *ar)
{
	int counter = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if ((ar[i] + ar[j]) % k == 0)
			{
				counter++;
			}
		}
	}

	return counter;
}

int main()
{
	int n, k;

	// Get input for the size of the array (n) and the divisor (k)
	scanf("%d", &n);

	scanf("%d", &k);

	// Dynamically allocate memory for the array 'ar'
	int *ar = (int *)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &ar[i]);
	}

	// Call the divisibleSumPairs function to get the result
	int result = divisibleSumPairs(n, k, ar);

	// Display the result
	printf("%d", result);

	// Free dynamically allocated memory
	free(ar);

	return 0;
}
