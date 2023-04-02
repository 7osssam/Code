/*
 ============================================================================
 Name        : Func_Ex2.c
 Author      : Mohamed Tarek
 Description : Code to print the square for numbers from 1 to 10
 ============================================================================
 */

#include <stdio.h>

int square( int y ); /* function prototype */

/* function main begins program execution */
int main( void )
{
	int x; /* counter */
	/* loop 10 times and calculate and output square of x each time */
	for ( x = 1; x <= 10; x++ )
	{
		printf( "%d ", square( x ) ); /* function call */
	} /* end for */
	printf( "\n" );
	return 0; /* indicates successful termination */
} /* end main */

/* square function definition returns square of parameter */
int square( int y ) /* y is a copy of argument to function */
{
	int results;
	results = y * y;
	return results;
} /* end function square */
