//? https://www.hackerrank.com/challenges/printing-pattern-2/problem
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define row (n * 2) - 1
int main()
{
    // n = 5 --> rows = (n * 2) - 1 = 9
    // n = 7 --> rows = (n * 2) - 1 = 13
    // raws = (n * 2) - 1
    int n;
    scanf("%d", &n);
    int counter = 1;
    int size = n;
    for (int i = 1; i <= row; i++)
    {

        for (int j = 1; j <= row; j++)
        {
            if (i == counter || j == counter || i == row || j == row)
            {
                printf("%d ", size);
            }
        }
        printf("\n");
    }
    return 0;
}