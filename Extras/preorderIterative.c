//Program to implement preorder traversal iteratively
#include<stdio.h>
#include<stdlib.h>
#define SIZE 30

typedef struct node{
    int data;
    struct node *left, *right;
}node;

node *stack[SIZE];
int top = -1;

void push(node *root)
{
    stack[++top] = root;
}

node *pop()
{
    return stack[top--];
}

node *Node(int x)
{
    node *root = (node *)malloc(sizeof(node));
    root -> data = x;
    root -> left = NULL;
    root -> right = NULL;
}

node *insert(node *root, int x)
{
    if(!root)
    {
        return Node(x);
    }
    else if(x < root-> data)
    {
        root -> left = insert(root -> left, x);
    }
    else if(x > root -> data)
    {
        root -> right = insert(root -> right, x);
    }
    return root;
}

void preorder(node *root)
{
    if(!root)
    {
        printf("Tree is empty\n");
        return;
    }
    printf("The contents of tree are: ");
    push(root);
    while(top != -1)
    {
        node *temp = pop();
        printf("%d ", temp -> data);
        if(temp -> right) push(temp -> right);
        if(temp -> left) push(temp -> left);
    }
    printf("\n");
}

int main()
{
    node *root = NULL;
    int choice, item;
    for(;;)
    {
        printf("\n1:Insert\t2:Display\t3:Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);   
        switch(choice)
        {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &item);
                root = insert(root, item);
                break;
            case 2:
                preorder(root);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}