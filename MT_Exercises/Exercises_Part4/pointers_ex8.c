/*
 ===================================================================================================
 Name        : pointers_ex8.c
 Author      : Mohamed Tarek
 Description : Program to use different types of pointers.
 ===================================================================================================
 */

#include <stdio.h>

int main(void)
{
	char str1[] = { 'A', 'B', 'C', 'D', 'E' };
	char str2[] = "ABCDE";
	char *str3 = "ABCDE";
	char  *cPtr = str1;

	short sArr[] = {1, 2, 3, 4, 5};
	short sArr2D[][5] = { {1, 2, 3, 4, 5},
						  {6, 7, 8, 9, 10} };
	short *sPtr1 = sArr;
	short (*sPtr2)[5] = sArr2D;
	short *sPtr3[5];

	printf("sizeof(str1) = %u\n", sizeof(str1));
	printf("sizeof(str2) = %u\n", sizeof(str2));
	printf("sizeof(str3) = %u\n", sizeof(str3));
	printf("sizeof(cPtr) = %u\n", sizeof(cPtr));
	printf("\n");

	printf("sizeof(sArr) = %u\n", sizeof(sArr));
	printf("sizeof(sPtr1) = %u\n", sizeof(sPtr1));
	printf("sizeof(sArr2D) = %u\n", sizeof(sArr2D));
	printf("sizeof(sPtr2) = %u\n", sizeof(sPtr2));
	printf("sizeof(*sPtr2) = %u\n", sizeof(*sPtr2));
	printf("sizeof(sPtr3) = %u\n", sizeof(sPtr3));
	printf("\n");

	printf("sArr2D[1][2] = %d\n", sArr2D[1][2]);
	printf("sPtr2[0][0] = %d, sPtr2[1][2] = %d\n", sPtr2[0][0], sPtr2[1][2]);
	printf("*(* (sArr2D + 1) + 2) = %d\n", *(* (sArr2D + 1) + 2)); // same as sArr2D[1][2]
	printf("*(*(sArr2D) + 1*5 + 2) = %d\n\n", *(*(sArr2D) + 1*5 + 2)); // same as sArr2D[1][2]
	return 0;
}
