#include <stdio.h>

// 1 2 3 4 5
// 1 2 3 4 5
// 1 2 3 4 5
// 1 2 3 4 5
void pattern1()
{
    int i, j;
    for (i = 1; i <= 4; i++) //! raws
    {
        for (j = 1; j <= 5; j++) //! whats inside the raw (we can call then columns but actually they are not)
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
void pattern2()
{
    int i, j;
    for (i = 1; i <= 4; i++) // 4 rows
    {
        for (j = 1; j <= 5; j++)
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
void pattern3()
{
    int i, j;
    for (i = 1; i <= 4; i++) // 4 rows
    {
        for (j = 1; j <= 5; j++)
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
void pattern4()
{
    int i, j;
    for (i = 1; i <= 5; i++) // 5 rows
    {
        for (j = 1; j <= 5; j++)
        {
            if (i == 1 || i == 5 || j == 1 || j == 5) // if we are in the first or last raw   or  first or last column
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
void pattern5()
{
    int i, j;
    for (i = 1; i <= 5; i++) // 4 rows
    {
        for (j = 1; j <= 5; j++)
        {
            if (j == 2 && i == 3 || j == 3 && i == 2 || j == 3 && i == 4 || j == 4 && i == 3)
            { // here we are only excluding the spaces in the middle of the pattern
                printf("  ");
            }
            else // and printing the rest
            {
                printf("* ");
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
void pattern6()
{
    int i, j;
    for (i = 1; i <= 5; i++) // raws
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
void pattern7()
{
    int i, j;
    for (i = 1; i <= 5; i++) // raws
    {
        for (int j = i; j <= 5; j++) // j = i as we need to print 5 stars in the 1st raw, 4 stars in the 2nd raw, 3 stars in the 3rd raw... etc
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
void pattern8()
{
    int i, j;

    // method 1     //time complexity: O(n^2)
    for (i = 1; i <= 5; i++) // raws
    {
        for (j = 1; j <= 5; j++) // columns
        {
            if (j + i <= 5) //
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

    // method 2     //time complexity: O(n^2) same as method 1 but it's more readable
    for (i = 1; i <= 5; i++) // raws
    {
        for (j = i; j <= 4; j++) // printing the spaces
        {
            printf("  ");
        }
        for (j = 1; j <= i; j++) // printing the stars
        {
            printf("* ");
        }
        printf("\n"); // new line
    }
}

//           *
//         * * *
//       * * * * *
//     * * * * * * *
//   * * * * * * * * *
void pattern9()
{
    int i, j, k;
    for (i = 1; i <= 5; i++) // raws
    {
        for (j = i; j <= 5; j++) // printing the spaces
        {
            printf("  ");
        }
        for (k = 1; k <= (i * 2) - 1; k++) //! (i * 2) - 1 as we need to print 1 star in the 1st raw, 3 stars in the 2nd raw, 5 stars in the 3rd raw... etc
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

void pattern10()
{
    int i, j; // i raws // j what inside the raws (columns)

    // the first half of the pattern
    for (i = 1; i <= 5; i++) // raws
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

    for (i = 1; i <= 5; i++) // raws
    {
        for (j = i; j <= 5; j++)
        {
            if (j == 5) // if we are in the last column
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

void pattern11()
{
    int i, j; // i raws // j what inside the raws (columns)
    int k, l;
    // the first half of the pattern
    for (i = 1; i <= 5; i++) // raws
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
        int x = 0;
        for (k = 5; k <= (k * 2) - 1; k--) // spaces in the middle
        {
            printf("$ ");
        }

        printf("\n"); // new line
    }

    for (i = 1; i <= 5; i++) // raws
    {
        for (j = i; j <= 5; j++)
        {
            if (j == 5) // if we are in the last column
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
int main()
{
    //  printf("Pattern 1: \n" );  pattern1();  printf("\n");
    //  printf("Pattern 2: \n" );  pattern2();  printf("\n");
    //  printf("Pattern 3: \n" );  pattern3();  printf("\n");
    //  printf("Pattern 4: \n" );  pattern4();  printf("\n");
    //  printf("Pattern 5: \n" );  pattern5();  printf("\n");
    //  printf("Pattern 6: \n" );  pattern6();  printf("\n");
    //  printf("Pattern 7: \n" );  pattern7();  printf("\n");
    //  printf("Pattern 8: \n" );  pattern8();  printf("\n");
    //  printf("Pattern 9: \n" );  pattern9();  printf("\n");
    //  printf("Pattern 10:\n" );  pattern10(); printf("\n");
    printf("Pattern 11: \n");
    pattern11();
    printf("\n");

    return 0;
}
