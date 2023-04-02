/*
 ===================================================================================================
 Name        : pointers_ex5.c
 Author      : Mohamed Tarek
 Description : Program to understand the pointers arithmetic concept
 ===================================================================================================
 */

#include <stdio.h>

int main()
{
    int i;
    int arr[4] = {1,2,3,4};
    int *p_arr = arr;
    printf("Array Addresses:\n");
    for(i=0;i<4;i++)
    {
        printf("%p\t",arr+i);
    }
    printf("\nFirst Element Address: %p\n",p_arr);
    p_arr++;
    printf("Second Element Address: %p\n",p_arr);
    p_arr+=2;
    printf("Forth Element Address: %p\n",p_arr);
    return 0;
}
