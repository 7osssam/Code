// Write a C Function that check if the number if positive or negative

#include <stdio.h>

int CheckNum(int num)
{
    if (num >= 0)
        return 1;

    return 0;
}

int main()
{
    int num;

    printf("Enter num : ");
    scanf("%d", &num);

    if (CheckNum(num))
    {
        printf("positive");
    }
    else
    {
        printf("negative");
    }

    return 0;
}