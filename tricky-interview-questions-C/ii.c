#include<stdio.h>

void main()
{

int i = 1;

while(++i <= 5)
{
printf(" first value is %d\n", i);
printf(" second value is %d\n", ++i);
printf(" third value is %d\n", i);
}

}