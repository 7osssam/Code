// https://open-gl.com/2010/05/20/pointers/

#include <stdio.h>

void trick1()
{
       int arr[] = {1, 2, 3};
       int *ptr;

       ptr = arr;

       printf("arr[0] = %d, arr[1] = %d, arr[2] = %d, ptr = %p, *ptr = %d\n",
              arr[0], arr[1], arr[2], ptr, *ptr);
       *ptr++ = -1; // is equivalent to *(ptr++) = -1; which is equivalent to *ptr = -1; ptr++;
       printf("arr[0] = %d, arr[1] = %d, arr[2] = %d, ptr = %p, *ptr = %d\n",
              arr[0], arr[1], arr[2], ptr, *ptr);
       *++ptr = -2; // is equivalent to *(++ptr) = -2; which is equivalent to ptr++; *ptr = -2;
       printf("arr[0] = %d, arr[1] = %d, arr[2] = %d, ptr = %p, *ptr = %d\n",
              arr[0], arr[1], arr[2], ptr, *ptr);
       (*ptr)++; // is equivalent to *ptr = *ptr + 1;
       printf("arr[0] = %d, arr[1] = %d, arr[2] = %d, ptr = %p, *ptr = %d\n",
              arr[0], arr[1], arr[2], ptr, *ptr);
}

void trick2()
{
       int arr[] = {1, 2, 3};

       *arr = 5;
       printf("arr[0] = %d, arr[1] = %d, arr[2] = %d\n",
              arr[0], arr[1], arr[2]);
       *(arr + 1) = 10;
       printf("arr[0] = %d, arr[1] = %d, arr[2] = %d\n",
              arr[0], arr[1], arr[2]);
       2 [arr] = 15;
       printf("0[arr] = %d, 1[arr] = %d, 2[arr] = %d\n",
              0 [arr], 1 [arr], 2 [arr]);
}

void trick3()
{
       char str1[] = {'A', 'B', 'C', 'D', 'E'}; // 5 bytes
       char str2[] = "ABCDE";                   // 6 bytes (5 chars + '\0')
       char *str3 = "ABCDE";                    // 4 bytes (pointer) or 8 bytes (64-bit)
       char *cPtr = str1;                       // 4 bytes (pointer) or 8 bytes (64-bit)

       short sArr[] = {1, 2, 3, 4, 5};                          // 10 bytes (5 shorts) (2 bytes each)
       short sArr2D[][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}}; // 20 bytes (2 rows, 5 shorts each) (2 bytes each)
       short *sPtr1 = sArr;                                     // 4 bytes (pointer) or 8 bytes (64-bit)
       short(*sPtr2)[5] = sArr2D;                               // 10 bytes (2 pointers) (4 bytes each) or 20 bytes (64-bit)
       short *sPtr3[5];                                         // 20 bytes (5 pointers) (4 bytes each) or 40 bytes (64-bit)

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

       printf("sArr2D[1][2] = %d\n", sArr2D[1][2]); // 8 bytes (2 bytes * 4)
       printf("sPtr2[0][0] = %d, sPtr2[1][2] = %d\n", sPtr2[0][0], sPtr2[1][2]);
       printf("*(* (sArr2D + 1) + 2) = %d\n", *(*(sArr2D + 1) + 2));
       printf("*(*(sArr2D) + 1*5 + 2) = %d\n\n", *(*(sArr2D) + 1 * 5 + 2));
}

int main()
{
       printf("Trick 1:\n\n");
       trick1();
       printf("\n");
       printf("Trick 2:\n\n");
       trick2();
       printf("\n");
       printf("Trick 3:\n\n");
       trick3();
       printf("\n");
}
