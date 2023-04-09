// 14 - Write a C Function that calculate the Fibonacci series using recursive method.
// The Fibonacci Series : 0,1,1,2,3,5,8,13,21,..

#include <stdio.h>
int fib(int num)
{
    // // Iterative approach
    // // time complexity: O(n)
    // int first = 0, second = 1, next;

    // for (int i = 0; i < num; i++)
    // {
    //     if (i <= 1) // because fib of 0 = 0 and fib of 1 = 1
    //     {
    //         next = i;
    //     }
    //     else
    //     {
    //         next = first + second;
    //         first = second;
    //         second = next;
    //     }
    //     printf("%d ", next);
    // }

    // Recursive approach
    // time complexity: O(2^n)
    if (num == 0) // base case
    {
        return 0;
    }
    else if (num == 1) // base case
    {
        return 1;
    }
    return fib(num - 1) + fib(num - 2);
}

int main()
{
    int num;

    printf("Enter num : ");
    scanf("%d", &num);

    printf("fib of %d = %d ", num, fib(num));
}