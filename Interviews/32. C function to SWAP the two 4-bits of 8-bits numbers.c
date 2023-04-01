#include <stdio.h>
void SWAP(int num)
{
    num = (num>>4) |(num<<4);
    printf("Number = %d ",num);
}
int main()
{
    int n;
    printf("Please enter the number: ");
    scanf("%d",&n);
     SWAP(n);
    return 0;
}
