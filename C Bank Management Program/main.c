#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n ; //n is the number of elements in the array
    int arr[1000]; //array of size 1000
    scanf("%d" , &n); //taking input of the number of elements in the array
    for(int i = 0; i < n;i++) //loop for taking input of the array
    {
     scanf( "%d" , &arr[i]); // using array notation
     //scanf( "%d" , arr+i); //using pointer notation //
    }

    //of the following are equivalent ways of accessing the array elements
    //*(arr + i); scanf("%d", arr + i);   | printf("%d", *(arr + i));
    // *(i + arr); scanf("%d", i + arr);  | printf("%d", *(i + arr));
    // arr[i]; scanf("%d", arr[i]);       | printf("%d", arr[i]);
    // i[arr]; scanf("%d", i[arr]);       | printf("%d", i[arr]);

    // print the array
    for(int i = 0; i < n;i++) //loop for printing the array
    {
     printf( "%d " , *(arr+i) ); // using array notation
    }
    return 0;
}