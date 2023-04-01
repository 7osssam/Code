#include <stdio.h>
#include <string.h>

void CheckString(char *s)
{
    int i,flag=0;
    while(s[i] != '\0')
    {
        if(s[i] == s[strlen(s)-1-i])
        {
           flag = 1; 
        }
        else
        {
            flag = 0;
        }
        i++;
    }
    if(flag == 1)
    {
        printf("String is mirror");
    }
    else
    {
        printf("String is not mirror");
    }
}
int main()
{
   char ss[100];
   printf("Please enter the string: ");
   scanf("%s",&ss);
   CheckString(ss);
    return 0;
}
