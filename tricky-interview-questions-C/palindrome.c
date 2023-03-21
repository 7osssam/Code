#include <stdio.h>

int main()
{
    int n = 147841;
    int temp, count, sum, rem;
    temp =n;
    while(temp != 0)
    {
        sum = sum*10 + temp%10;
        temp = temp/10;
    }
    if(n == sum)
    printf("yes, %d is pailndrome\n", sum);
    else
    printf("no, %d is not pailndrome\n", sum);
    return 0;
}