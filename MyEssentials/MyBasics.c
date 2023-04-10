#include <stdio.h>

//! ========================== Swap advanced ==========================  //
void Swap_Advanced(int *num1, int *num2) // with no temp variable
{
    *num1 = *num1 + *num2; // add x and y and store in x
    *num2 = *num1 - *num2; // subtract y from x and store in y // x = x + y - y = x
    *num1 = *num1 - *num2; // subtract y from x and store in x // y = x + y - x = y
}
//! ========================== Swap ===================================  //
void Swap(int *num1, int *num2) // using temp variable
{
    int temp;
    temp = *num1;  // save the value of num1
    *num1 = *num2; // assign the value of num2 to num1
    *num2 = temp;  // assign the saved value of num1 to num2
}
//! ========================== Power of two ==============================  //
int isPowerOfTwo(int n) // time complexity: O(log n)
{
    if (n <= 0) // 0 is not a power of 2
    {
        return 0;
    }
    while (n != 1) // while number is not 1
    {
        if (n % 2 != 0) // if number is not divisible by 2
        {
            return 0;
        }
        n /= 2; // divide number by 2
    }
    return 1;
}
//! ========================== isPowerOfTwo_Advanced ======================  //
int isPowerOfTwo_Advanced(int num) // time complexity: O(1)
{
    if (num <= 0) // 0 is not a power of 2 and negative numbers are not power of 2
        return 0;

    if ((num & (num - 1)) == 0) // if number is a power of 2, then it will have only 1 bit set
    {
        return 1; // number is a power of 2
    }
    else
    {
        return 0; // number is NOT a power of 2
    }
}
//! ========================== fibonacci of nth ============================  //
int fibOfN(int num)
{
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
    return fibOfN(num - 1) + fibOfN(num - 2);
}

//! ========================== fibonacci sequence ===========================  //
void printFibonacci(int num)
{
    // Iterative approach
    // time complexity: O(n)
    int first = 0, second = 1, next;

    for (int i = 0; i <= num; i++)
    {
        if (i <= 1)
        {
            next = i;
        }
        else
        {
            next = first + second;
            first = second;
            second = next;
        }
        printf("%d ", next);
    }
    // printf("%d ", next); // to get the nth fibonacci number
}

//! ========================== Power of three ========================== //
int isPowerOfThree(int num) // time complexity: O(log n)
{
    if (num <= 0) // 0 is not a power of 3
    {
        return 0;
    }
    while (num != 1) // while number is not 1
    {
        if (num % 3 != 0) // if number is not divisible by 3
        {
            return 0;
        }
        num /= 3; // divide number by 3
    }
    return 1;
}