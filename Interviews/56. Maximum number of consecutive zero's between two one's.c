#include <stdio.h>

int main()
{
    int num;
    printf("Please enter the number: ");
    scanf("%d",&num);
    int max = 0;
    int count = 0;
    int flag = 0;
    while(num>0)
    {
        if(num & 1)
        {
            if(count>max)
            {
                max = count;
            }
            count = 0;
            flag =1;
        }
        else if(flag == 1)
        {
            count++;
        }
        num>>=1;
    }
printf("%d",max);
    return 0;
}
