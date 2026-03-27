#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// a structure to represent a stack
struct Stack {
    int top; //most recent item
    unsigned capacity; // stack's max size
    int* arr; // a pointer to an integer - used to store the elements
} ;


// function to create a stack of given capacity
struct Stack* createStack(unsigned capacity){
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    if(!stack){
        return NULL;
    }
    stack -> capacity = capacity;
    stack -> top = -1;

    stack -> arr = malloc(stack -> capacity * sizeof(int));
    
    if(!stack -> arr){
        free(stack);
        return NULL;
    }
    return stack;
}

int isFull(struct Stack* stack){
    return stack -> top == stack -> capacity - 1;
}

int isEmpty(struct Stack* stack){
    return stack -> top == -1;
}

void push(struct Stack* stack , int value){
    if(isFull(stack)){
        printf("Stack Overflow\n");
        return;
    }
    stack -> arr[++stack -> top] = value;
    printf("%d pushed to stack\n" , value);
}

int pop(struct Stack* stack){
    if(isEmpty(stack)){
        printf("Stack is empty\n");
        return INT_MIN;
    }
    return stack -> arr[stack -> top--] ;
}

int peek(struct Stack* stack){
    if(isEmpty(stack)){
        printf("Stack is empty\n");
        return INT_MIN;
    }
    return stack -> arr[stack -> top];
}

void freeStack(struct Stack* stack){
    if(stack) {
        free(stack -> arr);
        free(stack);
    }
}

int main(){
    // stack --> pointer
    struct Stack* stack = createStack(5);
    if(!stack){
        printf("Failed to create stack");
        return -1;
    }

    push(stack , 10);
    push(stack , 20);
    push(stack , 30);

     printf("\nTop element is %d\n", peek(stack));

    printf("%d popped from stack\n", pop(stack));
    printf("After popping, top element is %d\n\n", peek(stack));

    push(stack, 40);
    push(stack, 50);
    push(stack, 60); 
    
    push(stack, 70); // This will cause a stack overflow

    printf("\nPopping all elements:\n");
    while(!isEmpty(stack)) {
        printf("%d popped from stack\n", pop(stack));
    }

    pop(stack); // This will cause a stack underflow

    freeStack(stack);

    return 0;
    
}