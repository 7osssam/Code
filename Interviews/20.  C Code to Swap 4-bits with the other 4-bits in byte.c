#include <stdio.h>

int main()
{ 
   unsigned int num;
   printf("Please enter the number: ");
   scanf("%d",&num);
   num = (num<<4) | (num >> 4);
   printf("%d",num);
    return 0;
}
