/*
 ===================================================================================================
 Name        : array_ex4.c
 Author      : Mohamed Tarek
 Description : Program to display number of * according to the value in each array element
 ===================================================================================================
 */

#include <stdio.h>

/* function main begins program execution */
int main( void )
{
    /* use initializer list to initialize array n */
    int n[ 5 ] = { 19, 3, 15, 7, 11};
    int i; /* outer for counter for array elements */
    int j; /* inner for counter counts *s in each histogram bar */
    /* for each element of array n, output a bar of the histogram */
    for ( i = 0; i < 5; i++ )
    {
        printf("%d\t",n[i]);
        for ( j = 1; j <= n[ i ]; j++ ) { /* print one bar */
            printf( "%c", '*' );
        } /* end inner for */
        printf( "\n" ); /* end a histogram bar */
    } /* end outer for */
    return 0; /* indicates successful termination */
} /* end main */

