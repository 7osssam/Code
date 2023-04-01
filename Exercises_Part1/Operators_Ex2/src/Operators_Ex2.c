/*
 ===================================================================================================
 Name        : Operators_Ex2.c
 Author      : Mohamed Tarek
 Description : Code to demonstrate the capability of the Equality and Relational operators
 ===================================================================================================
 */

#include <stdio.h>

/* function main begins program execution */
int main( void )
{
	int num1; /* first number to be read from user */
	int num2; /* second number to be read from user */
	printf( "Enter two integers, and I will tell you\n" );
	printf( "the relationships they satisfy: " );
	scanf( "%d%d", &num1, &num2 ); /* read two integers */

	if (num1 == num2)
	{
		printf( "\n%d is equal to %d\n", num1, num2 );
	}

	if (num1 != num2 )
	{
		printf( "\n%d is not equal to %d\n", num1, num2 );
	}

	if (num1 < num2 )
	{
		printf( "\n%d is less than %d\n", num1, num2 );
	}

	if (num1 > num2 )
	{
		printf( "\n%d is greater than %d\n", num1, num2 );
	}

	if (num1 <= num2 )
	{
		printf( "\n%d is less than or equal to %d\n", num1, num2 );
	}

	if (num1 >= num2 )
	{
		printf( "\n%d is greater than or equal to %d\n", num1, num2 );
	}
	return 0;
}
