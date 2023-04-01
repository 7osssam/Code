#include <stdio.h>
void Ones(unsigned int num)
{
    int i=0,count=0;
    for(i=0; i<sizeof(int)*8; i++)
    {
        if((num>>i) & 1)
        {
            count++;
        }
    }
    printf("%d",count);
}
int main()
{
    int n;
    printf("Please enter the number: ");
    scanf("%d",&n);
    Ones(n);
    return 0;
}
