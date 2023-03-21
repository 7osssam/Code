#include <stdio.h>

void callbyreference(int *a, int *b)
{
 int c= *a;
 *a = *b;
 *b = c;
 printf("the values of a, b in the called function are %d, %d\n", *a ,*b);
}

int main()
{
    int a= 4, b =5;
    printf("enter the two numbers\n");
    scanf("%d", &a);
    scanf("%d", &b);
    callbyreference(&a,&b);
    printf("the values of a, b in the calling function are %d, %d\n", a ,b);
    

    return 0;
}

//the values of  a and b will  change because we have sent the actual address
//to the function and the changes are affected to the original values.
