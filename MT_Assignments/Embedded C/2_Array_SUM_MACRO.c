/***************************************************
(2) Write a C Macro to calculate the sum of an array.
****************************************************/
#include <stdio.h>

#define ARRAY_SUM(array) ({                                      \
    int sum = 0;                                                 \
    for (int i = 0; i < (sizeof(array) / sizeof(array[0])); i++) \
    {                                                            \
        sum += (array)[i];                                       \
    }                                                            \
    sum;                                                         \
})

int main()
{
    int arr[4] = {1, 4, 5, 7};
    int sum = ARRAY_SUM(arr);
    printf("%d", sum);
    return 0;
}
