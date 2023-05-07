/*
(4)Write a C function that returns the sum of all the nodes in linked list.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *nxPtr;

} node;

node *head = NULL;

void DisplayList(void)
{
    node *ptr = head;
    printf("[head] =>");

    while (ptr != NULL)
    {
        printf(" %d =>", ptr->data);
        ptr = ptr->nxPtr;
    }

    printf(" [null]\n");
}

void insertAtHead(int num)
{

    node *temp = (node *)malloc(sizeof(node));

    temp->data = num;
    temp->nxPtr = head;

    head = temp;
}

int SumOfList(void)
{
    int sum = 0;
    node *ptr = head;
    while (ptr != NULL)
    {
        sum += ptr->data;
        ptr = ptr->nxPtr;
    }
    return sum;
}

int main()
{
    insertAtHead(1);
    insertAtHead(3);
    insertAtHead(15);
    insertAtHead(8);
    insertAtHead(66);
    insertAtHead(36);
    insertAtHead(56);
    insertAtHead(43);
    insertAtHead(65);
    insertAtHead(24);
    DisplayList();
    printf("\nelement : %d ", SumOfList());
    // printf("%d\n", SizeofList());
    //  SearchList(55);
}
