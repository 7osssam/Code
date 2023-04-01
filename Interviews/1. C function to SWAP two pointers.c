#include <stdio.h>
void SwapPointer(int *p1, int *p2)
{
    int temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
    printf("First pointer = %d\nSecond pointer = %d",*p1,*p2);
}
int main()
{
   int n1,n2;
   printf("Enter first number: ");
   scanf("%d",&n1);
   printf("Enter second number: ");
   scanf("%d",&n2);
   SwapPointer(&n1,&n2);

    return 0;
}
