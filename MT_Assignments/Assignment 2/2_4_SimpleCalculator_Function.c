// 4 - Write a C Function that return the addition or subtraction or multiplication or division for two numbers.
// The function should take the required operation and two numbers as arguments.
// It also should check that the input operation is one of those operation that mentioned before and if not it should return error.
// The function should be implemented using switch case

#include <stdio.h>

float SimpleCalculator(float num1, float num2, char op)
{
    float result;
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
        if (num2 == 0)
        {
            printf("Error: division by zero"); //! Error massage need some update
            return 0;
        }
        result = num1 / num2;
        break;

    default:
        printf("ERROR"); // error message if the user enters an invalid operator
        return 0;        // return 0 to avoid returning a garbage value
    }
    return result;
}

int main()
{
    float num1, num2, result;
    char op;

    printf("Enter 2 numbers:");
    scanf("%f%f", &num1, &num2);

    printf("Enter operation (+ or - or * or /) ");
    scanf(" %c", &op); // added a space before %c to avoid skipping the first character

    result = SimpleCalculator(num1, num2, op);
    printf("The result is %.2f", result);

    return 0;
}