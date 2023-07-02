/*
 ? Link: https://www.hackerrank.com/challenges/counter-game/problem
 * Difficulty: Medium
 * Name: Counter game
 *
 * Tags: Algorithms, Bit Manipulation
 *
 * Summary:
 * 1. Given a number n, the two players take turns dividing n by 2.
 * 2. If n is not a power of 2, reduce the largest power of 2 less than n to get n.
 * 3. The player who cannot make a move loses the game.
 * 4. The first player always plays to win.
 * 5. If the first player wins, print "Richard" else print "Louise".
 *
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define isPowerOf2(num) (num && !(num & (num - 1)))

//?? this function uses alot of floating point operations which is consuming alot of time and memory
// unsigned long MSB(unsigned long num)
// {
//     static unsigned long mask = 1u << (sizeof(num) * 8u - 1u);
//     while ((mask & num) == 0)
//     {
//         mask >>= 1;
//     }
//     return mask;
// }

unsigned long findLogBase2(unsigned long num)
{
	unsigned long r = 0;
	while (num >>= 1UL)
	{
		r++;
		// num >>= 1UL;
	}
	return r;
}

void Countergame(unsigned long num)
{
	unsigned long counter = -1; // even numbers are Louise // odd numbers are Richard
	// unsigned long long k;
	while (num != 1)
	{
		if (isPowerOf2(num)) // if num is power of 2
		{
			// num /= 2;
			num >>= 1; // Divide by 2 using bitwise right-shift
		}
		else // if not
		{
			unsigned long msb = findLogBase2(num);
			num -= (1U << msb);
			// k = pow(2, floor(log2(num)));
			// num -= k;
		}
		counter++;
	}

	if (counter % 2 == 0)
	{
		puts("Louise");
	}
	else
	{
		puts("Richard");
	}
}
int main()
{
	int n;
	scanf("%d", &n);

	unsigned long *arr = (unsigned long *)malloc(sizeof(unsigned long) * n);

	for (int i = 0; i < n; i++)
	{
		scanf("%lu", &arr[i]);
	}

	for (int i = 0; i < n; i++)
	{
		Countergame(arr[i]);
	}

	free(arr);
}
