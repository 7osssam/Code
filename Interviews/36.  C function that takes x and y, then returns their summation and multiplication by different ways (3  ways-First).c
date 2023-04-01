#include <stdio.h>
int Addition(int x, int y)
{
    int result;
    result = x+ y;
    return result;
}
int main()
{
    int num1,num2,r;
    printf("Enter first number: ");
    scanf("%d",&num1);
    printf("Enter second number: ");
    scanf("%d",&num2);
    r = Addition(num1,num2);
    printf("Result = %d",r);
    return 0;
}
