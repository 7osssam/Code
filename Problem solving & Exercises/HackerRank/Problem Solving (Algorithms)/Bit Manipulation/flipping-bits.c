/*
 ? Link: https://www.hackerrank.com/challenges/flipping-bits/problem
 * Difficulty: Easy
 * Name: Flipping bits
 *
 * Tags: Algorithms, Bit Manipulation
 *
 * Note:
 * just a simple XOR operation with 0xFFFFFFFF
 *
 */

#include <stdio.h>
#include <stdlib.h>

long flippingBits(long n) // time complexity O(1)
{
	unsigned long mask = 0xFFFFFFFF;

	n = n ^ mask; // using mask

	// n = (unsigned)~n; // alternative solution
	return n;
}

int main()
{
	int queries;
	scanf("%d", &queries);

	unsigned long *input = (unsigned long *)malloc(sizeof(unsigned long) * queries);
	unsigned long *output = (unsigned long *)malloc(sizeof(unsigned long) * queries);

	for (int i = 0; i < queries; i++)
	{
		scanf("%lu", &input[i]);
		output[i] = flippingBits(input[i]);
	}

	for (int i = 0; i < queries; i++)
	{
		printf("%lu\n", output[i]);
	}
	return 0;
}
