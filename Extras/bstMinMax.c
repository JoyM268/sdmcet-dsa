//Program to find minimum and maximum element in binary search trees
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
    return root;
}

node *insertNode(node *root, int data)
{
    if(root == NULL)
    {
        return createNode(data);
    }
    else if(data < root -> data)
    {
        root -> left = insertNode(root -> left, data);
    }
    else if(data > root -> data)
    {
        root -> right = insertNode(root -> right, data);
    }
    return root;
}

node *createBST(int n)
{
    int item;
    node *root = NULL;
    printf("Enter %d elements: ", n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &item);
        root = insertNode(root, item);
    }
    return root;
}

int minimumElement(node *root)
{
    if(root -> left == NULL)
    {
        return root -> data;
    }
    return minimumElement(root -> left);
}

int maximumElement(node *root)
{
    if(root -> right == NULL)
    {
        return root -> data;
    }
    return maximumElement(root -> right);
}

int main()
{
    int n;
    node *root = NULL;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    root = createBST(n);
    printf("The minimum element in BST is: %d\n", minimumElement(root));
    printf("The maximum element in BST is: %d\n", maximumElement(root));
    return 0;
}