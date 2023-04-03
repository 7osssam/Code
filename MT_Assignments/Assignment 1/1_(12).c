// (12) Write a program that reads a positive integer and computes the factorial.

#include <stdio.h>

int factorial(int num) // function to calculate factorial
{
    int factorial = 1;
    for (int i = 2; i <= num; i++) // i = 1 is not required
    {
        factorial = factorial * i;
    }
    return factorial;
}

int main()
{
    int num; // declare variable
    do
    {
        printf("Enter a postive number num:");
        scanf("%d", &num);
    } while (num < 0); // if num is negative (true), then loop again

    printf("factorial = %d", factorial(num));

    return 0;
}