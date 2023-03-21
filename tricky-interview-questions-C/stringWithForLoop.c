#include <stdio.h>

int main()

{
   char s[] ="main";
   int i;
   for(i =0; s[i]; i++)
   printf("\n%c%c%c%c", s[i], *(s+i), *(i+s), i[s]);
}

//output is mmmm,aaaa,iiii,nnnn
//s[i] is written also as *(s+i), *(i+s), i[s]
