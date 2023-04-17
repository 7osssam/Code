//? https://www.hackerrank.com/challenges/simple-array-sum/problem
// sum of array elements
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size;
    int sum = 0;
    scanf("%d", &size);

    int *ar = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &ar[i]);
        sum = sum + ar[i];
    }

    printf("%d", sum);

    free(ar);
    return 0;
}
