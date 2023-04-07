//? https://www.hackerrank.com/challenges/recursion-in-c/problem
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
////////////////! Complete the following function.

int find_nth_term(int n, int a, int b, int c)
{

    if (n == 1) // base case
    {
        return a; // return the first term
    }
    else if (n == 2) // base case
    {
        return b; // return the second term
    }
    else if (n == 3) // base case
    {
        return c; // return the third term
    }
    else // recursive case
    {

        return find_nth_term(n - 1, a, b, c) + find_nth_term(n - 2, a, b, c) + find_nth_term(n - 3, a, b, c);
    }
}

////////////////!
int main()
{
    int n, a, b, c;

    scanf("%d %d %d %d", &n, &a, &b, &c);
    int ans = find_nth_term(n, a, b, c);

    printf("%d", ans);
    return 0;
}