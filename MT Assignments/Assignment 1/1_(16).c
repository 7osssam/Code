// (16) Write a program to reverse a number.

#include <stdio.h>

int reverse(int num) // optimized function to reverse a number
{
    int mod, reverse = 0; // mod will store last digit of number and reverse will store the reverse of number

    while (num != 0) // while loop will run until num becomes 0
    {
        mod = num % 10;               // getting last digit of number
        reverse = reverse * 10 + mod; // adding last digit to reverse

        num = num / 10; // removing last digit from number
    }

    return reverse;
}

int main()
{
    int num;
    printf("Enter Number:");
    scanf("%d", &num);

    printf("Reverse : %d", reverse(num));

    return 0;
}