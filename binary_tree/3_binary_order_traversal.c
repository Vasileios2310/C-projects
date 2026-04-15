#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct TreeNode
{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* createNode(int value){
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));

    if(newNode != NULL){
        newNode -> data = value;
        newNode -> left = NULL;
        newNode -> right = NULL;
    }
    return newNode;
}

// Function to insert a node into the binary tree
struct TreeNode* insertNode(struct TreeNode* root , int value) {
    if (root == NULL){
        return createNode(value);
    }
    if (value < root -> data){
        root -> left = insertNode(root -> left , value);
    }else if (value > root -> data){
        root -> right = insertNode(root -> right , value);
    }
    return root;
}

// Function to perform in-order traversal and print elements in sorted order
void inOrderTraversal(struct TreeNode* root){
    if(root != NULL){
        inOrderTraversal(root -> left);
        printf("%d " , root -> data);
        inOrderTraversal(root -> right);
    }
}

// Function to free the memory allocated for the binary tree
void freeTree(struct TreeNode* root){
    if(root != NULL){
        freeTree(root -> left);
        freeTree(root -> right);
        free(root);
    }
}

int main(){
    struct TreeNode* root = NULL;
    int nodeValue;
    //int choice;
    
    do{
        printf("Input a value to insert into the binary tree( enter 0 to stop)");
        scanf("%d" , &nodeValue);

        if(nodeValue != 0){
            root = insertNode(root, nodeValue);
        }
    } while (nodeValue != 0);

    printf("\nIn-order Traversal (Sorted Order) of the Binary Tree: ");
    inOrderTraversal(root);
    printf("\n");

    // Free allocated memory
    freeTree(root);

    return 0;
}