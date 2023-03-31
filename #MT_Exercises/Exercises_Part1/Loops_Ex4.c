/*
 ===================================================================================================
 Name        : Loops_Ex4.c
 Author      : Mohamed Tarek
 Description : Code to calculate and print the factorial of any input number
 ===================================================================================================
 */

#include <stdio.h>

int main()
{
    int num,i;
    long long fact_result = 1;
    printf("Enter any number to calculate the factorial: ");
    scanf("%d",&num);
    for(i=1;i<=num;i++)
    {
        fact_result = fact_result * i;
    }
    printf("\nFactorial of number %d is : %ld\n",num,fact_result);
    return 0;
}
