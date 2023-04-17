//? https://www.hackerrank.com/challenges/staircase/problem
// print a staircase pattern
//       #
//      ##
//     ###
//    ####
//   #####
//  ######
// #######
#include <stdio.h>

void pattern(int num)
{
    for (int i = 1; i <= num; i++)
    {
        for (int j = i; j < num; j++) // not ( j <= num ) because The last line must have 0 spaces in it.
        {
            printf(" ");
        }
        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }

        printf("\n");
    }
}

int main()
{
    int num;
    scanf("%d", &num);

    pattern(num);

    return 0;
}