/* Write a C program to implement the following on priority queue, consisting 
of three queues:  
i.  insert()  –  start  inserting  the  elements  into  the  queues  from  the  first 
queue. 
ii.  delete() - start deleting the elements from the first queue.  
iii.  display() */
#include<stdio.h>
#include<stdlib.h>
#define QSIZE 5

struct queue{
    int q[QSIZE], front, rear;
}q1, q2, q3;

int isFull(struct queue lq)
{
    return (lq.rear == QSIZE - 1);
}

int isEmpty(struct queue lq)
{
    return (lq.front > lq.rear || lq.rear == -1);
}

void insert(int item)
{
    if(!isFull(q1))
    {
        q1.q[++q1.rear] = item;
    }
    else if(!isFull(q2))
    {
        q2.q[++q2.rear] = item;
    }
    else if(!isFull(q3))
    {
        q3.q[++q3.rear] = item;
    }
    else
    {
        printf("Queue is full\n");
    }
}

void delete()
{
    int item;
    if(!isEmpty(q1))
    {
        item = q1.q[q1.front++];
    }
    else if(!isEmpty(q2))
    {
        item = q2.q[q2.front++];
    }
    else if(!isEmpty(q3))
    {
        item = q3.q[q3.front++];
    }
    else
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Element %d deleted from queue\n", item);
    if(isEmpty(q1) && isEmpty(q2) && isEmpty(q3))
    {
        q1.front = q2.front = q3.front = 0;
        q1.rear = q2.rear = q3.rear = -1;       
    }
}

void display()
{
    int i;
    if(isEmpty(q1) && isEmpty(q2) && isEmpty(q3))
    {
        printf("Queue is empty\n");
        return;
    }
    printf("The contents of queue are: ");
    if(!isEmpty(q1))
    {
        for(i = q1.front; i <= q1.rear; i++)
        {
            printf("%d ", q1.q[i]);
        }
    }
    if(!isEmpty(q2))
    {
        for(i = q2.front; i <= q2.rear; i++)
        {
            printf("%d ", q2.q[i]);
        }
    }
    if(!isEmpty(q3))
    {
        for(i = q3.front; i <= q3.rear; i++)
        {
            printf("%d ", q3.q[i]);
        }
    }
    printf("\n");
}

int main()
{
    int choice, item;
    q1.front = q2.front = q3.front = 0;
    q1.rear = q2.rear = q3.rear = -1;
    for(;;)
    {
        printf("\n1:Insert\t2:Delete\t3:Display\t4:Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &item);
                insert(item);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}