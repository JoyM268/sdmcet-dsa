//Program to find the diameter of the binary tree
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *left, *right;
} node;

node *Node(int x)
{
    node *root = (node *)malloc(sizeof(node));
    root -> data = x;
    root -> left = NULL;
    root -> right = NULL;
    return root;
}

node *insertElement(node *root, int data)
{
    if(!root) return Node(data);
    if(data < root -> data) root -> left = insertElement(root -> left, data);
    else if(data > root -> data) root -> right = insertElement(root -> right, data);
    return root;
}

void inorderDisplay(node *root)
{
    if(!root) return;
    inorderDisplay(root -> left);
    printf("%d ", root -> data);
    inorderDisplay(root -> right);
}

int max(int num1, int num2)
{
    return (num1 > num2)? num1 : num2;
}

int findHeight(node *root, int *diameter)
{
    if(!root) return 0;
    int lh = findHeight(root -> left, diameter);
    int rh = findHeight(root -> right, diameter);
    *diameter = max(*diameter, lh + rh);
    return 1 + max(lh, rh);
}

void diameterOfTree(node *root)
{
    int diameter = -1;
    findHeight(root, &diameter);
    printf("The diameter of the tree is %d\n", diameter);
}

int main()
{
    int choice, item;
    node *root = NULL;
    for(;;)
    {
        printf("\n1:Insert\t2:Display\t3:Diameter\t4:Exit\n");
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
                inorderDisplay(root);
                printf("\n");
                break;
            case 3:
                diameterOfTree(root);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}