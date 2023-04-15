#include <stdio.h>

// 1 2 3 4 5
// 1 2 3 4 5
// 1 2 3 4 5
// 1 2 3 4 5
// 1 2 3 4 5
void pattern1(int num)
{
    int i, j;
    for (i = 1; i <= num; i++) //! raws
    {
        for (j = 1; j <= num; j++) //! whats inside the raw (we can call then columns but actually they are not)
        {
            printf("%d ", j); // one raw of pattern
        }
        printf("\n"); // new line
    }
}

// 1 1 1 1 1
// 2 2 2 2 2
// 3 3 3 3 3
// 4 4 4 4 4
// 5 5 5 5 5
void pattern2(int num)
{
    int i, j;
    for (i = 1; i <= num; i++) // 4 rows
    {
        for (j = 1; j <= num; j++)
        {
            printf("%d ", i); // i is the raw counter
        }
        printf("\n"); // new line
    }
}

// * * * * *
// * * * * *
// * * * * *
// * * * * *
// * * * * *
void pattern3(int num)
{
    int i, j;
    for (i = 1; i <= num; i++) // 4 rows
    {
        for (j = 1; j <= num; j++)
        {
            printf("* ");
        }
        printf("\n"); // new line
    }
}

// * * * * *
// *       *
// *       *
// *       *
// * * * * *
void pattern4(int num)
{
    int i, j;
    for (i = 1; i <= num; i++) // rows
    {
        for (j = 1; j <= num; j++)
        {
            if (i == 1 || i == num || j == 1 || j == num) // if we are in the first or last raw (or) first or last column
            {
                printf("* ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n"); // new line
    }
}

// * * * * *
// * *   * *
// *   *   *
// * *   * *
// * * * * *
void pattern5(int num)
{
    int i, j;
    for (i = 1; i <= num; i++) // 4 rows
    {
        for (j = 1; j <= num; j++)
        {
            if (i == 1 || i == num || j == 1 || j == num || i == j || i + j == num + 1)
            { // i = 1 first raw, i = num last raw, j = 1 first column, j = num last column, i = j diagonal from top left to bottom right, i + j = num + 1 diagonal from top right to bottom left
                printf("* ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n"); // new line
    }
}

// *
// * *
// * * *
// * * * *
// * * * * *
void pattern6(int num)
{
    int i, j;
    for (i = 1; i <= num; i++) // raws
    {
        for (j = 1; j <= i; j++) //! the numbr of items in the raw is equal to the raw number
        {
            printf("* ");
        }
        printf("\n"); // new line
    }
}

// * * * * *
// * * * *
// * * *
// * *
// *
void pattern7(int num)
{
    int i, j;
    for (i = 1; i <= num; i++) // raws
    {
        for (int j = i; j <= num; j++) // j = i as we need to print 5 stars in the 1st raw, 4 stars in the 2nd raw, 3 stars in the 3rd raw... etc
        {
            printf("* ");
        }

        printf("\n"); // new line
    }
}

//         *
//       * *
//     * * *
//   * * * *
// * * * * *
void pattern8(int num)
{
    int i, j;

    // method 1     //time complexity: O(n^2)
    for (i = 1; i <= num; i++) // raws
    {
        for (j = 1; j <= num; j++) // columns
        {
            if (j + i <= num) //
            {
                printf("  ");
            }
            else
            {
                printf("* ");
            }
        }
        printf("\n"); // new line
    }
    // // method 2     //time complexity: O(n^2) same as method 1 but it's more readable
    // for (i = 1; i <= num; i++) // raws
    // {
    //     for (j = i; j <= num-1; j++) // printing the spaces
    //     {
    //         printf("  ");
    //     }
    //     for (j = 1; j <= i; j++) // printing the stars
    //     {
    //         printf("* ");
    //     }
    //     printf("\n"); // new line
    // }
}

//           *
//         * * *
//       * * * * *
//     * * * * * * *
//   * * * * * * * * *
void pattern9(int num)
{
    int i, j;
    for (i = 1; i <= num; i++) // raws
    {
        for (j = i; j <= num; j++) // printing the spaces
        {
            printf("  ");
        }
        for (j = 1; j <= (i * 2) - 1; j++) //! (i * 2) - 1 ex: 1*2-1=1, 2*2-1=3, 3*2-1=5, 4*2-1=7, 5*2-1=9
        {
            printf("* ");
        }
        printf("\n"); // new line
    }
}

// *
//   *
//     *
//       *
//         *
//         *
//       *
//     *
//   *
// *
void pattern10(int num)
{
    int i, j; // i raws // j what inside the raws (columns)

    // the first half of the pattern
    for (i = 1; i <= num; i++) // raws
    {
        for (j = 1; j <= i; j++)
        {
            if (i == j) // if we are in the last column
            {
                printf("* ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n"); // new line
    }
    // the second half of the pattern
    for (i = 1; i <= num; i++) // raws
    {
        for (j = i; j <= num; j++)
        {
            if (j == num) // if we are in the last column
            {
                printf("* ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n"); // new line
    }
}

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
void pattern11(int num)
{
    int i, j;
    for (i = 1; i <= num; i++) // raws
    {
        for (j = 1; j <= num; j++) // columns
        {
            if (i == j || i + j == num + 1) // if we are in the diagonal OR (i == j || j == num - i + 1)
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

int main()
{
    int num, choice;

    printf("Enter a choice ");
    scanf("%d", &choice);

    printf("Enter a number");
    scanf("%d", &num);

    switch (choice)
    {
    case 1:
        pattern1(num);
        break;
    case 2:
        pattern2(num);
        break;
    case 3:
        pattern3(num);
        break;
    case 4:
        pattern4(num);
        break;
    case 5:
        pattern5(num);
        break;
    case 6:
        pattern6(num);
        break;
    case 7:
        pattern7(num);
        break;
    case 8:
        pattern8(num);
        break;
    case 9:
        pattern9(num);
        break;
    case 10:
        pattern10(num);
        break;
    case 11:
        pattern11(num);
        break;
    default:
        printf("Invalid choice");
        break;
    }

    return 0;
}
