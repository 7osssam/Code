#include <stdio.h>

int main()
{
	int num, n;
	printf("Enter a number: ");
	scanf("%d", &num);
	printf("Enter the bit number to set: ");
	scanf("%d", &n);

	num = num | (1 << n);

	printf("The number after setting the %dth bit is %d\n", n, num);

	return 0;
}