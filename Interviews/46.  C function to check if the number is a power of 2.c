#include <stdio.h>
void Power2(int num)
{
    if((num !=0) && ((num & (num-1)) == 0))
    {
        printf("%d is power of 2",num);
    }
    else
    {
        printf("%d is not power of 2",num);
    }
}
int main()
{
   int n;
   printf("Enter the number: ");
   scanf("%d",&n);
Power2(n);
    return 0;
}
