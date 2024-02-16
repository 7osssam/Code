/*
    (2) Write a C Function that returns the data of the middle node in a linked list
    and in case the linked list contains only one node return the data inside this node.
*/
// ! solve with time complexity log(n)
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *nxPtr;

} node;

node *head = NULL;

int findMiddleNode(void)
{
    if (head == NULL)
    {
        // The linked list is empty
        return -1; // or any other value to indicate an error
    }
    node *FastPtr = head;
    node *SlowPtr = head;
    while (FastPtr != NULL && FastPtr->nxPtr != NULL) // the order of the conditions matters in this case
    {
        FastPtr = FastPtr->nxPtr->nxPtr;
        SlowPtr = SlowPtr->nxPtr;
    }

    return SlowPtr->data;
}

void DisplayList(void)
{
    node *ptr = head;

    while (ptr != NULL)
    {
        printf(" %d  ", ptr->data);
        ptr = ptr->nxPtr;
    }
}

void insertAtHead(int num)
{

    node *temp = (node *)malloc(sizeof(node));

    temp->data = num;
    temp->nxPtr = head;

    head = temp;
}

int main()
{
    insertAtHead(11);
    insertAtHead(13);
    DisplayList();
    printf("\n");
    printf("Middle node is %d", findMiddleNode());
}