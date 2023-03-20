// (8) Write a program that reads a positive integer and
// checks if it is a perfect square.

#include <stdio.h>
#include <math.h> // for sqrt() function

int is_perfect_square(int num) // O(1) time complexity using sqrt() function
{
    int i;

    int root = sqrt(num); // sqrt() function returns the square root of a number
    if (root * root == num)
    {
        return 1;
    }
    return 0;
}

int main()
{
    int num1;
    printf("Enter a number:");
    scanf("%d%d%d", &num1);

    // using sqrt() function
    if (is_perfect_square(num1))
    {
        printf("%d is a perfect square _Lib\n", num1);
    }
    else
    {
        printf("%d is not a perfect square _Lib\n", num1);
    }
    return 0;
}
