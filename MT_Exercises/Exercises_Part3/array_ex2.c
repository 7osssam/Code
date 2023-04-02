/*
 ===================================================================================================
 Name        : array_ex2.c
 Author      : Mohamed Tarek
 Description : Code to calculate the sum and average for the arrays elements values
 ===================================================================================================
 */

#include <stdio.h>

#define arr_size 5

int main(void)
{
    int arr[arr_size];
    int i,sum=0;
    float average;

    /* Take all the array elements values as an input from user */
    printf("Please Enter Five Numbers : \n");
    for(i=0;i<arr_size;i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("The array elements are:\n");
    for(i=0;i<arr_size;i++)
    {
    	/* Print the values for all the array elements */
        printf("%d\t",arr[i]);

        /* Calculate the accumulative Sum  of all the array elements*/
        sum+=arr[i];
    }
    printf("\nThe sum of the array elements is: %d\n",sum);

    /* Calculate the average of the sum for the array elements */
    average = (float)sum/arr_size;
    printf("The average of the array elements is: %f\n",average);

    return 0;
}
