// Write a C function to check if the input is an even number or an odd number,
// if even number return 0 if odd number return 1.
// Example:
// Input 7, Output = 1 (Odd)
// Input 6, Output = 0 (Even)

#include <stdio.h>

int CheckEvenOdd(int num)
{
    if (num % 2 == 0) // even
    {
        return 0; // 0 if even
    }
    return 1; // 1 if odd
}
int main()
{
    int num;
    printf("Enter num : ");
    scanf("%d", &num);

    // ternary operator if true (1) print ODD else (0) print EVEN
    CheckEvenOdd(num) ? printf("ODD") : printf("EVEN");

    return 0;
}