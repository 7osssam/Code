#include <stdio.h>



int main()
{
    int i= 1, k= 1,n;
    printf("enter a number\n");
    scanf("%d", &n);
    if(n == 1 || n == 0)
    k =1;
    else
    for(i = n; i > 0; i--)
        k = k *i;
      
    printf("%d\n", k);
    
        return 0;
}