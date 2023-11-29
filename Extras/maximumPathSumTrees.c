//Program to find maximum path sum in a binary tree
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct node{
    int data;
    struct node *left, *right;
}node;

int max(int num1, int num2)
{
    return (num1 > num2)? num1 : num2;
}

int findSum(node *root, int *ans)
{
    if(!root) return 0;
    int lsum = max(0, findSum(root -> left, ans));
    int rsum = max(0, findSum(root -> right, ans));
    *ans = max(*ans, lsum + rsum + root -> data);
    return root -> data + max(lsum, rsum);
}

int maxPathSum(node *root)
{
    int ans = INT_MIN;
    findSum(root, &ans);
    return ans;
}

node *createNode(int data)
{
    node *root = (node *)malloc(sizeof(node));
    root -> data = data;
    root -> left = NULL;
    root -> right = NULL;
    return root;
}

node *insertElement(node *root, int data)
{
    if(!root) return createNode(data);
    if(data < root -> data) root -> left = insertElement(root -> left, data);
    else if(data > root -> data) root -> right = insertElement(root -> right, data);
    return root;
}

void inorderPrint(node *root)
{
    if(!root) return;
    inorderPrint(root -> left);
    printf("%d ", root -> data);
    inorderPrint(root -> right);
}

int main()
{
    node *root = NULL;
    int choice, item;
    for(;;)
    {
        printf("\n1:Insert\t2:Max Path Sum\t3:Display\t4:Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &item);
                root = insertElement(root, item);
                break;
            case 2:
                item = maxPathSum(root);
                printf("The maximum path sum of binary tree is: %d\n", item);
                break;
            case 3:
                inorderPrint(root);
                printf("\n");
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    }
}