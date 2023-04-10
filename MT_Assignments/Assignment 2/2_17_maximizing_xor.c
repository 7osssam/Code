// 17 - Given two integers: L and R, Find the maximal value of A xor B (A^B)
// where A and B satisfy the condition L =< A <= B <= R
// Constrains: 1 <= L <= R <= 1000
// Input format : the input contains two lines first line contains Land next line contains R.
// Output format: The maximum value of A xor B

#include <stdio.h>

int maxXOR(int L, int R)
{
    int max = 0;
    for (int i = L; i <= R; i++)
    {
        for (int j = i; j < R; j++) // j = i to avoid duplicate values
        {
            if ((i ^ j) > max)
                max = i ^ j;
        }
    }
    return max;
}

int main()
{
    int L, R; // declare the range variables

    printf("Enter the range: ");
    scanf("%d%d", &L, &R); // take input of the range

    printf("The maximum value of the range %d xor %d is: %d ", L, R, maxXOR(L, R));
    return 0;
}