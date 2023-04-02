/*
 ===================================================================================================
 Name        : pointers_ex12.c
 Author      : Mohamed Tarek
 Description : Program to understand how to use array of pointers to function.
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

int main()
{
    int result,operation,x,y;
    int (*ptr_func[4])(int,int) ={add,sub,mul,division}; //make 4 pointers point to 4 functions
    printf("please enter the required operation : \n0:add\t1:sub\t2:mul\t3:division\n");
    scanf("%d",&operation);
    printf("please enter two number for the operation: \n");
    scanf("%d %d",&x,&y);
    result = (*ptr_func[operation])(x,y); // call the required function
    printf("result=%d\n",result);
    return 0;
}
