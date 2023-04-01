#include <stdio.h>
void Ones_zeros(unsigned char c)
{
    int i=0,count1=0,count2=0;
    for(i=0; i<sizeof(char)*8; i++)
    {
        if((c>>i) & 1)
        {
            count1++;
        }
        else
        {
            count2++;
        }
    }
    printf("No. of Zeros: %d\nNo. of Ones: %d",count2,count1);
    
}
int main()
{
   char n;
   printf("Please enter the character: ");
   scanf("%c",&n);
   Ones_zeros(n);
    return 0;
}
