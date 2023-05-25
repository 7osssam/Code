#include <stdlib.h>
#include <stdio.h>
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *insert(Node *head, int data)
{

    Node *current;
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        current = head;
        while (current->next)
            current = current->next;
        current->next = temp;
    }
    return head;
}

void display(Node *head)
{
    Node *start = head;
    while (start)
    {
        printf("%d ", start->data);
        start = start->next;
    }
}
int main()
{
    int T, data;
    scanf("%d", &T);
    Node *head = NULL;
    while (T-- > 0)
    {
        scanf("%d", &data);
        head = insert(head, data);
    }
    display(head);
}
