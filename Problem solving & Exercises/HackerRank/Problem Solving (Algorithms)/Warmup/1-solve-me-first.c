/*
 ? Link: https://www.hackerrank.com/challenges/solve-me-first/problem
 * Difficulty: Easy
 * Name: Solve Me First
 *
 * Tags: Algorithms, Warmup
 *
 * Summary:
 * sum of two integers
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int solveMeFirst(int a, int b)
{
	return a + b; // :)
}
int main()
{
	int num1, num2;
	scanf("%d %d", &num1, &num2);
	int sum;
	sum = solveMeFirst(num1, num2);
	printf("%d", sum);
	return 0;
}
