#include <stdio.h>

int main()
{
    int i, j;
    for(i = 1; i<=5; i++)
    {
        for(j=1; j <= 5; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}

//output
//*****
//*****
//*****
//*****
//*****

//i signifies number of rows
//and j signifies number of stars
//the inner loop prints five stars
//and forms a new line and the outer loop 
//prints numner of rows