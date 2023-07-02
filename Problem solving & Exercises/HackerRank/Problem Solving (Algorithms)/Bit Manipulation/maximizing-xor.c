/*
 ? Link: https://www.hackerrank.com/challenges/maximizing-xor/problem
 * Difficulty: Easy
 * Name: Maximizing XOR
 *
 * Tags: Algorithms, Bit Manipulation
 *
 */

#include <stdio.h>

//////////////////////////////////////!
int maxXOR(int L, int R)
{
	int max = 0;
	for (int i = L; i <= R; i++) // loop for the first number
	{
		for (int j = i; j < R; j++) // loop for the second number //* j = i to avoid duplicate values
		{
			if ((i ^ j) > max) // if the XOR of the two numbers is greater than the current maximum XOR
				max = i ^ j;   // update the maximum XOR
		}
	}
	return max;
}
//////////////////////////////////////!

int main()
{
	int L, R;			   // declare the range variables
	scanf("%d%d", &L, &R); // take input of the range

	printf("%d", maxXOR(L, R));
	return 0;
}
