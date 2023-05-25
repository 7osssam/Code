#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr_size;
    scanf("%d", &arr_size);
    int *array = (int *)malloc(sizeof(int) * arr_size);

    for (int i = 0; i < arr_size; i++)
    {
        scanf("%d", &array[i]);
    }

    int SortCounter = 0;

    for (int steps = 0; steps < arr_size - 1; steps++)
    {
        for (int i = 0; i < arr_size - steps - 1; i++)
        {
            if (array[i] > array[i + 1])
            {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;

                SortCounter++;
            }
        }
        if (SortCounter == 0) // didn't swap any numbers
        {
            break;
        }
    }

    printf("Array is sorted in %d swaps.\n", SortCounter);
    printf("First Element: %d\n", array[0]);
    printf("Last Element: %d\n", array[arr_size - 1]);
    free(array);
}
