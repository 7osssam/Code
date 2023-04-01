/*
 ===================================================================================================
 Name        : Loops_Ex3.c
 Author      : Mohamed Tarek
 Description : Code to print the sum of the even numbers from ZERO to 100
 ===================================================================================================
 */

#include <stdio.h>

/* function main begins program execution */
int main( void )
{
	int number; /* number to be added to sum */
	int sum = 0; /* initialize sum */

	for ( number = 2; number <= 100; number += 2 ) {
		sum += number; /* add number to sum */
	} /* end for */
	printf( "Sum is %d\n", sum ); /* output sum */
	return 0; /* indicate program ended successfully */
} /* end function main */

