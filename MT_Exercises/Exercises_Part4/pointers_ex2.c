/*
 ===================================================================================================
 Name        : pointers_ex2.c
 Author      : Mohamed Tarek
 Description : Application to understand the difference between passing variables by value and by reference.
 ===================================================================================================
 */

#include <stdio.h>

void swap_pass_by_reference(int *num1_ptr,int *num2_ptr)
{
    int temp;
    temp = *num1_ptr;
    *num1_ptr = *num2_ptr;
    *num2_ptr = temp;
}

void swap_pass_by_value(int x,int y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int main(void)
{
    int num1=5,num2=3;
    printf("The two numbers before swapping : %d %d\n",num1,num2);
    swap_pass_by_value(num1,num2);
    printf("The two numbers after using swapping by Value : %d %d\n",num1,num2);
    swap_pass_by_reference(&num1,&num2);
    printf("The two numbers after using swapping by reference : %d %d\n",num1,num2);
    return 0;
}
