//Program to implement circular queues
#include<stdio.h>
#include<stdlib.h>
#define QSIZE 5

typedef struct{
    int queue[QSIZE], front, rear, count;
} Queue;

void queueInsert(Queue *q, int item)
{
    if(q -> count == QSIZE)
    {
        printf("Queue is full\n");
        return;
    }
    q -> rear = ((q -> rear) + 1) % QSIZE;
    q -> queue[q -> rear] = item;
    (q -> count)++;
}

int queueDelete(Queue *q)
{
    int item;
    if(q -> count == 0)
    {
        printf("Queue is empty\n");
        return -1;
    }
    item = q -> queue[q -> front];
    printf("%d", item);
    (q -> count)--;
    q -> front = (q -> front + 1) % QSIZE;
    return item;
}

void display(Queue *q)
{
    int i;
    if(q -> count == 0)
    {
        printf("Queue is Empty\n");
        return;
    }
    printf("The contents of queue are:\n");
    for(i = (q -> front); i < ((q -> front) + (q -> count)); i++)
    {
        printf("%d ", q -> queue[(i % QSIZE)]);
    }
    printf("\n");
}

int main()
{
    Queue q;
    q.front = 0, q.rear = -1, q.count = 0;
    int choice, item;
    do{
        printf("\n1:Insert\t2:Delete\t3:Display\t4:Exit\n");
        printf("Enter a choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &item);
                queueInsert(&q, item);
                break;
            case 2:
                item = queueDelete(&q);
                if(item != -1)
                {
                    printf("Element %d deleted from queue\n", item);
                }
                break;
            case 3:
                display(&q);
                break;
            case 4:
                break;
            default:
                printf("Invalid Choice\n");
        }
    }while(choice != 4); 
}