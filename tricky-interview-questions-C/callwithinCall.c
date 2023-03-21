#include <stdio.h>

int main()
{
    call();
    
    void call()
    {
    printf("Hello, World!\n");
    }
    return 0;
}

//output is error, because previous implicit 
//decleration of call was here