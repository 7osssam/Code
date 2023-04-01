#include <stdio.h>
int Root3(int num)
{
    int res = 0;
    if(num == 0 || num == 1)
    {
        return num;
    }
    while(res*res*res <= num)
    {
        res++;
    }
    return res-1;
}
int main()
{
   int n;
   printf("Please enter the number: ");
   scanf("%d",&n);
   printf("%d",Root3(n));

    return 0;
}
