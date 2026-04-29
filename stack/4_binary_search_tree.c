#include<stdio.h>
#include<stdlib.h>

/**
 * Each node has a value (data) and two pointers, one to reference the left child or NULL and the oter to reference the right child or NULL
 * BST --> the name of struct 
 * node --> alias name
 * struct BST *p; == node *p
 */
typedef struct BST
{
    int data; // the value of node , each node has a value
    struct BST *left; // pointer struct BST (address from left child)
    struct BST *right; // pointer struct BST (address from right child)
} node;

node *create();
void insert(node *root, node *temp);
void preorder(node *root);


/*
*  This function creates a new node and returns the address from this node
* 
*/
node *create()
{
    node *temp; // temp holds the new address 
    printf("\nEnter the data:");
    temp = (node*)malloc(sizeof(node));   // memory in heap and returns the pointer
    scanf("%d", &temp->data);
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
}

/*
*  This recursive function inserts the new node in BST
* 
*/
void insert(node *root , node *temp)
{
    if(temp -> data < root -> data )
    {
        if(root -> left !=NULL)
        
            insert(root -> left , temp);
        else
            root -> left = temp;
    }

    if (temp -> data > root -> data)
    {
        if(root -> right!=NULL)
        
            insert(root -> right , temp);
        else
            root -> right = temp;
    }
}

/*
*  This  function traverses the tree
* 
*/
void preorder(node *root)
{
    if (root != NULL)
    {
        printf("%d" , root->data);
        preorder(root -> left);
        preorder(root -> right);
    }
}


int main()
{
    char ch;
    node *root = NULL;
    node *temp = NULL;

    do
    {
        temp = create();
        if (root == NULL)
            root = temp;
        else
            insert(root , temp);
        
        printf("\nDo you want to enter more(y/n)?");
		getchar();
		scanf("%c",&ch);

    } while (ch == 'y' | ch=='Y');

    printf("\nPreorder Traversal: ");
	preorder(root);
	return 0;
}