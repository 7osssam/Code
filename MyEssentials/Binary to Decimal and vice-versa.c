#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void DestoBi(int num)
{
    if (num > 1)
        DestoBi(num / 2);

    printf("%d", num % 2);
}

void BitoDes(int num)
{
    int des = 0, bit, i = 0;
    while (num != 0)
    {
        bit = num & 1; // or bit = n % 10
        des = des + bit * pow(2, i);
        num /= 10, i++;
    }
    printf("%d", des);
}
int main()
{
    unsigned int num = 10111011;
    // DestoBi(num);
    BitoDes(num);
    // printf("%d" , DestoBi(num));

    return 0;
}
