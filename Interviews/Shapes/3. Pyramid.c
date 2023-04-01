#include <stdio.h>
#define size 6
int main()
{
   int i=0,row=0,row_col;
   printf("Please enter the column: ");
   scanf("%d",&row_col);
   for(row=0; row<row_col; row++)
   {
       for(i=row; i<row_col-1; i++)
       {
           printf(" ");
       }
       
       for(i=0; i<((2*row)+1);i++)
       {
           printf("*");
       }
       printf("\n");
   }

    return 0;
}
