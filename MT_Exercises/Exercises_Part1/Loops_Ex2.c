/*
 ===================================================================================================
 Name        : Loops_Ex2.c
 Author      : Mohamed Tarek
 Description : Code to print count from 0 to 10 to illustrate the capability of the for loop
 ===================================================================================================
 */

#include <stdio.h>

/* function main begins program execution */
int main(void)
{
	int counter; /* define counter */

	/* initialization, repetition condition, and increment are all included in the for statement header. */
	for (counter = 1; counter <= 10; counter++)
	{
		printf("counter = %d\n", counter); /* display counter */
	}									   /* end for */

	printf("Last counter value = %d\n", counter);

	return 0; /* indicate program ended successfully */
} /* end function main */
