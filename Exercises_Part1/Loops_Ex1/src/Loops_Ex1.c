/*
 ===================================================================================================
 Name        : Loops_Ex1.c
 Author      : Mohamed Tarek
 Description : Code to print count from 0 to 10 to illustrate the capability of the while loop
 ===================================================================================================
 */

#include <stdio.h>

/* function main begins program execution */
int main( void )
{
	int counter = 1; /* initialization */
	while (counter <= 10 ) { /* repetition condition */
		printf ( "counter = %d\n", counter ); /* display counter */
		++counter;
	} /* end while */

	printf("Last counter value = %d\n",counter);

	return 0; /* indicate program ended successfully */
} /* end function main */
