// (18) Write a program to display half pyramid using stars pattern.
// *
// * *
// * * *
// * * * *
// * * * * *

#include <stdio.h>

int main()
{
    int i, j;
    for (i = 1; i <= 5; i++)
    {
        for (j = 1; j <= i; j++)
        {
            printf("* ");
        }
        printf("\n");
    }
}