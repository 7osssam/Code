#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *nxPtr;

} node;

node *head = NULL;

void insertAtHead(int num)
{
    //! common mistake.. we are here creating a (pointer) to a node
    node *temp = (node *)malloc(sizeof(node));

    temp->data = num;
    temp->nxPtr = head;
    /*
     temp->nxPtr = NULL; is only right for the first node
     but in every other insertion we need the temp->nxPtr to point to the head (which is the previous node)
    */
    head = temp;
}

void insertAtEnd(int num)
{
    node *temp = (node *)malloc(sizeof(node));

    temp->data = num;
    temp->nxPtr = NULL;

    if (head == NULL)
    {

        head = temp;
        return;
    }

    node *current = head;

    while (current->nxPtr != NULL)
    {
        current = current->nxPtr;
    }
    current->nxPtr = temp;
}

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
}

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

int SizeofList(void)
{
    int counter = 0;
    node *ptr = head;
    if (head == NULL)
    {
        return counter;
    }
    else
    {
        while (ptr != NULL)
        {
            counter++;
            ptr = ptr->nxPtr;
        }
    }
    return counter;
}

void SearchList(int num)
{
    int postion = 0;
    node *ptr = head;

    if (head == NULL)
    {
        printf("Linked List is empty");
        return;
    }
    // with all the functions that only check for a data NOT creates one, we use temp != NULL....
    // using temp->nxPtr != NULL will cause a segmentation fault even if we are not assigning any data to it
    while (ptr != NULL)
    {
        if (ptr->data == num)
        {
            printf("Num is found at postion %d", postion);
            return;
        }

        postion++;
        ptr = ptr->nxPtr;
    }

    printf("Not Found");
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

int MaxOfList(void)
{
    if (head == NULL)
    {
        printf("Linked List is empty");
        return -1;
    }
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
    insertAtHead(24);
    DisplayList();

    insertAtPosition(100, 3);
    DisplayList();
    // printf("%d\n", SizeofList());
    //  SearchList(55);
}