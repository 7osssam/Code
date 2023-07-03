/*
 ? Link: https://www.hackerrank.com/challenges/lonely-integer/problem
 * Difficulty: Easy
 * Name: Lonely Integer
 *
 * Tags: Algorithms, Bit Manipulation
 *
 * Summary:
 *  the idea is to use the XOR operator to find the unique number in the array
 *  XOR of a number with itself is 0 and XOR of a number with 0 is the number itself
 *  so if we XOR all the numbers in the array, the numbers that are repeated will cancel each other out
 *  and the only number that will remain is the unique number
 */

#include <stdio.h>
#include <stdlib.h>

int lonelyinteger(int a_count, int const *a)
{
	int result = 0;
	for (int i = 0; i < a_count; i++)
	{
		result ^= a[i]; // XOR the result with the current number
	}
	return result;
}

int main()
{
	int n;
	scanf("%d", &n);

	int *arr = (int *)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	printf("%d", lonelyinteger(n, arr));
	return 0;
}
