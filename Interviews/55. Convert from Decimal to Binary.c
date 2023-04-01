#include <stdio.h>
void Binary_Representation(int num)
{
    int count = 31;
    while(count != -1)
    {
        printf("%d",(num>>count)&1);
        count--;
    }
}
int main()
{
    int n;
    printf("Enter the number: ");
    scanf("%d",&n);
    Binary_Representation(n);
    return 0;
}
