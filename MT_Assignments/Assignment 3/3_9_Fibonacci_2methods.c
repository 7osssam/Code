/******************************************************************************
(9)The sequence of numbers 1, 1, 2, 3, 5, 8, 13, ...is called Fibonacci numbers:
each is the sum of the preceding 2.
Write a program which given n, returns the nth Fibonacci number.
-with for/while
-with recursion
*******************************************************************************/
#include <stdio.h>

int fibRecursion(int num) // recursion
{
    if (num == 1) // base case
    {
        return 1;
    }
    if (num == 0) // base case
    {
        return 0;
    }

    return fibRecursion(num - 1) + fibRecursion(num - 2);
}

int fibForLoop(int num) // for loop
{
    if (num <= 0) // base case
        return num;
    if (num == 1) // base case
        return num;

    int first = 0, second = 1, next;
    for (int i = 0; i <= num; i++)
    {
        next = first + second;
        first = second;
        second = next;
    }
    return next;
}

int main()
{
    int num;
    printf("Enter a num :");
    scanf("%d", &num);

    printf("%d\n", fibForLoop(num));
    printf("%d", fibForLoop(num));

    return 0;
}