// (19) Write a program to display inverted half pyramid using stars pattern.
// * * * * *
// * * * *
// * * *
// * *
// *

#include <stdio.h>

int main()
{
    int i, j;
    for (i = 1; i <= 5; i++)
    {
        for (j = i; j <= 5; j++)
        {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}