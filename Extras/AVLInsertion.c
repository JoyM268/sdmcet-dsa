//Program to perform insertion in AVL Trees.
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *left, *right;
    int height;
}node;

node *createNode(node *root, int data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp -> data = data;
    temp -> left = NULL;
    temp -> right = NULL;
    temp -> height = 1;
    return temp;
}

int max(int a, int b)
{
    return (a > b)? a:b;
}

int height(node *root)
{
    if(root == NULL) return 0;
    return root -> height;
}

int balancedFactor(node *root)
{
    if(root == NULL) return 0;
    return height(root -> left) - height(root -> right);
}

node *leftRotate(node *root)
{
    node *temp = root -> right;
    root -> right = temp -> left;
    temp -> left = root;
    temp -> height = 1 + max(height(temp -> left), height(temp -> right));
    root -> height = 1 + max(height(root -> left), height(root -> right));
    return temp;
}

node *rightRotate(node *root)
{
    node *temp = root -> left;
    root -> left = temp -> right;
    temp -> right = root;
    temp -> height = 1 + max(height(temp -> left), height(temp -> right));
    root -> height = 1 + max(height(root -> left), height(root -> right));
    return temp;
}

node *insertAVL(node *root, int data)
{
    if(root == NULL) return createNode(root, data);
    else if(data < root -> data) root -> left = insertAVL(root -> left, data);
    else if(data > root -> data) root -> right = insertAVL(root -> right, data);
    else return root;
    root -> height = 1 + max(height(root -> left), height(root -> right));
    int Balanced = balancedFactor(root);
    if(Balanced > 1 && data < root -> left -> data)
    {
        return rightRotate(root);
    }
    else if(Balanced > 1 && data > root -> left -> data)
    {
        root -> left = leftRotate(root -> left);
        return rightRotate(root);
    }
    else if(Balanced < -1 && data > root -> right -> data)
    {
        return leftRotate(root);
    }
    else if(Balanced < -1 && data < root -> right -> data)
    {
        root -> right = rightRotate(root -> right);
        return leftRotate(root);
    }
    return root;
}

void preorder(node *root)
{
    if(root == NULL) return;
    printf("%d ", root -> data);
    preorder(root -> left);
    preorder(root -> right);
}

int main()
{
    node *root = NULL;
    int item, choice;
    for(;;)
    {
        printf("\n1.Insert\t2.Print\t3.Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &item);
                root = insertAVL(root, item);
                break;
            case 2:
                preorder(root);
                printf("\n");
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}