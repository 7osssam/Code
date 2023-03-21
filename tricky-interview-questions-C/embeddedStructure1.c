#include <stdio.h>


struct date{
  int dob;
};


struct point{
    int x;
    int y;
    struct date birth_of_date;
};



int main()
{
   
    struct point po; 
    struct date da;
    printf("struct size of point is %d\n", sizeof(struct point));
    printf("struct size of date is %d\n", sizeof(struct date));
    po.x =3;
    po.y =4;
    da.dob = 2017;
    printf("the elements in structure point is \n");
    printf("x is %d\n", po.x);
    printf("y is %d\n", po.y);
    printf("the elements in structure date is \n");
    printf("dob is %d\n", da.dob);
    return 0;
}

//this is embedded structure, and can be defined in the first way