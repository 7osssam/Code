#include <stdio.h>

struct emp{
    int data;
    char name[20];
    float salary;
};

typedef struct emp EMPREC;  


int main()
{
    
    EMPREC to_change(EMPREC);
    EMPREC emp1;
    
    printf("enter the details\n");
    scanf("%d %s %f", &emp1.data, &emp1.name, &emp1.salary);
    printf("before the function call\n");
    printf("%d %s %f", emp1.data, emp1.name, emp1.salary);
    
    emp1 = to_change(emp1);
    printf("\nafter the function call\n");
    printf("%d %s %f", emp1.data, emp1.name, emp1.salary);
    printf("after\n");
    
  printf("%d %s %f", emp1.data, emp1.name, emp1.salary);
    return 0;
}

EMPREC to_change(EMPREC nowkara)
{
    nowkara.data = 2222;
    strcpy(nowkara.name,"chandru");
    nowkara.salary = 50,000;
    return nowkara;
}
