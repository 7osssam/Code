/*
 ===================================================================================================
 Name        : Func_Ex1.c
 Author      : Mohamed Tarek
 Description : Code to print the addition, subtraction, multiplication and division for 2 numbers
 ===================================================================================================
 */

#include <stdio.h>

/*************** Functions Prototypes ***************/
float add(float x,float y);
float sub(float x,float y);
float mul(float x,float y);
float division(float x,float y);

/*************** Main Programs ***************/
int main(void)
{
    float a=5,b=3,c;
    c = add(a,b);
    printf("a+b=%f\n",c);
    c = sub(a,b);
    printf("a-b=%f\n",c);
    c = mul(a,b);
    printf("a*b=%f\n",c);
    c = division(a,b);
    printf("a/b=%f\n",c);
    return 0;
}

/*************** Functions Definitions ***************/
float add(float x,float y)
{
    return x+y;
}

float sub(float x,float y)
{
    return x-y;
}

float mul(float x,float y)
{
    return x*y;
}

float division(float x,float y)
{
    return x/y;
}
