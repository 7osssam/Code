// 19 - Write a C function that return 0 if a given number is a power of 3,
// otherwise return 1(except 3 to the power of 0).
#include <stdio.h>

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

int main()
{
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (isPowerOfThree(num))
    {
        printf("number is a power of 3");
    }
    else
    {
        printf("number is NOT a power of 3");
    }
}