// Title: check whether the triangle is isosceles or not
#include <stdio.h>
int main()
{
    int side_1, side_2, side_3;
    printf("Enter triangle sides");
    scanf("%d%d%d", &side_1, &side_2, &side_3);

    if (side_1 == side_2 || side_1 == side_3 || side_2 == side_3)
    {
        printf("isosceles");
    }
    else
    {
        printf("NOT isosceles");
    }

    return 0;
}