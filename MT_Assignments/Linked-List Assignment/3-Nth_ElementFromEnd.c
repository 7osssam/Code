/*
(3) Write a C function that returns the data inside the 5th element from the end of linked list
and in case the linked list contains only one node return the data inside this node.
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

int Nth_ElementFromEnd(int num)
{
    if (head == NULL)
    {
        return -1;
    }
    node *FastPtr = head;
    node *SlowPtr = head;
    while (FastPtr != NULL)
    {
        FastPtr = FastPtr->nxPtr;
        if (num <= 0)
        {
            SlowPtr = SlowPtr->nxPtr;
        }
        num--;
    }
    return SlowPtr->data;

    //================================================================================================
    // ======================= Another solution (using only 1 pointer)================================
    //================================================================================================
    /*
    only for the 5th element from the end or any other element (not input from the user)

    node *ptr = head;
    while (ptr->nxPtr->nxPtr->nxPtr->nxPtr->nxPtr != NULL)
    {
        ptr = ptr->nxPtr;
    }

    return ptr->data;
    */
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
    printf("\nelement : %d ", Nth_ElementFromEnd(5));
    // printf("%d\n", SizeofList());
    //  SearchList(55);
}
