#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    unsigned char num = 212, num2 = 0, count_2 = 7;

    for (size_t i = 0; i < 8; i++)
    {
        printf("%d\n", i);
        if (num >> i & 1)
        {
            num2 = num2 | 1 << count_2;
        }
        printf("%d\n", count_2);
        count_2 = count_2 - 1;
    }
    printf("%d", num2);

    return 0;
}
