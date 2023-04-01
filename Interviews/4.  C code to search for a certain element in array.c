#include <stdio.h>

void SearchElement(int *arr,int size,int num)
{
    int i,flag=0;
    for(i=0; i<size; i++)
    {
        if(num == arr[i])
        {
            flag=1;
            break;
           
        }
        else
        {
            flag=0;
            
        }
    }
    if(flag == 1)
    {
        printf("The index is of %d : %d",num,i);
    }
    else
    {
        printf("The number is not found");
    }
}
int main()
{
   
    int n,i,s;
    printf("Enter size of array: ");
    scanf("%d",&s);
    int arr[s];
    printf("Enter Array numbers: ");
    for(i=0; i<s; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Please Enter the number: ");
    scanf("%d",&n);
    SearchElement(arr,s,n);
    
    return 0;
}
