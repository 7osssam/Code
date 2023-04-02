/*
 ===================================================================================================
 Name        : pointers_ex4.c
 Author      : Mohamed Tarek
 Description : Program to understand how to access the array elements with different methods using pointers.
 	 	 	   and the relations between pointers and arrays.
 ===================================================================================================
 */

#include <stdio.h>

int main( void )
{
    int b[] = { 10, 20, 30, 40 }; /* initialize array b */
    int *bPtr = b; /* set bPtr to point to array b */
    int i; /* counter */
    int offset; /* counter */

    /* output array b using array subscript notation */
    printf( "Array b printed with:\nArray subscript notation\n" );
    /* loop through array b */
    for ( i = 0; i < 4; i++ ) {
        printf( "b[ %d ] = %d\n", i,b[i] );
    } /* end for */

    /* output array b using array name and pointer/offset notation */
    printf( "\nPointer/offset notation where\nthe pointer is the array name\n" );
    /* loop through array b */
    for ( offset = 0; offset < 4; offset++ ) {
        printf( "*( b + %d ) = %d\n", offset, *(b+offset) );
    } /* end for */

    /* output array b using bPtr and array subscript notation */
    printf( "\nPointer subscript notation\n" );
    /* loop through array b */
    for ( i = 0; i < 4; i++ ) {
        printf( "bPtr[ %d ] = %d\n", i,bPtr[i] );
    } /* end for */

    /* output array b using bPtr and pointer/offset notation */
    printf( "\nPointer/offset notation\n" );
    /* loop through array b */
    for ( offset = 0; offset < 4; offset++ ) {
        printf( "*( bPtr + %d ) = %d\n", offset, *(bPtr+offset) );
    } /* end for */

    return 0; /* indicates successful termination */
} /* end main */
