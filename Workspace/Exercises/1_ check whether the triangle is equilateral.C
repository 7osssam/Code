// file name: C program to check whether the triangle is equilateral.C

#include <stdio.h>

int main()
{
    int side_1, side_2, side_3;
    printf("Enter triangle sides ");
    scanf("%d%d%d", &side_1, &side_2, &side_3);

    if (side_1 == side_2 && side_1 == side_3)
    {
        printf("Triangle is equilateral");
    }
    else
    {
        printf("It's not equilateral");
    }

    return 0;
}