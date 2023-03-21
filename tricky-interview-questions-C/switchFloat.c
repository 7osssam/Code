#include <stdio.h>



int main()
{
    float a;
    a =2;
    switch(a)
    {
     
     
        case 1: printf("hai\n");
        break;
        case 2: printf("hello\n");
        break;
           default: printf("jai hind\n");
    }
    

    return 0;
}

//this code causes a compile time error, because only int or character
//values are allowed in the Switch statement.
