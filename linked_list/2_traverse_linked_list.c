/** 
 * Program to create and traverse a Linked List
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
} node;


node* createNode(int data);
node* createList(int nodeCount);
void traverseList(node* head);
void freeList(node* head);

int main()
{
    int totalNodes;
    node *head;

    printf("Enter the total number of nodes: ");
    scanf("%d", &totalNodes);

    head = createList(totalNodes);

    printf("\nData in the list \n");

    traverseList(head);

    freeList(head);

    return 0;
}

/**
 * Creates a new node with the given data and returns the pointer to the node
 */
node* createNode(int data)
{
    // allocate memory to new node
    node* newNode = (node*)malloc(sizeof(node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed");
        exit(1);
    }
    // initialize node data and pointer 
    newNode -> data = data;
    newNode -> next = NULL;

    return newNode;
}

/**
 *  Create a list of nodes. Returns the pointer to head node.
 */
node* createList(int nodeCount)
{
    int data;
    int counter;
    node *head = NULL;
    node *previous = NULL;
    node *newNode = NULL;

    if (nodeCount <= 0)
    {
        printf("No nodes to create");
        return head;
    }

    for(counter = 1; counter <=nodeCount; counter++)
    {
        printf("Input data at node %d" , counter);
        scanf("%d", &data);

        newNode = createNode(data);

        if(previous != NULL)
        {
            // link previous node with newNode
            previous->next = newNode;
        }

        previous = newNode;

        if(counter == 1)
        {
            head = newNode;
        }
    }
    return head;
}

/**
 * Traverses through entire linked list and prints data to console.
 */
void traverseList(node* head)
{
    // starting from head
    node *current = head; 

    while (current != NULL)
    {
        // print data of current node
        printf("%d -> ", current -> data);
        // move to next node
        current = current -> next;
    }
    printf("\n");
}

/**
 * Traverses from head till NULL, deletes all the allocated bytes.
 */ 
void freeList(node *head) 
{
    printf("Clearing memory");

    node* current;

    while (head != NULL)
    {
        current = head;

        head = head->next;

        free(current);
    }
}