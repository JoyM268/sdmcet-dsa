//Program to delete a node in binary search tree
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *left, *right;
}node;

node *Node(int x)
{
    node *root = (node *)malloc(sizeof(node));
    root -> data = x;
    root -> left = NULL;
    root -> right = NULL;
    return root; 
}

node *insert(node *root, int x)
{
    if(!root)
    {
        return Node(x);
    }
    else if(x < root -> data)
    {
        root -> left = insert(root -> left, x);
    }
    else if(x > root -> data)
    {
        root -> right = insert(root -> right, x);
    }
    return root;
}

void display(node *root)
{
    if(!root) return;
    display(root -> left);
    printf("%d ", root -> data);
    display(root -> right); 
}

node *min(node *root)
{
    if(root == NULL) return root;;
    while(root -> left != NULL)
    {
        root = root -> left;
    }
    return root;
}

node *delete(node *root, int x)
{
    if(!root) return root;
    if(x < root -> data)
    {
        root -> left = delete(root -> left, x);
    }
    else if(x > root -> data)
    {
        root -> right = delete(root -> right, x);
    }
    else
    {
        if(root -> left == NULL && root -> right == NULL)
        {
            free(root);
            root = NULL;
        }
        else if(root -> left == NULL)
        {
            node *temp = root;
            root = root -> right;
            free(temp);
        }
        else if(root -> right == NULL)
        {
            node *temp = root;
            root = root -> left;
            free(temp);
        }
        else
        {
            node *temp = min(root -> right);
            root -> data = temp -> data;
            root -> right = delete(root -> right, temp -> data);
            free(temp);
        }
    }
    return root;
}

int main()
{
    node *root = NULL;
    int item, choice;
    while(1)
    {
        printf("\n1:Insert\n2:Delete\n3:Display\n4:Exit\n");
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
                printf("Enter the element to be deleted: ");
                scanf("%d", &item);
                root = delete(root, item);
                break;
            case 3:
                printf("The contents of the tree:\n");
                display(root);
                printf("\n");
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}