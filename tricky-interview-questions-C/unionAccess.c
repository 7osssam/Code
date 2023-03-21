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
   
    printf("data is %d, avg is %6.2f\n", x.data, x.avg);
     x.avg = 250.00;
    printf("data is %d, avg is %6.2f\n", x.data,x.avg);


    return 0;
}

//output is 5, 0.00
//output is 113206, 250.00
//it indicates that only one value can be given
//at any one time.