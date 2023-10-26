//Program to find sum of elements in each level of a tree
#include<stdio.h>
#include<stdlib.h>
#define SIZE 50

typedef struct node{
    int data;
    struct node *left, *right;
}node;

node *queue[SIZE];
int front = 0, rear = -1; 

void enqueue(node *root)
{
    queue[++rear] = root;
}

node *dequeue()
{
    node *temp = queue[front++];
    if(front > rear)
    {
        front = 0;
        rear = -1;
    }
    return temp;
}

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
    if(!root) return Node(x);
    if(x < root -> data) root -> left = insert(root -> left, x);
    if(x > root -> data) root -> right = insert(root -> right, x);
    return root;
}

void printLevelSum(node *root)
{
    if(!root)
    {
        printf("The tree is empty\n");
        return;
    }
    enqueue(root);
    int l = 0;
    printf("\n");
    while(front <= rear && rear != -1)
    {
        int size = rear - front + 1, sum = 0;
        for(int i = 0; i < size; i++)
        {
            node *temp = dequeue();
            sum += temp -> data;
            if(temp -> left) enqueue(temp -> left);
            if(temp -> right) enqueue(temp -> right);
        }
        printf("Sum of elements on level %d: %d\n", l++, sum);
    }
}

int main()
{
    node *root = NULL;
    int choice, x;
    for(;;)
    {
        printf("\n1:Insert\t2:Print level sum\t3:Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &x);
                root = insert(root, x);
                break;
            case 2:
                printLevelSum(root);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}