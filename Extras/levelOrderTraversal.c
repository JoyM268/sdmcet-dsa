//Program to implement level order traversal using queue
#include<stdio.h>
#include<stdlib.h>
#define SIZE 50

typedef struct node{
    int data;
    struct node *left, *right;
}node;

typedef struct queue{
    node *q[SIZE];
    int front, rear;
}queue;

void enqueue(queue *lq, node *root)
{
    lq -> q[++lq -> rear] = root;
}

node *dequeue(queue *lq)
{
    node *root = lq -> q[lq -> front++];
    if(lq -> front > lq -> rear)
    {
        lq -> front = 0;
        lq -> rear = -1;
    }
    return root;
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

void BFS(node *root)
{
    queue lq;
    lq.front = 0;
    lq.rear = -1;
    node *temp = NULL;
    enqueue(&lq, root);
    while(lq.rear != -1 && lq.front <= lq.rear)
    {
        temp = dequeue(&lq);
        printf("%d ", temp -> data);
        if(temp -> left) enqueue(&lq, temp -> left);
        if(temp -> right) enqueue(&lq, temp -> right);
    }
    printf("\n");
}

main()
{
    node *root = NULL;
    int choice, ele;
    while(1)
    {
        printf("\n1:Insert\n2:Print\n3:Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the element: ");
                scanf("%d", &ele);
                root = insert(root, ele);
                break;
            case 2:
                printf("Contents of the tree:\n");
                BFS(root);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    }
    BFS(root);
}