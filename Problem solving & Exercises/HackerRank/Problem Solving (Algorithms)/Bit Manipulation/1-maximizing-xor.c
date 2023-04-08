//? https://www.hackerrank.com/challenges/maximizing-xor/problem
#include <stdio.h>

//////////////////////////////////////!
int maximizingXor(int l, int r)
{
    int MaxXOR = 0;              // declare maximum XOR variable
    for (int i = l; i <= r; i++) // loop for the first number
    {
        for (int j = i; j <= r; j++) // loop for the second number
        {
            if ((i ^ j) > MaxXOR) // if the XOR of the two numbers is greater than the current maximum XOR
                MaxXOR = i ^ j;   // update the maximum XOR
        }
    }
    return MaxXOR;
}
//////////////////////////////////////!

int main()
{
    int l, r;              // declare the range variables
    scanf("%d%d", &l, &r); // take input of the range
    printf("%d", maximizingXor(l, r));
    return 0;
}
