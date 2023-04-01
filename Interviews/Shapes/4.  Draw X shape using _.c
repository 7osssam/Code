#include <stdio.h>

int main()
{
   int row,col,row_col;
   printf("Enter number of row_cols: ");
   scanf("%d",&row_col);
   printf("\n");
   for(row=0; row<row_col; row++)
   {
       for(col=0; col<row_col; col++)
       {
           if(col == row || col == row_col-row-1 )
           {
               printf("*");
           }
           else
           {
               printf(" ");
           }
       }
       printf("\n");
   }
   
    return 0;
}
