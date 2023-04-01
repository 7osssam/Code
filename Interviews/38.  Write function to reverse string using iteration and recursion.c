#include <stdio.h>
void ReverseString(char *arr)
{

   if(*arr != '\0')
   {
        ReverseString(arr+1);
        printf("%c",*arr);
       
   
    
    }
    
 


}
int main()
{
  
  char arr[] = "Nadine Ashraf";
ReverseString(arr);

    return 0;
}
