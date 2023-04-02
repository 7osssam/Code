/*
 ============================================================================
 Name        : Func_Ex3.c
 Author      : Mohamed Tarek
 Description : Function that print the minimum value of two numbers.
 ============================================================================
 */

#include <stdio.h>

/*
 * Function definition and no need for function prototype
 * as the function is defined before its usage in the main function
 */
void print_min(int num1,int num2)
{
	int min_num;
	if(num1 <= num2)
	{
		min_num =  num1;
	}
	else
	{
		min_num =  num2;
	}
	printf("The Minimum Number is : %d \n",min_num);
}

int main(void)
{
	int a,b;
	/* take the two numbers from the user */
	scanf("%d %d",&a,&b);
	print_min(a,b);
	return 0;
}
