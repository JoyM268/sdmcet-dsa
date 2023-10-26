//Program to implement chaining using trees
#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

typedef struct node{
    int data;
    struct node *left, *right;
} node;

node *chain[SIZE];

node *createNode(int item)
{
    node *temp = (node *)malloc(sizeof(node));
    temp -> data = item;
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
}

node *searchNode(node *root, int item)
{
    if(!root || root -> data == item) return root;
    else if(item < root -> data)
    {
        return searchNode(root -> left, item);
    }
    return searchNode(root -> right, item);
} 

node *insertNode(node *root, int item)
{
    if(!root) return createNode(item);
    else if(item < root -> data) root -> left = insertNode(root -> left, item);
    else if(item > root -> data) root -> right = insertNode(root -> right, item);
    return root;
}

void displayTree(node *root)
{
    if(!root) return;
    displayTree(root -> left);
    printf("%d     ", root -> data);
    displayTree(root -> right);
}

node *min(node *root)
{
    while(root -> left)
    {
        root = root -> left;
    }
    return root;
}

node *deleteNode(node *root, int item)
{
    if(!root) return root;
    if(item < root -> data)
    {
        root -> left = deleteNode(root -> left, item);
    }
    else if(item > root -> data)
    {
        root -> right = deleteNode(root -> right, item);
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
            root -> right = deleteNode(root -> right, temp -> data);
            free(temp);
        }
    }
    return root;
}

void insertInChain(int item)
{
    int index = item % SIZE;
    chain[index] = insertNode(chain[index], item);           
}

void searchInChain(int item)
{
    int index = item % SIZE;
    if(searchNode(chain[index], item))
    {
        printf("%d found\n", item);
        return;
    }
    printf("%d not found\n", item);
}

void deleteInChain(int item)
{
    int index = item % SIZE;
    chain[index] = deleteNode(chain[index], item);
}

void displayChain()
{
    for(int i = 0; i < SIZE; i++)
    {
        if(chain[i])
        {
            displayTree(chain[i]);
        }
        else
        {
            printf("NULL");
        }
        printf("\n");
    }
}

int main()
{
    int choice, item;
    for(;;)
    {
        printf("\n1.Insert\t2.Search\t3.Delete\t4.Display\t5.Exit\n");
        printf("Enter the choice(1, 2, 3, 4, 5): ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter the element: ");
                scanf("%d", &item);
                insertInChain(item);
                break;
            case 2:
                printf("Enter the element: ");
                scanf("%d", &item);
                searchInChain(item);
                break;
            case 3:
                printf("Enter the element: ");
                scanf("%d", &item);
                deleteInChain(item);
                break;
            case 4:
                printf("The contents of the chain are:\n");
                displayChain();
                printf("\n");
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    }
    return 0;
}