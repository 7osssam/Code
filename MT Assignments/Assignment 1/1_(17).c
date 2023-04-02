// (17) Write a program to count number of digits in a decimal number.

#include <stdio.h>

int countDig(int num)
{
    int count = 0;   // Initialize count to 0
    while (num != 0) // Loop until num is not equal to 0
    {
        count++;        // Increment count by 1
        num = num / 10; // remove last digit
    }
    return count;
}
int main()
{
    int num;
    printf("Enter Number:");
    scanf("%d", &num);

    printf("This number has %d digits", countDig(num));
    return 0;
}