/*
 ===================================================================================================
 Name        : array_ex1.c
 Author      : Mohamed Tarek
 Description : Code to understand how to access all the array elements using loop
 ===================================================================================================
 */

#include<stdio.h>

int main(void)
{
    int arr[3];
    int   i;
    for (i = 0; i < 3; i++)
    {
        arr[i] = 2*i;
    }
	for (i = 0; i < 3; i++)
	{
	    printf("arr[%d] = %d \n",i,arr[i]);
	}
	return 0;
}
