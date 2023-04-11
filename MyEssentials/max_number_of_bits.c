#include <stdio.h>
#include <stdlib.h>
#define INT_SIZE sizeof(int) * 8

int maxZerosbetween(int num)
{
	int flag = 0, max = 0, zero_count = 0;
	for (int i = 0; i < INT_SIZE; i++) // 0b1011010100011100001000
	{
		if (num >> i & 1) // ones
		{
			flag = 1;
			if (zero_count > max) // will only set max if there is one before
				max = zero_count; // set max
			zero_count = 0;		  // reset zero count
		}
		else // zeros
		{
			if (flag == 1) // will only count if flag is 1
				zero_count++;
		}
	}

	return max;
}

int main()
{

	int num = 0b1011010100011100001000;
	printf("max number zeros is %d", maxZerosbetween(num)); // 4
	return 0;
}
