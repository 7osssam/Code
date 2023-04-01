#include <stdio.h>
void Divide(float num1, float num2)
{
    float result;
    if(num2 !=0)
    {
        result = num1/num2;
        printf("%f",result);
    }
    else
    {
        printf("Error");
    }
}

int main()
{
  Divide(8, 9);
  
   

    return 0;
}
