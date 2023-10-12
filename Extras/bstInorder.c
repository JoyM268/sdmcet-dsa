//Program to perform inorder traversal on binary search trees
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *left, *right; 
} node;

node *createNode(int data)
{
    node *root = (node *)malloc(sizeof(node));
    root -> data = data;
    root -> left = NULL;
    root -> right = NULL;
}

node *insertElement(node *root, int data)
{
    if(root == NULL)
    {
        return createNode(data);
    }
    else if(data < root -> data)
    {
        root -> left = insertElement(root -> left, data);
    }
    else if(data > root -> data)
    {
        root -> right = insertElement(root -> right, data);
    }
    return root;
}

void inorderTraversal(node *root)
{
    if(root == NULL) return;
    inorderTraversal(root -> left);
    printf("%d ", root -> data);
    inorderTraversal(root -> right);
}

int main()
{
    node *root = NULL;
    int choice, item;
    while(1)
    {
        printf("\n1.Insert\n2.Inorder traversal\n3.Exit\n");
        printf("Enter the choice(1, 2, 3): ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &item);
                root = insertElement(root, item);
                break;
            case 2:
                printf("The contents of the BST are:\n");
                inorderTraversal(root);
                printf("\n");
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    }
    return 0;
}