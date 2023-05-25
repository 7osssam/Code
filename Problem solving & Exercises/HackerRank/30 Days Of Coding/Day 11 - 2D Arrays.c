#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define arr_size 6
int main()
{
    // int array[arr_size][arr_size];

    //  This is how to correctly dynamically allocate a 2D array in C
    int **array = (int **)malloc(arr_size * sizeof(int *));
    for (int i = 0; i < arr_size; i++)
    {
        array[i] = (int *)malloc(arr_size * sizeof(int));
    }

    long max = -500000; // for some reason, if I set max to 0, it doesn't work properly
    long SumOfRows;

    for (int i = 0; i < arr_size; i++)
    {
        for (int j = 0; j < arr_size; j++)
        {
            scanf("%d", &array[i][j]);
        }
    }

    for (int i = 0; i < arr_size - 2; i++)
    {
        for (int j = 0; j < arr_size - 2; j++)
        {
            SumOfRows = (array[i][j] + array[i][j + 1] + array[i][j + 2]) +
                        (array[i + 1][j + 1]) +
                        (array[i + 2][j] + array[i + 2][j + 1] + array[i + 2][j + 2]);
            if (SumOfRows > max)
            {
                max = SumOfRows;
            }
        }
    }

    printf("%ld", max);
    return 0;
}
