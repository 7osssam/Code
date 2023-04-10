// 11- Write a C function that returns 1 if the input number is a power of 2
// and return 0 if the input number is not power of 2.
// For example:
// 1, 2 and 16 are power of 2.
// 0, 10 and 30 are not power of 2.
#include <stdio.h>

// int isPowerOfTwo(int num) // very bad approach
// {
//     int count = 1;
//     for (int i = 1; i <= num; i++)
//     {
//         count = count * 2;
//         if (count == num)
//         {
//             return 1; // number is a power of 2
//         }
//         else if (count > num)
//         {
//             break;
//         }
//     }
//     return 0; // number is NOT a power of 2
// }

// int isPowerOfTwo(int n) // time complexity: O(log n)
// {
//     if (n <= 0) // 0 is not a power of 2
//     {
//         return 0;
//     }
//     while (n != 1) // while number is not 1
//     {
//         if (n % 2 != 0) // if number is not divisible by 2
//         {
//             return 0;
//         }
//         n /= 2; // divide number by 2
//     }
//     return 1;
// }

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

int main()
{
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (isPowerOfTwo_Advanced(num))
    {
        printf("number is a power of 2");
    }
    else
    {
        printf("number is NOT a power of 2");
    }
}
