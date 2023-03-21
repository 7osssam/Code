#include <stdio.h>
#include <string.h>

struct employee{
  int data;
  char name[20];
  float salary;
};

int main()
{
    struct employee emp = {1,"chandru", 50,000};
  
    printf("the size of struct is %d\n", sizeof(emp));
    printf("the size is %d\n", sizeof(struct employee));
    to_print();
    to_check();
    to_print();
    return 0;
}

void to_print(struct employee pr)
{
       printf("employee id %d\n",pr.data);
    printf("employee name %s\n", pr.name);
    printf("employee salary %2f\n", pr.salary);
}
void to_check(struct employee nowkara)
{
    printf("the struct in this function is\n");
     nowkara.data = 2;
     strcpy(nowkara.name , "bindu");
     nowkara.salary = 49,000;

    printf("employee id %d\n",nowkara.data);
    printf("employee name %s\n", nowkara.name);
    printf("employee salary %2f\n", nowkara.salary);
    
}