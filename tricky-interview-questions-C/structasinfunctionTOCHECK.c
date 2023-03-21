#include <stdio.h>
#include <string.h>

struct student_rec{
    int data;
    char name[20];
    int semester;
};


    typedef struct student_rec STUDENT;//now the STUDENT variable is also of type struct
  
  void to_change(STUDENT st)
{
     st.data = 4;
    strcpy(st.name ,"bindhu");
    st.semester = 4;
    printf("the details of the structure in the function are\n");
    printf("data is %d\n", st.data);
    printf("name is %s\n", st.name);
    printf("semester is %d\n", st.semester);
}  

int main()
{
    void to_check(STUDENT);
    STUDENT s;//s is also struct type of variable
    s.data = 1;
    strcpy(s.name , "chandru");
    s.semester = 1;
    printf("before the function call\n");
    printf("the details in the structure are\n");
    printf("data is %d\n", s.data);
    printf("name is %s\n", s.name);
    printf("semester is %d\n", s.semester);
    printf("---------------------------\n");
    to_change(s);//to change the values
     printf("after the function call\n");
       printf("---------------------------\n");
    printf("the details in the structure are\n");
    printf("data is %d\n", s.data);
    printf("name is %s\n", s.name);
    printf("semester is %d\n", s.semester);
    
   
    return 0;
}
//this is more or less like the call by value
//and the values will not change since there is no return type.
