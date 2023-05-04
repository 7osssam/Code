/******************************************************************************
(17) Write a C Program for swapping two arrays “A & B” with different lengths.
//! B will be always the smallest array.
int * Swap (int a_size,int *a,int b_size,int *b)
*******************************************************************************/

#include <stdio.h>

int *Swap(int a_size, int *a, int b_size, int *b)
{
    int temp;
    for (int i = 0; i < b_size; i++)
    {
        temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
    return a;
    /* =======================================
    we don't need to return anything, we are changing the values of the arrays directly
    but it's in the requirements of the question
    ======================================= */
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {6, 7, 8};

    int a_size = sizeof(a) / sizeof(a[0]);
    int b_size = sizeof(b) / sizeof(b[0]);

    for (int i = 0; i < a_size; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n");

    for (int i = 0; i < b_size; i++)
    {
        printf("%d ", b[i]);
    }

    Swap(a_size, a, b_size, b);
    printf("\n\nAfter swapping:\n");

    for (int i = 0; i < a_size; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n");

    for (int i = 0; i < b_size; i++)
    {
        printf("%d ", b[i]);
    }
}