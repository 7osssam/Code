//? hackerrank.com/challenges/functions-in-c/problem

#include <stdio.h>
// int max_of_four(int a, int b, int c, int d) //! old function
// {
//     if (a > b && a > c && a > d)
//     {
//         return a;
//     }
//     else if (b > a && b > c && b > d)
//     {
//         return b;
//     }
//     else if (c > a && c > b && c > d)
//     {
//         return c;
//     }
//     else if (d > a && d > c && d > b)
//     {
//         return d;
//     }
//     return 0;
// }

int max_of_four(int a, int b, int c, int d) // better function
{
    int max = a; // assume a is the max
    if (b > max)
    {
        max = b;
    }
    if (c > max)
    {
        max = c;
    }
    if (d > max)
    {
        max = d;
    }
    return max;
    // it's better to use another variable to store the max value
    // and return it at the end of the function
    // instead of returning the value in the if statement
}
int main()
{
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);

    return 0;
}
