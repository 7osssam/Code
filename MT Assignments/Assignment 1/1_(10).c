// (10) Write a program to make a simple calculator using switch-case.
// The calculator takes the operation (+ or – or * or /)
// and takes the two input arguments and print the results.

#include <stdio.h>

int main()
{
    float num1, num2, result;
    char op;

    printf("Enter 2 numbers:");
    scanf("%f%f", &num1, &num2);

    printf("Enter operation (+ or - or * or /) ");
    scanf(" %c", &op); // added a space before %c to avoid skipping the first character

    switch (op)
    {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
        result = num1 / num2;
        break;

    default:
        printf("ERROR"); // error message if the user enters an invalid operator
        break;
    }
    printf("The result is %.2f", result);
    return 0;
}