#include <stdio.h>

union number
{
    int data;
    char ch;
    float avg;
};

union number x;

int main()
{
    
    x.data = 5;
    x.avg = 250.00;
    printf("size of union is %d\n", sizeof(x));
    printf("size of union is %d\n", sizeof(union number));


    return 0;
}

//the sixe of the union can be determined using both the steps
//here the answer would be 4 bytes depending on the compiler type