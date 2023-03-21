// (18) Write a program to display half pyramid using stars pattern.
// *
// * *
// * * *
// * * * *
// * * * * *

#include <stdio.h>

int main()
{
    int raws = 5;
    for (int i = 1; i <= raws; i++)
    {
        // printf(" * ");
        for (int j = 1; j <= i; j++)
        {
            // printf(" * ");
            printf(" %d ", i);
        }
        printf("\n");
    }
}