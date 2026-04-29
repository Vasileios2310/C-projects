/*Binary Tree is a non-linear and hierarchical data structure where each node has at most two children referred to as the left child and the right child.  The topmost node in a binary tree is called the root, and the bottom-most nodes(having no children) are called leaves
*/
#include <stddef.h>   // defines NULL
#include <stdlib.h>  // defines malloc
//structure of each node
struct Node 
{
    int data;
    struct Node* right;
    struct Node* left;
};

struct Node* createNode(int item){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp -> data = item;
    temp -> left =  temp -> right = NULL;
    return temp;
}

int main (){
    struct Node* firstNode = createNode(1);
    struct Node* secondNode = createNode(2);
    struct Node* thirdNode = createNode(3);
    struct Node* fourthNode = createNode(4);

    firstNode -> left = secondNode;
    firstNode -> right = thirdNode;
    secondNode -> left = fourthNode;

    return 0;
}