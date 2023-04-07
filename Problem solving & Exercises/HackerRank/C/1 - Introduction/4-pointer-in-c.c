//? hackerrank.com/challenges/pointer-in-c/problem
#include <stdio.h>
#include <stdlib.h>

// void update(int *a,int *b) // old function
// {
//    int x, y;
//    x  = *a;
//    y  = *b;
//    *a = *a+*b;
//    if (x > y)
//    {*b = x-y;}
//    else
//    {*b = y-x;}
// }

void update(int *a, int *b) // better function
{
    int x; // less variables
    x = *a;
    *a = *a + *b;
    *b = abs(x - *b);
}

int main()
{
    int a, b;
    int *pa = &a, *pb = &b;

    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
