/** 
 * Program to create and traverse a Linked List
 */

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

// Insert at the beginning
// head_ref is the address of the head pointer
// *head_ref is the pointer to the current head node
void insertAtBeginning(struct Node** head_ref , int new_data){

    struct Node* new_node = malloc(sizeof(struct Node));
    new_node -> data = new_data;
    new_node -> next = (*head_ref);
    (*head_ref) = new_node;
}

// Insert a node after node
void insertAfter(struct Node* previous_node , int new_data){
    if(previous_node == NULL){
        printf("the given previous node can not be NULL");
        return;
    }

    struct Node* new_node = malloc(sizeof(struct Node*));
    new_node -> data = new_data;
    new_node -> next = previous_node -> next;
    previous_node -> next = new_node;
}

// Insert at the end
// *head_ref is the actual head pointer
void insertEnd(struct Node** head_ref , int new_data){
    struct Node* new_node = malloc(sizeof(struct Node*));
    struct Node* last = *head_ref;

    new_node -> data = new_data;
    new_node -> next = NULL;

    if(*head_ref == NULL){
        *head_ref = new_node;
        return;
    }

    while (last -> next != NULL) // As long as there is another node after this one, keep moving forward
        last = last -> next ; // move the pointer forward
    last -> next = new_node; // link a new node after current
    return;   
}

// Delete a node
void deleteNode(struct Node** head_ref , int key){
    struct Node *current  = *head_ref , *previous;

    //If the first node is the one to delete
    if(current != NULL && current -> data == key){
        *head_ref = current -> next;
        free(current);
        return;
    }

    //find the key to be deleted
    while (current != NULL && current -> data != key)
    {
        previous = current;
        current = current -> next;
    }

    if(current == NULL) return;

    previous -> next = current -> next;
    free(current); 
}

// Search a node
int searchNode(struct Node** head_ref , int key){
    struct Node* current = *head_ref;
    
    while (current != NULL)
    {
        if(current -> data == key) return 1;
        current = current -> next;
    }
    return 0;
}

// Sort the linked list
void sortLinkedList(struct Node** head_ref) {
    struct Node *current = *head_ref, *index = NULL;
    int temp;

    if (head_ref == NULL) {
    return;
    } 
    else
    {
    while (current != NULL) {
        // index points to the node next to current
        index = current->next;

        while (index != NULL) {
        if (current->data > index->data) {
        temp = current->data;
        current->data = index->data;
        index->data = temp;
        }
        index = index->next;
        }
        current = current->next;
        }
    }
}

// print linked list
void printList(struct Node* node){
    while(node != NULL){
        printf(" %d " , node -> data);
        node = node -> next;
    }
}

int main(){
    struct Node* head = NULL;

    insertEnd(&head , 1);
    insertAtBeginning(&head , 2);
    insertAtBeginning(&head , 3);
    insertEnd(&head , 4);
    printList(head);

    printf("\nAfter deleting an element: ");
    deleteNode(&head, 4);
    printList(head);


    int item_to_find = 3;
    if (searchNode(&head, item_to_find)) {
    printf("\n%d is found", item_to_find);
    } else {
    printf("\n%d is not found", item_to_find);
    }

    sortLinkedList(&head);
    printf("\nSorted List: ");
    printList(head);
}