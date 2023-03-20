// (17) Write a program to count number of digits in a decimal number.

#include <stdio.h>

int countDig(int num)
{
    int count = 0;
    while (num != 0)
    {
        count++;
        num = num / 10;
    }
    return count;
}
int main()
{

    int num;
    printf("Enter Number:");
    scanf("%d", &num);

    printf("this number has %d digits", countDig(num));
    return 0;
}