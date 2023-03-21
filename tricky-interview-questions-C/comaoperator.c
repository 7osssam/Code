#include <stdio.h>

int main()
{
    int i =2;
    int j = i+ (1,2,3,4,5);
    printf("%d\n", j);
        return 0;
}
//the answer is 7, because when we use comma opearator, the final value
// in the brackets is finally assigned to j. So, j = 2+5 is 7.