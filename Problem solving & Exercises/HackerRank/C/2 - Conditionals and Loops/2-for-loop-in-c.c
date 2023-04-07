//? https://hackerrank.com/challenges/for-loop-in-c/problem

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() // main function
{
    int a, b;                // declaring variables
    scanf("%d\n%d", &a, &b); // taking input

    ////////////////////////! Complete the code.
    for (size_t i = a; i <= b; i++) // looping through the range
    {
        switch (i) // switch case for printing the numbers in words
        {
        case 1:
            printf("one\n");
            break;
        case 2:
            printf("two\n");
            break;
        case 3:
            printf("three\n");
            break;
        case 4:
            printf("four\n");
            break;
        case 5:
            printf("five\n");
            break;
        case 6:
            printf("six\n");
            break;
        case 7:
            printf("seven\n");
            break;
        case 8:
            printf("eight\n");
            break;
        case 9:
            printf("nine\n");
            break;
        default: // default case for printing even or odd for numbers greater than 9
        {
            if (i % 2 == 0) // checking if the number is even or odd
                printf("even\n");
            else
                printf("odd\n");
        }
        }
    }
    ////////////////////////!

    return 0;
}
