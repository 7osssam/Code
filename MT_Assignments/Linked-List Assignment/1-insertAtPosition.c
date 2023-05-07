/*
(1) Write a C function that insert linked list node at any position.
The function takes the data of the node and the node position as inputs.
For example if we have a linked list contains the following data nodes: 11 3 10 50 23 5 60
If you asked the function to insert a new node hasdata equals to 15 at position 3
the linked list should be: 11 3 10 15 50 23 5 60
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *nxPtr;

} node;

node *head = NULL;

void insertAtPosition(int num, int position)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = num;
    temp->nxPtr = NULL;

    if (head == NULL && position == 0)
    { // Case 1: Inserting at the beginning of an empty list
        head = temp;
        return;
    }

    if (head == NULL && position != 0)
    { // Case 2: Inserting at any position in an empty list
        printf("List is empty. Cannot insert at position %d.\n", position);
        return;
    }

    if (position == 0)
    { // Case 3: Inserting at the beginning of a non-empty list
        temp->nxPtr = head;
        head = temp;
        return;
    }

    int i;
    node *current = head;
    node *previous = head;
    for (i = 0; i < position && current != NULL; i++)
    {
        previous = current;
        current = current->nxPtr;
    }

    if (current == NULL && position > i)
    { // Case 4: Inserting at a position beyond the end of the list
        printf("List has only %d elements. Cannot insert at position %d.\n", i, position);
        return;
    }

    previous->nxPtr = temp;
    temp->nxPtr = current;
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
    insertAtHead(60);
    insertAtHead(5);
    insertAtHead(23);
    insertAtHead(50);
    insertAtHead(10);
    insertAtHead(3);
    insertAtHead(11);
    DisplayList();
    insertAtPosition(15, 1);
    printf("\n");
    DisplayList();
}