/******************************************************************************
Write a program that computes the nth term of the arithmetic series:
1, 3, 9, 27, ...
Run the program to compute the10th term of the given series
*******************************************************************************/

#include <stdio.h>

#include <stdio.h>

int main()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int i;
    int term = 1; // initialize the first term to 1
    for (i = 2; i <= n; i++)
    {
        term *= 3; // add 2 to the previous term to get the next term
    }

    printf("The %dth term of the series is: %d\n", n, term);
    return 0;
}
