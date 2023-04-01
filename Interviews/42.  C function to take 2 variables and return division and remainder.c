
#include <stdio.h>
void Division(int x, int y)
{
   float division,rem;
   if(y != 0)
   {
       division =(float) x/y;
       rem =  x%y;
       printf("Division = %.2f\nRemindar= %.2f",division,rem);
   }
   else
   {
       printf("Error");
   }
    
}
int main()
{
    int n1,n2;
    printf("Please enter first number: ");
    scanf("%d",&n1);
    printf("Please enter second number: ");
    scanf("%d",&n2);
    Division(n1,n2);
   
    
    return 0;
}
