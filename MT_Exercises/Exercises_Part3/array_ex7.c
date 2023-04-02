/*
 ===================================================================================================
 Name        : array_ex7.c
 Author      : Mohamed Tarek
 Description : Program to sort the array elements using selection sorting algorithm
 ===================================================================================================
 */

#include <stdio.h>

void selection_sorting(int array[],const int size)
{
    int i,j,min,temp;
    for(i=0;i<size-1;i++)
    {
    	/* Assume that this position contains the min value */
        min=i;

        /* Start compare with the next positions to find the
         * position which contains the minimum value.
         * The position of which contains the minimum value should be
         * stored in the min variable */
        for(j=i+1;j<size;j++)
        {
            if(array[min]>array[j])
                min=j;
        }

        /* Swap between the element in this position (i) and the position
         * which has the minimum value(min).
         */
        temp = array[i];
        array[i] = array[min];
        array[min] = temp;
    }
}

int main(void)
{
    const int arr_size = 5;
    int arr[arr_size],i;

    /* Take all the array elements values as an input from user */
    printf("Enter the required numbers to be sorted:\n");
    for(i=0;i<arr_size;i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("Array Before Sorting: \n");
    for(i=0;i<arr_size;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");

    /* pass the array to be sorted using function */
    selection_sorting(arr,arr_size);

    printf("Array After Sorting: \n");
    for(i=0;i<arr_size;i++)
    {
        printf("%d\t",arr[i]);
    }

    return 0;
}
