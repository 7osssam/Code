/******************************************************************************
Write a program that computes the nth term of the arithmetic series:
1, 3, 5, 7, 9, ...
Run the program to compute the 100th term of the given series.
*******************************************************************************/

#include <stdio.h>

int main()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    // int term = 1 + (n - 1) * 2; with no loop

    int i;
    int term = 1; // initialize the first term to 1
    for (i = 2; i <= n; i++)
    {
        term += 2; // add 2 to the previous term to get the next term
    }

    printf("The %dth term of the series is: %d\n", n, term);
    return 0;
}
