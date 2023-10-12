//Program to search a element in binary search tree
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
    if(!root)
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
    int ele;
    node *root = NULL;
    printf("Enter %d elements: ", n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &ele);
        root = insertNode(root, ele);       
    }
    return root;
}

node *searchNode(node *root, int key)
{
    if(!root || root -> data == key)
    {
        return root;
    }
    else if(key < root -> data)
    {
        return searchNode(root -> left, key);
    }
    return searchNode(root -> right, key);
}

int main()
{
    int n, key;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    node *root = createBST(n);
    printf("Enter the element to be searched: ");
    scanf("%d", &key);
    if(searchNode(root, key))
    {
        printf("Element %d found\n", key);
        return 0;
    }
    printf("Element %d not found\n", key);
    return 0;
}