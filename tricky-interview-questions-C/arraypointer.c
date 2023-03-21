#include <stdio.h>

int main()
{
    int a[3] = {1,2,3};
    int b [3];
    b = a;
    printf(" a values are %d, %d, %d", a[0], a[1],a[2]);
    printf(" b values are %d, %d, %d", b[0], b[1],b[2]);
}


//output is compile time error,
//because array is constant time 
//pointer and cannot be changed 
//throughout the program
