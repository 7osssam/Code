/*
 ===================================================================================================
 Name        : Loops_Ex5.c
 Author      : Mohamed Tarek
 Description : Code to print count from 0 to 10 to illustrate the capability of the do-while loop
 ===================================================================================================
 */

#include <stdio.h>

/* function main begins program execution */
int main( void )
{
	int counter = 1; /* initialize counter */
	do {
		printf( "counter = %d \n", counter ); /* display counter */
		counter++;
	}while( counter <= 10 ); /* end do...while */

	return 0; /* indicate program ended successfully */
} /* end function main */
