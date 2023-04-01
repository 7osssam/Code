#include <stdio.h>
#define size 6
int main()
{
   int i=0,j=0;
   for(j=0; j<size; j++)
   {
       for(i=0; i<j; i++)
       {
           printf("*");
       }
       printf("\n");
   }

    return 0;
}
