// (20) Write a programto display a full pyramid using starspattern.
//           *
//         * * *
//       * * * * *
//     * * * * * * *
//   * * * * * * * * *

#include <stdio.h>

int main()
{
    int i, j;
    for (i = 1; i <= 5; i++) // raws
    {
        for (j = i; j <= 5; j++) // printing the spaces
        {
            printf("  ");
        }
        for (j = 1; j <= (i * 2) - 1; j++) //! (i * 2) - 1 ex: 1*2-1=1, 2*2-1=3, 3*2-1=5, 4*2-1=7, 5*2-1=9
        {
            printf("* ");
        }
        printf("\n"); // new line
    }

    return 0;
}