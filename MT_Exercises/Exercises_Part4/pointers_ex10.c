/*
 ===================================================================================================
 Name        : pointers_ex10.c
 Author      : Mohamed Tarek
 Description : Program to understand how to use pointer to function to point to a different function
  	  	  	   in every run (flexibility)
 ===================================================================================================
 */

#include <stdio.h>

int add(int a,int b){
	return a+b;
}

int sub(int a,int b){
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
    int x,y;
    int result;
    int operation;
    int (*ptr_func)(int,int) = NULL; //pointer to function
    printf("please enter the required operation : \n0:add\t1:sub\t2:mul\t3:division\n");
    scanf("%d",&operation);

    /* choose the required function according to the operation */
    switch(operation)
    {
        case 0: ptr_func = add;
                break;
        case 1: ptr_func = sub;
        		break;
        case 2: ptr_func = mul;
                break;
        case 3: ptr_func = division;
                break;
        default: printf("Invalid input\n");
                 break;
    }
    printf("please enter two number for the operation: \n");
    scanf("%d %d",&x,&y);
    result = (*ptr_func)(x,y); // call the chosen function using pointer to function.
    printf("result=%d\n",result);
    return 0;
}
