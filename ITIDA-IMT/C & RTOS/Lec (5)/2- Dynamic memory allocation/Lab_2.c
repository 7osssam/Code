#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
	int			 data;
	struct Node* next;
} Node;

/**
 * Adds a new node to the end of a linked list.
 *
 * @param head_ref Pointer to the head of the linked list.
 * @param new_data The data to be added to the new node.
 */
void LinkedList_AddNodeToEnd(Node** head_ref, int new_data)
{
	// Allocate memory for the new node
	Node* new_node = (Node*)malloc(sizeof(Node));

	// Assign data to the new node
	new_node->data = new_data;
	// As this new node will be the last node, make next of it as NULL
	new_node->next = NULL;

	// If the linked list is empty, then make the new node as head
	if (*head_ref == NULL)
	{
		*head_ref = new_node;
		return;
	}

	Node* current = *head_ref;

	// Otherwise, traverse till the current node
	while (current->next != NULL)
	{
		current = current->next;
	}
	// Change the next of the current node
	current->next = new_node;
	return;
}

/**
 * Prints the linked list.
 *
 * @param node The head of the linked list.
 */
void LinkedList_print(Node* node)
{
	if (node == NULL)
	{
		printf("==============\n");
		printf("list is Empty\n");
		printf("==============\n");
		return;
	}
	printf("==============\n");
	int counter = 1;
	while (node != NULL)
	{
		printf("Node Number %d : %d\n", counter, node->data);
		node = node->next;

		counter++;
	}
	printf("==============\n");
}

int main()
{
	Node* head = NULL;
	int	  choice, data;
	bool  isExit = false;

	while (isExit == false)
	{
		printf("===========================\n");
		printf("To add node enter               (0)\n");
		printf("To print the linked list enter  (1)\n");
		printf("To exit press                   (2)\n");
		printf("===========================\n");
		printf("Your Choice: ");
		scanf("%d", &choice);
		printf("===========================\n");

		switch (choice)
		{
			case 0:
				printf("Please Enter Node Value: ");
				scanf("%d", &data);
				LinkedList_AddNodeToEnd(&head, data);
				printf("Node Added. Thank You.\n");
				break;
			case 1:
				LinkedList_print(head);
				break;
			case 2:
				printf("Exiting...\n");
				isExit = true;
				//exit(0);  // or can also use exit(0) to exit the program
				break;
			default:
				printf("===========================");
				printf("\nInvalid Choice. Please try again.\n");
				printf("===========================\n");
		}
	}

	return 0;
}
