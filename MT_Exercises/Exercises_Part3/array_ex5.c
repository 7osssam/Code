/*
 ===================================================================================================
 Name        : array_ex5.c
 Author      : Mohamed Tarek
 Description : Program to understand the difference between passing array as argument and passing
               element inside the array as argument.
 ===================================================================================================
 */

#include<stdio.h>

#define SIZE 5

/* function prototypes */
void modifyArray( int b[], int size );
void modifyElementByValue( int e );
void modifyElementByAddress( int * e );

/* function main begins program execution */
int main( void )
{
    int a[SIZE] = { 0, 1, 2, 3, 4 }; /* initialize a */
    int i; /* counter */

    printf("values of the original array are:\n" );
    /* output original array */
    for ( i = 0; i < SIZE; i++ ) {
        printf( "%d\t", a[ i ] );
    } /* end for */
    printf( "\n" );

    /* pass array a to modifyArray by reference */
    modifyArray( a, SIZE );
    printf( "The values of the modified array are:\n" );
    /* output modified array */
    for ( i = 0; i < SIZE; i++ ) {
        printf( "%d\t", a[ i ] );
    } /* end for */

    /* output value of a[ 3 ] */
    printf("\nThe value of a[3] is %d\n", a[ 3 ] );
    modifyElementByValue( a[ 3 ] ); /* pass array element a[ 3 ] by value */
    /* output value of a[ 3 ] */
    printf( "The value of a[ 3 ] is %d\n", a[ 3 ] );

    modifyElementByAddress( &a[ 3 ] ); /* pass address of array element a[ 3 ] by value */
    /* output value of a[ 3 ] */
    printf( "The value of a[ 3 ] is %d\n", a[ 3 ] );

    return 0; /* indicates successful termination */
} /* end main */

/* in function modifyArray, "b" points to the original array "a"
in memory */
void modifyArray( int b[], int size )
{
    int j; /* counter */
    /* multiply each array element by 2 */
    for ( j = 0; j < size; j++ ) {
        b[ j ] *= 2;
    } /* end for */
} /* end function modifyArray */

/* in function modifyElement, "e" is a local copy of array element
a[ 3 ] passed from main */
void modifyElementByValue( int e )
{
    /* multiply parameter by 2 */
    printf( "Value in modifyElementByValue is %d\n", e *= 2 );
} /* end function modifyElementByValue */

void modifyElementByAddress(int * e)
{
	/* multiply parameter by 2 */
	*e = *e * 2;
	printf( "Value in modifyElementByAddress is %d\n", *e );
} /* end function modifyElementByAddress */
