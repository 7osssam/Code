#include <stdio.h>

int main()
{
    int num;
    scanf("%d", &num);

    if (num % 2 != 0)
    {
        printf("Weird");
    }
    else
    {
        if (num >= 2 && num <= 5)
        {
            printf("Not Weird");
        }
        else if (num >= 6 && num <= 20)
        {
            printf("Weird");
        }
        else if (num >= 20)
        {
            printf("Not Weird");
        }
    }

    return 0;
}
