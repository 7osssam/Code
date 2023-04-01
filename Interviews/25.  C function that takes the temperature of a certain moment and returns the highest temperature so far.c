#include <stdio.h>
unsigned int MAX_TEMP(signed int temp)
{
    static signed int max;
   
     
        if(temp > max)
        {
            max = temp;
        }
        return max;
    
}
int main()
{
    int t1,t2,t3;
t1 = MAX_TEMP(15);
t2 = MAX_TEMP(10);
t3 = MAX_TEMP(5);
printf("%d %d %d",t1,t2,t3);
    return 0;
}
