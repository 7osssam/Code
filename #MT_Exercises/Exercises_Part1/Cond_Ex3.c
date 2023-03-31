/*
 ===================================================================================================
 Name        : Cond_Ex3.c
 Author      : Mohamed Tarek
 Description : Code to check if the input number is greater or less then 100
 ===================================================================================================
 */

#include <stdio.h>

int main(void)
{
	/* variable declaration */
	int a;

	printf("Please Enter a Number : ");
	scanf("%d", &a);

	/* check the condition and evaluating this condition */
	if (a < 100)
	{
		printf("\na is less than 100\n");
	}
	else if (a > 100)
	{
		printf("\n a greater than 100\n");
	}
	else
	{
		printf("\n a equal to 100\n");
	}
	return 0;
}
