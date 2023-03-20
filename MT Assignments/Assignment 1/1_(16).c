// (16) Write a program to reverse a number.

#include <stdio.h>

int reverse(int num)
{
    int mod, rev = 0;

    while (num != 0) // while loop will run until num becomes 0
    {
        mod = num % 10;       // getting last digit of number
        rev = rev * 10 + mod; // adding last digit to reverse

        num = num / 10; // we are removing last digit from number
    }
    return rev;
}

int main()
{
    int num;
    printf("Enter Number:");
    scanf("%d", &num);

    printf("Reverse : %d", reverse(num));

    return 0;
}