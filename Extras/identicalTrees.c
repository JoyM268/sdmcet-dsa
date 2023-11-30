//Program to check if two trees are identical or not
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct node{
    int data;
    struct node *left, *right;
}node;

typedef enum{false, true}bool;

bool isIdentical(node *r1, node *r2)
{
    if(!r1 && !r2) return true;
    if(!r1 || !r2) return false;
    return (r1 -> data == r2 -> data && isIdentical(r1 -> left, r2 -> left) && isIdentical(r1 -> right, r2 -> right));
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
    node *root1 = NULL, *root2 = NULL;
    int choice, item;
    for(;;)
    {
        printf("\n1:Insert in tree 1\t2:Insert in tree 2\t3:Display tree 1\t4:Display tree 2\t5:Check identical\t6:Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &item);
                root1 = insertElement(root1, item);
                break;
            case 2:
                printf("Enter the element to be inserted: ");
                scanf("%d", &item);
                root2 = insertElement(root2, item);
                break;
            case 3:
                inorderPrint(root1);
                printf("\n");
                break;
            case 4:
                inorderPrint(root2);
                printf("\n");
                break;
            case 5:
                if(isIdentical(root1, root2))
                {
                    printf("Trees are identical\n");
                    break;
                }
                printf("Trees are not identical\n");
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    }
}