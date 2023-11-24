//Program to find maximum depth of binary trees
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *left, *right;
}node;

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

int max(int num1, int num2)
{
    return (num1 > num2)? num1 : num2;
}

int maximumDepth(node *root)
{
    if(!root) return 0;
    int left = maximumDepth(root -> left);
    int right = maximumDepth(root -> right);
    return 1 + max(left, right);
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
        printf("\n1:Insert\t2:Max Depth\t3:Display\t4:Exit\n");
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
                item = maximumDepth(root);
                printf("The maximum depth of binary tree is: %d\n", item);
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