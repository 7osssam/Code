#include <stdio.h>



int main()
{
    int i =5;
    printf("%d\n", i++ + ++i);
    

    return 0;
}

//this code prints 12 because we have preincrement and
//post increment and i becomes 6 and then it is substituted
//in both the values and then once the statement has been 
//executed the i value becomes 7

