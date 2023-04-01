/*
 ===================================================================================================
 Name        : Operators_Ex4.c
 Author      : Mohamed Tarek
 Description : Code to demonstrate the capability of the Compiler optimization with Logical operators
 ===================================================================================================
 */

#include<stdio.h>

int main()
{
    int num = 30;

    int x = 10;

    if(num>=30 || x++)
    {
    	/* First condition is True, so compiler will not evaluate the second condition as
    	 * the OR logical operator will be True even the second condition is True/False
    	 */
    	printf("First Condition x = %d\n",x);
    }

    if(num>=40 || x++)
    {
    	/* First condition is False, so compiler will evaluate the second condition normally */
    	printf("Second Condition x = %d\n",x);
    }

    if(num>=30 && x++)
    {
    	/* First condition is True, so compiler will evaluate the second condition normally */
    	printf("Third Condition x = %d\n",x);
    }

    if(num>=40 && x++)
    {
    	/* First condition is False, so compile will not evaluate the second condition as
    	 * the AND logical operator will be False even the second condition is True/False
    	 */
    	printf("Forth Condition x = %d\n",x);
    }

    return(0);
}
