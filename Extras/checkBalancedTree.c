//program to check wheter the binary tree is balanced or not
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *left, *right;
}node;

typedef enum{false, true}bool;

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

int check(node *root)
{
    if(!root) return 0;
    int left = check(root -> left);
    int right = check(root -> right);
    if(left == -1 || right == -1) return -1;
    if(abs(left - right) > 1) return -1;
    return 1 + max(left, right);
}

bool isBalanced(node *root)
{
    if(!root) return true;
    if(check(root) == -1) return false;
    return true;   
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
        printf("\n1:Insert\t2:Display\t3:Check Balanced\t4:Exit\n");
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
                inorderPrint(root);
                printf("\n");
                break;
            case 3:
                if(isBalanced(root))
                {
                    printf("The binary tree is balanced\n");
                    break;
                }
                printf("The binary tree is not balanced\n");
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid Choice\n");
        }       
    }
}