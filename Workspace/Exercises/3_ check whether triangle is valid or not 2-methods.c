// Title: check whether triangle is valid or not 2-methods

// triangle inequality theorem:
// if you add any two sides then it will be greater than the third side
#include <stdio.h>

int main()
{

    int side_1, side_2, side_3;
    int angle_1, angle_2, angle_3;
    int sum;

    // method 1
    printf("Enter triangle sides ");
    scanf("%d%d%d", &side_1, &side_2, &side_3);

    if (side_1 + side_2 > side_3 || side_1 + side_3 > side_2 || side_3 + side_2 > side_1)
    {
        printf("this is a tringle");
    }
    else
    {
        printf("Nahhh ");
    }

    // method 2
    printf("Enter angles sides ");
    scanf("%d%d%d", &angle_1, &angle_2, &angle_3);
    sum = angle_1 + angle_2 + angle_3;
    if (sum == 180 && angle_1 != 0 && angle_2 != 0 && angle_3 != 0)
    {
        printf("this is a tringle");
    }
    else
    {
        printf("Nahhh ");
    }
    return 0;
}