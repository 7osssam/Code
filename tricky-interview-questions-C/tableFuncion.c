#include <stdio.h>

void table(int n)
{
    int i, k;
    for(i = 0;i <=10; i++)
    {
        k = n * i;
        printf("%d = %d * %d\t", n,i,k); 
        printf("\n");
    }
    
}

int main()
{
    int n;
    printf("enter the number table\n");
    scanf("%d", &n);
     table(n);

    return 0;
}

