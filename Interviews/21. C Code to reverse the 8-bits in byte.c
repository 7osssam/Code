#include <stdio.h>

int main()
{
    unsigned int num,new=0;
    int i=0;
    scanf("%d",&num);
    for(i=0; i<sizeof(char)*8; i++)
    {
         
        if((num >> i) & 1)
        {
           
            new |= (num | (1<<(7-i)));
            
            
            
           
        }
       
    }
  printf("%d",new-num);
    return 0;
}
