#include <stdio.h>

// 1 2 3 4 5
// 1 2 3 4 5
// 1 2 3 4 5
// 1 2 3 4 5
void pattern1()
{
    int i, j;
    for (j = 1; j <= 4; j++) //! raws
    {
        for (i = 1; i <= 5; i++) //! whats inside the raw (we can call then columns but actually they are not)
        {
            printf("%d ", i); // one raw of pattern
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
    for (j = 1; j <= 4; j++) // 4 rows
    {
        for (i = 1; i <= 5; i++)
        {
            printf("%d ", j); // j is the raw counter
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
    for (j = 1; j <= 4; j++) // 4 rows
    {
        for (i = 1; i <= 5; i++)
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
    for (j = 1; j <= 5; j++) // 5 rows
    {
        for (i = 1; i <= 5; i++)
        {
            if (j == 1 || j == 5 || i == 1 || i == 5) // if we are in the first or last raw   or  first or last column
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
    for (j = 1; j <= 5; j++) // 4 rows
    {
        for (i = 1; i <= 5; i++)
        {
            if (i == 2 && j == 3 || i == 3 && j == 2 || i == 3 && j == 4 || i == 4 && j == 3)
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
    for (j = 1; j <= 5; j++) // raws
    {
        for (i = 1; i <= j; i++) //! the numbr of items in the raw is equal to the raw number
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
    for (j = 1; j <= 5; j++) // raws
    {
        // we used the same logic as the previous pattern but we are printing the items in reverse order
        // so we start from the last item in the raw and we print it until we reach the first item in the raw
        for (i = 5; i >= j; i--) //! the numbr of items in the raw is equal to the raw number
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
    for (j = 1; j <= 5; j++) // raws
    {
        for (i = 1; i <= 5; i++) // columns
        {
            if (i + j <= 5) //
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
}

//           *
//         * * *
//       * * * * *
//     * * * * * * *
//   * * * * * * * * *
void pattern9()
{
    int i, j, k;
    for (j = 1; j <= 5; j++) // raws
    {
        for (i = j; i <= 5; i++) // printing the spaces
        {
            printf("  ");
        }
        for (k = 1; k <= (j * 2) - 1; k++) //! (j * 2) - 1 as we need to print 1 star in the 1st raw, 3 stars in the 2nd raw, 5 stars in the 3rd raw... etc
        {
            printf("* ");
        }
        printf("\n"); // new line
    }
}
int main()
{
    // printf("Pattern 1: \n" );  pattern1();  printf("\n");
    // printf("Pattern 2: \n" );  pattsern2();  printf("\n");
    // printf("Pattern 3: \n" );  pattern3();  printf("\n");
    // printf("Pattern 4: \n" );  pattern4();  printf("\n");
    // printf("Pattern 5: \n" );  pattern5();  printf("\n");
    // printf("Pattern 6: \n" );  pattern6();  printf("\n");
    // printf("Pattern 7: \n" );  pattern7();  printf("\n");
    // printf("Pattern 8: \n" );  pattern8();  printf("\n");
    printf("Pattern 9: \n");
    pattern9();
    printf("\n");

    return 0;
}
