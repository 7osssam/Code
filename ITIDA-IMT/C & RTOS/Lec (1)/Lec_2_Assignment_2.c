#include <stdio.h>

int main()
{
	int numbers[5];
	printf("Enter 5 numbers: ");
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &numbers[i]);
	}

	printf("Numbers divisible by 3: ");
	for (int i = 0; i < 5; i++)
	{
		if (numbers[i] % 3 == 0)
		{
			printf("%d ", numbers[i]);
		}
	}
	printf("\n");

	return 0;
}