// (7) Write a program that takes three integers, and prints
// out the smallest number.

#include <stdio.h>

int main()
{
    int num1, num2, num3, smallest; // Declare 3 numbers and the smallest number

    printf("Enter 3 numbers:");
    scanf("%d%d%d", &num1, &num2, &num3); // Read 3 numbers from the user

    smallest = num1; // Assume that the first number has the smallest value

    if (num1 > num2) // Compare the smallest value with the second number
    {
        smallest = num2;
    }
    if (num1 > num3) // Compare the smallest value with the third number
    {
        smallest = num3;
    }
    printf("the samllest is %d", smallest); // Print the smallest number

    return 0; // Indicate the program terminated successfully
}
