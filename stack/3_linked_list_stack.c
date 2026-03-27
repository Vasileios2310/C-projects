#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct StackNode{
    int data;
    struct StackNode* next;
};

struct StackNode* newNode(int data){
    struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    if(!stackNode){
        printf("Heap overflow\n");
        return NULL;
    }

    stackNode -> data = data;
    stackNode -> next = NULL;
    return stackNode;
}

int isEmpty(struct StackNode* top){
    return !top;
}

void push(struct StackNode** top_ref , int data){
    struct StackNode* stackNode = newNode(data);
    if(!newNode) return;

    stackNode -> next = *top_ref;
    *top_ref = stackNode;
    printf("%d pushed to stack\n" , data);
}

int pop(struct StackNode** top_ref){
    if(isEmpty(*top_ref)){
        printf("Stack underflow\n");
        return INT_MIN;
    }

    struct StackNode* temp = *top_ref;
    int popped = temp -> data;
    *top_ref = (*top_ref) -> next;

    free(temp);

    return popped;
}

int peek(struct StackNode* top) {
    if (isEmpty(top)) {
        printf("Stack is empty\n");
        return INT_MIN; 
    }
    return top->data;
}

int main() {
    struct StackNode* top = NULL;

    push(&top, 10);
    push(&top, 20);
    push(&top, 30);

    printf("\nTop element is %d\n", peek(top));

    printf("%d popped from stack\n", pop(&top));

    printf("Top element is now %d\n", peek(top));
    
    printf("\nPopping all elements...\n");
    while(!isEmpty(top)) {
        printf("%d popped from stack\n", pop(&top));
    }

    pop(&top);

    return 0;
}