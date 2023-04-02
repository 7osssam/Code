/*
 ===================================================================================================
 Name        : pointers_ex9.c
 Author      : Mohamed Tarek
 Description : Program to understand how to call function through pointer to function.
 ===================================================================================================
 */

#include <stdio.h>

int add(int a,int b)
{
	return a+b;
}

int sub(int a,int b)
{
	return a-b;
}

int mul(int a, int b)
{
	return a*b;
}

int division(int a,int b)
{
	return a/b;
}

int main(void)
{
    int result1;
    int result2;
    int result3;
    int (*ptr_func)(int,int) = add; //make pointer points to the add function
    result1 = add(3,2); // Normal function call
    printf("result1=%d\n",result1);
    result2 = ptr_func(3,2); // call add function using pointer which points to it
    printf("result2=%d\n",result2);
    result3 = (*ptr_func)(3,2); // call add function using pointer which points to it
    printf("result3=%d\n",result3);
    return 0;
}
