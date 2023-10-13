#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *left, *right;
} node;

int max(int num1, int num2)
{
    return (num1 > num2)? num1 : num2;
}

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
    if(!root) return createNode(data);
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

node *createTree(int n)
{
    node *root = NULL;
    int ele;
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &ele);
        root = insertNode(root, ele);
    }
    return root;
}

int heightOfTree(node *root)
{
    if(!root) return -1;
    return 1 + max(heightOfTree(root -> left), heightOfTree(root -> right));
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    node *root = createTree(n);
    printf("Height of the tree is: %d\n", heightOfTree(root));
    return 0;
}