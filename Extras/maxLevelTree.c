//Program to find maximum element in each level of tree
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
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
    if(front > rear) front = 0, rear = -1;
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

void maxElement(node *root)
{
    if(!root)
    {
        printf("Tree is empty\n");
        return;
    }
    int l = 0;
    enqueue(root);
    printf("\n");
    while(rear != -1 && front <= rear)
    {
        int size = rear - front + 1, maxValue = INT_MIN;
        for(int i = 0; i < size; i++)
        {
            node *temp = dequeue();
            if(temp -> data > maxValue) maxValue = temp -> data;
            if(temp -> left) enqueue(temp -> left);
            if(temp -> right) enqueue(temp -> right);
        }
        printf("Maximum element at level %d is %d\n", l++, maxValue);
    }
}

int main()
{
    node *root = NULL;
    int choice, x;
    for(;;)
    {
        printf("\n1:Insert\t2:Print max at each level\t3:Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the element inserted: ");
                scanf("%d", &x);
                root = insert(root, x);
                break;
            case 2:
                maxElement(root);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}