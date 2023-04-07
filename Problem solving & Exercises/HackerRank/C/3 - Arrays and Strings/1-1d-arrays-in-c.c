//? https://www.hackerrank.com/challenges/1d-arrays-in-c/problem
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int n, sum = 0;  // n is the number of elements in the array
    scanf("%d", &n); // taking input of n

    int *arr = (int *)malloc(n * sizeof(int)); // memory allocation for the array
    // int *arr = (int*)calloc (n , sizeof(int)); // contiguous memory allocation for the array
    for (int i = 0; i < n; i++) // loop for taking input of the array
    {
        scanf("%d", &arr[i]); // using array notation
                              // scanf( "%d" , arr+i); //using pointer notation

        // sum = sum + *(arr + i); // using pointer notation
        sum = sum + arr[i]; // using array notation
    }
    free(arr); // freeing the memory

    printf("%d", sum); // printing the sum
    return 0;
}
