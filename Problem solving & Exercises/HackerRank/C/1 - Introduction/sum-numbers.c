// ? hackerrank.com/challenges/sum-numbers-c/problem

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int a, b;
    float x, y;
    scanf("%d%d", &a, &b);
    scanf("%f%f", &x, &y);

    printf("%d %d\n", a + b, a - b);
    printf("%.1f %.1f\n", x + y, x - y);

    return 0;
}
