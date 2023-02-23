#include <stdio.h>
#include <stdlib.h>
#include "stdtypes.h"

typedef struct node
{
    u32 data;
    struct node *nx;
}node;

node *head = NULL;

void add_first (u32 value)
{
    node *temp = (node*) malloc(sizeof(node));
    temp->data = value;
    temp->nx = head;
    head = temp;
}

void print(void)
{
    if (head == NULL)
    {
        printf("list is empty \n");
    }
     else
    {
        node *current = head;
        while (current !=NULL)
        {
            printf("%d\n", current->data);
            current = current->nx ;
        }
        printf("NULL\n");

    }
}

void delete_first(void)
{
    node *temp = head;
    head = head->nx;
    free(temp);
}

void delete_last(void)
{
    node *current = head;
    node *previous=head;
        while (current->nx !=NULL)
        {
            previous=current;
            current = current->nx ;
        }
    previous->nx=NULL;
    free(current);
}

void sizeoflist(node *list)
{
    u8 count=0;
    node *current = head;
    while (current !=NULL)
    {
        current = current->nx ;
        count++;
    }
    printf("size of list is %d\n", count);
}

void search(u32 value)
{
    node *current = head;
    while (current !=NULL)
    {
        if (current->data == value)
        {
            printf("value found \n");
            break;
        }
        else
        {
            current = current->nx ;
        }
    }
}

void add_last(u32 value)
{
    //create new node
    node *temp = (node*) malloc(sizeof(node));
    temp->data = value;
    temp->nx = NULL;
    //find last node
    node *current = head;
    while (current->nx !=NULL)
    {
        current = current->nx ;
    }
    current->nx = temp;
}
void ChangeTxtToRED (void)
{
    printf("\033[0;31m");
}
int main()
{
    add_first(10);
    add_first(20);
    add_first(30);
    add_first(40);
    add_last(50);
    add_last(80);
    print();
    //sizeoflist(head);
    delete_first();
    print();
    //sizeoflist(head);
    //printf("Size of Node struct: %lu bytes\n", sizeof(node));
    search(20);
    delete_last();
    ChangeTxtToRED();
    print();
    return 0;
}
