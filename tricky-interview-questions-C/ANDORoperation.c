#include <stdio.h>

int main()
{
    int i = -1, j = -1, k =0, l =2,m;
    m = i++ && j++ && k++ || l++;
    printf("m value is %d\n", m);

    return 0;
}

//output is 1, all the values get substituted to their 
//respective places and since all are post increment, it
//cannot have any effect on the output.
//T && T && F || T
// T && F || T
// F || T
//T  true value is deduced as 1 in C language.