#include <stdio.h>

int Root5(int num)
{
     int res=0;
    if(num == 0 || num == 1)
    {
        return num;
    }
  
    while(res*res*res*res*res <= num)
    {
        res++;
    }
    return res-1;
}
int main()
{
   
    int n;
    printf("Please Enter the number: ");
    scanf("%d",&n);
    printf("%d",Root5(n));
    return 0;
}
