/*
 ===================================================================================================
 Name        : array_ex8.c
 Author      : Mohamed Tarek
 Description : Program to understand how to access multi-diementional array
 ===================================================================================================
 */

#include <stdio.h>

int main(void)
{
	int a[2][2], b[2][2], c[2][2];
	int i,j;
	printf("Enter the elements of 1st matrix\n");

	/* Reading two dimensional Array with the help of two for loop.
	 * If there was an array of 'n' dimension, 'n' numbers of loops are needed for inserting data to array.*/
	for(i=0;i<2;++i)
	{
		for(j=0;j<2;++j)
		{
			printf("Enter a[%d][%d]: ",i,j);
			scanf("%d",&a[i][j]);
		}
	}

	printf("Enter the elements of 2nd matrix\n");
	for(i=0;i<2;++i)
	{
		for(j=0;j<2;++j)
		{
			printf("Enter b[%d][%d]: ",i,j);
			scanf("%d",&b[i][j]);
		}
	}

	for(i=0;i<2;++i)
	{
		for(j=0;j<2;++j)
		{
			/* Sum of corresponding elements of two arrays. */
			c[i][j]=a[i][j]+b[i][j];
		}
	}

	printf("\nSum Of Matrix:\n");
	for(i=0;i<2;++i)
	{
		for(j=0;j<2;++j)
		{
			printf("%d\t",c[i][j]);
			if(j==1)             /* To display matrix sum in order. */
				printf("\n");
		}
	}
	return 0;
}
