#include <stdio.h>
void Count(int num)
{
    int Ones=0,Zeros=0,i=0;
    while(num !=0)
    {
        if(num &1)
        {
            Ones++;
        }
        else
        {
            Zeros++;
        }
        
       i++; 
       num>>=1;
    }
    printf("Zeros = %d\nOnes = %d",Zeros,Ones);
}
int main()
{
    int n;
    printf("Please enter the number: ");
    scanf("%d",&n);
    Count(n);

    return 0;
}
