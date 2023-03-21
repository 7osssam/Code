#include <stdio.h>


int fact(int n)
{
     if(n == 1 || n ==0)
     return 1;
     else
     return n * fact(n-1); 
    
}

int main()
{
    int n = 145;
    printf(" you entered %d\n", n);
    int temp, i, rem , sum = 0;
    temp = n;
    while(temp >0)
    {
        
        rem = temp % 10;
        sum = sum + fact(rem);
        temp = temp/10;
    }
    if(sum == n)
        printf("yes, it is a strong number %d\n", sum); 
    
    else
        printf("no it is not a strong %d\n", sum);
    
   
    return 0;
    
}