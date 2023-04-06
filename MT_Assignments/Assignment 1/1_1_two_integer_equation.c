// (1) Write a program that take two integers from the user and print the results of this equation: Result = ((num1 + num2) * 3) – 10

#include <stdio.h>

int main()
{
    int num1, num2; // Declaring two variables

    printf("Enter two integers: "); // Printing a message
    scanf("%d%d", &num1, &num2);    // Taking two integers from the user

    printf("The Result is: %d", ((num1 + num2) * 3) - 10); // Printing the result

    return 0;
}