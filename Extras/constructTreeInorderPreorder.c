//Program to construct a binary tree using array of inorder and preorder traversals
#include<stdio.h>
#include<stdlib.h>
#define SIZE 50

typedef struct node{
    int data;
    struct node *left, *right;
}node;

node *createNode(int data)
{
    node *root = (node *)malloc(sizeof(node));
    root -> left = NULL;
    root -> right = NULL;
    root -> data = data;
    return root;
}

int searchElement(int arr[], int start, int end, int key)
{
    int i;
    for(i = start; i <= end; i++)
    {
        if(arr[i] == key)
            return i;
    }
}

node *createTree(int preorder[], int inorder[], int start, int end)
{
    static int preIndex = 0;
    if(start > end)
        return NULL;
    node *root = createNode(preorder[preIndex++]);
    if(start == end)
    {
        return root;
    }
    int index = searchElement(inorder, start, end, root -> data);
    root -> left = createTree(preorder, inorder, start, index - 1);
    root -> right = createTree(preorder, inorder, index + 1, end);
    return root;
}

void inorderTraversal(node *root)
{
    if(root == NULL) return;
    inorderTraversal(root -> left);
    printf("%d ", root -> data);
    inorderTraversal(root -> right);
}

void preorderTraversal(node *root)
{
    if(root == NULL) return;
    printf("%d ", root -> data);
    preorderTraversal(root -> left);
    preorderTraversal(root -> right);
}

void postorderTraversal(node *root)
{
    if(root == NULL) return;
    postorderTraversal(root -> left);
    postorderTraversal(root -> right);
    printf("%d ", root -> data);
}

void readArray(int *arr, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}

int main()
{
    int inorder[SIZE], preorder[SIZE], n;
    printf("Enter the number of nodes in the tree: ");
    scanf("%d", &n);
    printf("Enter the preorder traversal: ");
    readArray(preorder, n);
    printf("Enter the inorder traversal: ");
    readArray(inorder, n);
    node *root = createTree(preorder, inorder, 0, n - 1);
    printf("\nThe inorder traversal of the tree:\n");
    inorderTraversal(root);
    printf("\nThe preorder traversal of the tree:\n");
    preorderTraversal(root);
    printf("\nThe postorder traversal of the tree:\n");
    postorderTraversal(root);
    printf("\n");
}