/*
(5) Write a C function that returns the maximum data value inthe linked list.
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

int MaxOfLink(void)
{
    int max = head->data;
    node *ptr = head;
    while (ptr != NULL)
    {
        if (ptr->data > max)
        {
            max = ptr->data;
        }
        ptr = ptr->nxPtr;
    }
    return max;
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
    printf("\nelement : %d ", MaxOfLink());
    // printf("%d\n", SizeofList());
    //  SearchList(55);
}
