#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// define the maximum capacity of the stack
#define MAX_SIZE  100

// define the structure of the stack
typedef struct {
    int arr[MAX_SIZE];
    int top;
}Stack;

// function to initialize the stack (default value -1)
void initialize(Stack *stack){
    stack -> top = -1;
}

// function to check if stack is empty
bool isEmpty(Stack *stack){
    return stack -> top == -1;
}

// function to check if stack is full
bool isFull(Stack *stack){
    return stack -> top >= MAX_SIZE -1;
}

// function to push an element into the stack
void push(Stack *stack , int value){
    if(isFull(stack)){
        printf("Stack Overflow\n");
        return;
    }
    stack -> arr[++stack -> top] = value;
    printf("Pushed %d into the stack\n" , value);
}

// funtion to pop an element from the stack
int pop(Stack *stack){
    if(isEmpty(stack)){
        printf("Stack is empty");
        return -1;
    }
    int popped = stack -> arr[stack -> top];
    stack -> top--;
    printf("Popped %d from the stack\n" , popped);
    return popped;
}

// function to peek the top element from the stack
int peek(Stack *stack){
    if(isEmpty(stack)){
        printf("Stack is empty");
        return -1;
    }
    return stack -> arr[stack -> top];   
}

int main(){
    Stack stack;
    initialize(&stack);

    push(&stack , 3);
    printf("Top element into the stack is %d\n" , peek(&stack));

    push(&stack , 5);
    printf("Top element into the stack is %d\n" , peek(&stack));

    push(&stack , 11);
    printf("Top element into the stack is %d\n" , peek(&stack));

    push(&stack , 222);
    printf("Top element into the stack is %d\n" , peek(&stack));


    while (!isEmpty(&stack))
    {
        printf("Top element into the stack is %d\n" , peek(&stack));
        printf("Popped element from the stack is %d\n" , pop(&stack));
        printf("---stack is now empty---");
    }
}