/*
 ============================================================================
 Name        : Func_Ex7.c
 Author      : Mohamed Tarek
 Description : How to use functions defined from another file
 ============================================================================
 */

#include <stdio.h>
#include "File1.h"

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
