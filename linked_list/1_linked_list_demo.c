#include <stdio.h>
#include <stdlib.h>

/*
A linked list is a linear data structure made of nodes connected using pointers. 
Each node has: Data: The value stored in the node. Pointer: A reference to the next node.
Nodes are not stored in contiguous memory like arrays; they can be anywhere in memory.
To access a node, we start from the head and traverse sequentially through the list
*/

/*Define the Node structure */
struct Node
{
    int data; // actual value
    struct Node *next;  // address of the next node
};



int main()
{
    // create Nodes
    struct Node *head = NULL;   // will point to the first Node, but no point to nothing
    struct Node *second = NULL;
    struct Node *third = NULL;


    // allocate memory
    head = (struct Node *)malloc(sizeof(struct Node)); // points to a real node in memory
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof (struct Node));

    // check allocation
    if(!head || !second || !third){
        printf("Memory allocation failed\n");
        return 1;
    }

    // Assign data and link nodes
    head -> data = 10;
    head -> next = second;

    second -> data = 20;
    second -> next = third;

    third -> data = 30;
    third -> next = NULL;

    //print linked list
    struct Node *tmp = head;
    while (tmp != NULL)
    {
        printf("%d -> " , tmp -> data);
        tmp = tmp -> next;
    }
    printf("NULL\n");

    //free allocated memory
    tmp = head;
    while (tmp != NULL)
    {
        struct Node *next = tmp -> next;
        free(tmp);
        tmp = next;
    }
    return 0;
}