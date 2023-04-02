/*
 ===================================================================================================
 Name        : pointers_ex11.c
 Author      : Mohamed Tarek
 Description : Program to understand how to use pointer to function as a function argument.
 ===================================================================================================
 */

#include <stdio.h>

int add(int a,int b){
	return a+b;
}

int sub(int a,int b){
	return a-b;
}

int mul(int a, int b){
	return a*b;
}

int division(int a,int b){
	return a/b;
}

int operation(int (*ptr_func)(int,int),int a,int b)
{
    return (*ptr_func)(a,b);
}

int main()
{
    int x=10,y=5;
    int result;
    /* call add function using operation function */
    result = operation(add,x,y);
    printf("result of x+y = %d\n",result);
    /* call mul function using operation function */
    result = operation(mul,x,y);
    printf("result of x*y = %d\n",result);
    return 0;
}
