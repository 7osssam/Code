#include <stdio.h>

int main()
{
    int row,col,row_col,i;
    printf("Enter row_col: ");
    scanf("%d",&row_col);
    for(row = 0; row<row_col; row++)
    {
        for(col=row; col<row_col-1; col++)
        {
            printf(" ");
        }
        for(i=0; i<(2*row)+1;i++)
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
