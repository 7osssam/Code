#include <stdio.h>

void callname(int rem)
{
    switch(rem)
    {
        case 0: printf("zero\t"); break;
        case 1: printf("one\t"); break;
        case 2: printf("two\t"); break;
        case 3: printf("three\t"); break;
        case 4: printf("four\t"); break;
        case 5: printf("five\t"); break;
        case 6: printf("six\t"); break;
        case 7: printf("seven\t"); break;
        case 8: printf("eight\t"); break;
        case 9: printf("nine\t"); break;
        default: printf("wrong choice\n");break;
        
    }
}

int main()
{
    
    int a = 1023, temp=0, count=0, rem=0, sum=0;
    printf("enter the number\n");
    scanf("%d", &a);
    printf("you entered %d\n", a);
    temp = a;
    while(temp >0)
    {
        temp=  temp/10;
        count++;
    }
    temp = a;
    while(temp > 0)
    {
        rem = temp % 10;
       sum = sum*10 + rem;
        
        temp /= 10;
        
    }
    temp = sum;
    while(temp > 0)
    {
        rem = temp % 10;
        callname(rem);
        temp /= 10;
        
    }
    return 0;
}