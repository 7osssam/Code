#include <stdio.h>
int Toggle(int PinState)
{
    PinState^=1;
    return PinState;
}
int main()
{
   int s,x;
   printf("Please enter the state: ");
   scanf("%d",&s);
 x =  Toggle(s);
printf("State after toggle = %d",x);
    return 0;
}
