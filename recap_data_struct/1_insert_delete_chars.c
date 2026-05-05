// insert and delete nodes from a list

#include <stdio.h>
#include <stdlib.h>


struct listNode {
    char data;                  // each listnode has a char
    struct listNode *nextPtr;   // pointer to next node
};

typedef struct listNode ListNode; // ListNode is an alias of struct listNode 
typedef ListNode *ListNodePtr; // alias for ListNode*


void insert(ListNodePtr *sPtr , char value);
char delete(ListNodePtr *sPtr , char value);
int isEmpty(ListNodePtr *sPtr);
void printList(ListNodePtr currentPtr);
void instructions(void);




void insert(ListNodePtr *sPtr , char value) // *sPtr is the head Pointer
{
    ListNodePtr newPtr = malloc(sizeof(ListNode)); // create new node

    if(newPtr != NULL) // if memory allocated to newPtr
    {
        newPtr->data = value;
        newPtr->nextPtr = NULL;

        ListNodePtr previousPtr = NULL;
        ListNodePtr currentPtr = *sPtr;
        
        // find the correct position in List
        while(currentPtr != NULL && value > currentPtr -> data ){
            previousPtr = currentPtr;       
            currentPtr = currentPtr ->nextPtr;
        }

        // insert new node at the beginning of list
        if(previousPtr == NULL)
        {
            newPtr -> nextPtr = *sPtr;
            *sPtr = newPtr;
        }
        else
        {   // insert new node between previousPtr and currentPtr
            previousPtr -> nextPtr = newPtr;
            newPtr -> nextPtr = currentPtr;
        }
    }
    else
    {
        print("%c not inserted, no memory available.\n" , value);
    }
}

char delete(ListNodePtr *sPtr , char value)
{
    if(value == (*sPtr ) -> data){
        ListNodePtr tempPtr = *sPtr; // tempPtr is used to free the memory after
        *sPtr = (*sPtr) -> nextPtr;  // nextPtr is now the *sPtr
        free(tempPtr);
        return value;

    }
    else
    {
        ListNodePtr previousPtr = *sPtr;
        ListNodePtr currentPtr = (*sPtr) -> nextPtr;

        while(currentPtr != NULL && currentPtr -> data != value){
            previousPtr = currentPtr;
            currentPtr = currentPtr -> nextPtr;
        }

        if(currentPtr != NULL){
            ListNodePtr tempPtr = currentPtr;
            previousPtr -> nextPtr = currentPtr -> nextPtr;
            free(tempPtr);
            return value;
        }
    }
    return '\0';
}