#include <stdio.h>

int main()
{
    int n = 2016;
    if(n % 4 == 0)
    {
       if(n % 100 == 0)
       {
           if( n % 400 == 0)
               printf("the number is leap year %d\n", n);
           else
               printf("the number is not leap year %d\n", n);
       }
       else
       {
               printf("the number is leap year %d\n", n);

       }
    }
    else
    {
    printf("the number is not leap year %d\n", n);
    }
    return 0;
}