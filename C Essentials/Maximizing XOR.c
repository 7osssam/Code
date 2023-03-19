// explaing this code
// https://www.hackerrank.com/challenges/maximizing-xor/problem

#include <stdio.h>

int max_xor(int l, int r)
{
    int xor = 0;
    for (int i = l; i <= r; i++)
    {
        for (int j = i; j <= r; j++)
        {
            if ((i ^ j) > xor)
                xor = i ^ j;
        }
    }
    return xor;
}

int main()
{
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%d", max_xor(l, r));
    return 0;
}
