#include <stdio.h>

int count_trailing_zeros(unsigned int num)
{
	int count = 0;
	while ((num & 1) == 0 && num > 0)
	{
		num >>= 1;
		count++;
	}
	return count;
}

int main()
{
	unsigned int num;
	printf("Enter a number: ");
	scanf("%u", &num);

	int count = count_trailing_zeros(num);
	printf("The number of trailing zeros in %u is %d.\n", num, count);

	return 0;
}