//Program to print tree in zig zag order
#include<stdio.h>
#include<stdlib.h>
#define SIZE 50

typedef struct node{
    int data;
    struct node *left, *right;
}node;

typedef struct{
    node *q[SIZE];
    int rear, front;
}queue;

typedef enum{false, true}bool;

void enqueue(node *root, queue *lq)
{
    lq -> q[++lq -> rear] = root;
}

node *dequeue(queue *lq)
{
    return lq -> q[lq -> front++];
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

void zigZagPrint(node *root)
{
    if(!root) 
    {
        printf("Tree is empty\n");
        return;
    }
    bool flag = false;
    queue lq;
    lq.front = 0;
    lq.rear = -1;
    enqueue(root, &lq);
    while(lq.front <= lq.rear)
    {
        int size = lq.rear - lq.front + 1;
        int *level = (int *)malloc(size * sizeof(int));
        for(int i = 0; i < size; i++)
        {
            node *temp = dequeue(&lq);
            int index = (flag)? size - i - 1 : i;
            level[index] = temp -> data;
            if(temp -> left) enqueue(temp -> left, &lq);
            if(temp -> right) enqueue(temp -> right, &lq);
        }
        for(int i = 0; i < size; i++)
        {
            printf("%d ", level[i]);
        }
        flag = !flag;
    }
}

int main()
{
    node *root = NULL;
    int choice, item;
    for(;;)
    {
        printf("\n1:Insert\t2:Zig-zag print\t3:Exit\n");
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
                zigZagPrint(root);                
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    }
    return 0;
}