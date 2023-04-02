// (21) Write a program to print the following X pattern:
// *                 *
//   *             *
//     *         *
//       *     *
//         * *
//         * *
//       *     *
//     *         *
//   *             *
// *                 *

#include <stdio.h>

int main()
{
    int i, j;
    for (i = 1; i <= 10; i++) // raws
    {
        for (j = 1; j <= 10; j++) // columns
        {
            if (i == j || i + j == 11) // if we are in the diagonal OR (i == j || j == 10 - i + 1)
            {
                printf("* ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}