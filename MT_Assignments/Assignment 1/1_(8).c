// (8) Write a program that reads a positive integer and checks if it is a perfect square.
//! a perfect square is a number that can be expressed as the product of two equal integers.

#include <stdio.h>
#include <math.h> // for sqrt() function

int is_perfect_square(int num) // O(1) time complexity using sqrt() function
{

    int root = sqrt(num); // sqrt() function returns the square root of a number
    if (root * root == num)
    {
        return 1; // true
    }
    return 0; // false
}

int main()
{
    int num;
    printf("Enter a number:");
    scanf("%d", &num);

    // using sqrt() function
    if (is_perfect_square(num))
    {
        printf("%d is a perfect square _Lib\n", num);
    }
    else
    {
        printf("%d is not a perfect square _Lib\n", num);
    }
    return 0;
}
// test cases: 4, 9, 16, 25, 36, 49, 64, 81, 100, 121, 144, 16910