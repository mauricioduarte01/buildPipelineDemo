#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *next;
    int data;

} Node;

void printList(Node *n)
{
	while(n!=NULL) {
	printf("Node: %d\n", n->data);
	n=n->next;
	}
}


void push(Node **head_ref, int new_data)
{
	// allocate a node
	Node *new_node = malloc(sizeof(Node));
	// put in the data
	new_node->data = new_data;
	// make next of new node as head
	new_node->next = (*head_ref);
	// move the head to point to the new node
	(*head_ref) = new_node;
}

void insertAfter(Node *prev_node, int new_data)
{
	if (prev_node == NULL) {
	    printf("previous node can't be NULL");
	    return;
	}
	Node *new_node = malloc(sizeof(Node));
	
	new_node->data = new_data;
	new_node->next = prev_node->next;
	prev_node->next = new_node;
}

void insertEnd(Node *head_ref, int new_data)
{
	// prepare a node
	Node *new_node = malloc(sizeof(Node));
	new_node->data = new_data;
	new_node->next = NULL;
	// if linkedlist is empty, new_node will be head
	if(head_ref == NULL) {
	    head_ref = new_node;
	    return;
	}
	// find the last node
	Node *last = head_ref;
	while(last->next!=NULL) {
	    last=last->next;
	}
	// insert a new_node aftert last node (at the end)
	last->next=new_node;
}

int main(void)
{
	Node *head = NULL;
	Node *second = NULL;
	Node *third = NULL;

	head = malloc(sizeof(Node));
	second = malloc(sizeof(Node));
	third = malloc(sizeof(Node));

	head->data = 1;
	head->next = second;
	
	second->data = 2;
	second->next = third;

	third->data = 300;
	third->next = NULL;

	printList(head);

	Node *first = NULL;
	
	push(&head, 888);

	printList(head);

	insertAfter(second, 777);
	printList(head);

	insertEnd(head, 89824811);
	printList(head);
}	