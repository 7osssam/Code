/*
 ===================================================================================================
 Name        : pointers_ex3.c
 Author      : Mohamed Tarek
 Description : Program to find and display a certain number in array by passing an array
               to function using pointers.
 ===================================================================================================
 */

#include <stdio.h>

int Linear_Search(const int * ptr,int element,int n);

int main( void )
{
    const int size = 5;
    int i;
    int arr[size];
    int location;
    int element;

    /* Take all the array elements values as an input from user */
    printf("Enter the required array: \n");
    for(i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }

    /* Take the value of the number required to be found in the array */
    printf("Enter element for search: ");
    scanf("%d",&element);

    location = Linear_Search(arr,element,size);

    if(location == -1)
    {
        printf("\nElement not found\n");
    }
    else
    {
        printf("\nThe element at the location: %d",location);
    }
    return 0;
}

int Linear_Search(const int * ptr,int element,int n)
{
    int i;
    /* Search in all array values to find the position of the required element */
    for(i=0;i<n;i++)
    {
        if(element==ptr[i])
        {
        	return (i);
        }
    }
    return -1; /* element not found */
}
