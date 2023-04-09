// 7 - Write a C Function that reads two integers and checks if the first is multiple of the second

#include <stdio.h>

int isMultiple(int num1, int num2)
{
    if (num2 == 0) // if num2 is 0
    {
        // Check for division by zero
        printf("Error: division by zero");
        return -1;
    }
    else if (num1 % num2 == 0)
    {
        // If the remainder of num1 divided by num2 is 0, then num1 is a multiple of num2
        return 1;
    }
    else
    {
        // If the remainder is not 0, then num1 is not a multiple of num2
        return 0;
    }
}
int main()
{
    int num1, num2, result;
    printf("Enter 2 nums : ");
    scanf("%d%d", &num1, &num2);

    result = isMultiple(num1, num2);
    if (result == 1)
        printf("the first is multiple of the second");
    else if (result == 0)
        printf("NOT multiple");

    //! in this case below, the function is called twice no matter what the result is
    //! so it is better to use a variable to store the result and use it in the if-else statement
    //! and in error cases, the function is called twice as well

    // if (isMultiple(num1, num2) == 1)
    //     printf("the first is multiple of the second");
    // else if (isMultiple(num1, num2) == 0)
    //     printf("NOT multiple");
}