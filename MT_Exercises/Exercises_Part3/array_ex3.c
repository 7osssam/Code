/*
 ===================================================================================================
 Name        : array_ex3.c
 Author      : Mohamed Tarek
 Description : Code to calculate the maximum value in the array.
 ===================================================================================================
 */

#include <stdio.h>

#define arr_size 5

int main()
{
    int arr[arr_size];
    int i,max_num;

    /* Take all the array elements values as an input from user */
    for(i=0;i<arr_size;i++)
    {
        scanf("%d",&arr[i]);
    }

    /* Assume that the first element in the array contains the max value */
    max_num = arr[0];

    /* Compare the max value that we have with all the array elements values
     * to get the max value in the array
     */
    for(i=1;i<arr_size;i++)
    {
        if(arr[i] > max_num)
        {
            max_num = arr[i];
        }
    }

    printf("The maximum number in the array is : %d",max_num);
    return 0;
}
