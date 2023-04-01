#include <stdio.h>
void CircularShift(int num, int shift)
{
     int *ptr = &num;
    if(shift> 8)
    {
        *ptr = num;
    }
    *ptr = (num>>shift) |(num<<(8-shift));
    printf("Number = %d ",*ptr);
}
int main()
{
    int n,ss;
    printf("Please enter the number: ");
    scanf("%d",&n);
    printf("Enter number of shifts: ");
    scanf("%d",&ss);
     CircularShift(n,ss);
    return 0;
}
