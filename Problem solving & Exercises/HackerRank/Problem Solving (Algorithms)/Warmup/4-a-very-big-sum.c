/*
 ? Link: https://www.hackerrank.com/challenges/a-very-big-sum/problem
 * Difficulty: Easy
 * Name: A Very Big Sum
 *
 * Tags: Algorithms, Warmup
 *
 * Summary:
 * sum of array elements
 * + usage of long int to store the sum of the array elements
 */

#include <stdio.h>
#include <stdlib.h>

long aVeryBigSum(int size, long *arr)
{
	long sum = 0; // sum is a long int because the sum of the array elements can be very large
	for (int i = 0; i < size; i++)
	{
		sum = sum + arr[i];
	}
	return sum;
}

int main()
{
	int size;
	scanf("%d", &size);

	long *arr = (long *)malloc(size * sizeof(long));

	for (int i = 0; i < size; i++)
	{
		scanf("%ld", &arr[i]);
	}

	long result = aVeryBigSum(size, arr);

	printf("%ld\n", result);

	return 0;
}
