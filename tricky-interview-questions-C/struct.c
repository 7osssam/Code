#include <stdio.h>

struct student_rec{
    int m1;
    int m2;
    char name[20];
    float avg;
    int roll;
};



int main()
{
   
    struct student_rec student[4];
    printf("struct size of point is %d\n", sizeof(struct student_rec));
    printf("struct size of date is %d\n", sizeof(student));
    int i, total;
    printf("enter the information\n");
    for(i = 1; i <= 3; i++)
    {
        printf("enter the %d student details\n", i);
        printf("enter the %d student m1 marks\n");
        scanf("%d",&student[i].m1);
         printf("enter the %d student m2 marks\n",i);
        scanf("%d",&student[i].m2);
         printf("enter the %d student name \n",i);
        scanf("%s",student[i].name);
         printf("enter the %d student roll \n",i);
        scanf("%d",&student[i].roll);
        
    }
    
    for(i = 1; i <= 3; i++)
    {
        total = student[i].m1+student[i].m2;
        student[i].avg = total/2.0;
        printf("the %d student m1 marks\t",i);
        printf("%d\n",student[i].m1);
         printf("the %d student m2 marks\t",i);
        printf("%d\n",student[i].m2);
         printf("the %d student  name \t",i);
        printf("%s\n",student[i].name);
         printf("the %d student roll\t",i);
        printf("%d\n",student[i].roll);
        printf("the %d student average is\n", i);
        printf("%5.2f\n", student[i].avg);
        
    }

    return 0;
}

//this is the array of structures and we could have so many heterogeneous elements
//in an array.