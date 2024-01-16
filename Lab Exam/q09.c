/* Write a C program to implement queue operations using input Restricted Deque(double ended queue) works. 
insertqfront(), remvleft(), remvright(), displayq() */
#include<stdio.h>
#include<stdlib.h>
#define Qsize 5

//Answer: We can implement queue using input restricted Deque by using insertqfront() for insert operation and remvright() for delete operation.
int dequeue[Qsize], front = -1, rear = -1;
void insertqfront(int item)
{
    if((front == 0 && rear == Qsize - 1) || (front == rear + 1))
    {
        printf("Queue is full\n");
        return;
    }
    else if(front == -1 && rear == -1)
    {
        front = rear = 0;
    }
    else if(front == 0)
    {
        front = Qsize - 1;
    }
    else
    {
        front--;
    }
    dequeue[front] = item;
}

void remvleft()
{
    int item;
    if(front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
        return;
    } 
    item = dequeue[front];
    if(front == rear)
    {
        front = rear = -1;
    }
    else if(front == Qsize - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
    printf("Deleted element is %d\n", item);
}

void remvright()
{
    int item;
    if(front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    item = dequeue[rear];
    if(front == rear)
    {
        front = rear = -1;
    }
    else if(rear == 0)
    {
        rear = Qsize - 1;
    }
    else
    {
        rear--;
    }
    printf("Deleted element is %d\n", item);
}

void displayq()
{
    int i;
    if(front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("The contents of queue are:\n");
    for(i = front; i != rear; i = (i + 1) % Qsize)
    {
        printf("Queue[%d] = %d\n", i, dequeue[i]);
    }
    printf("Queue[%d] = %d\n", i, dequeue[i]);
}

int main()
{
    int choice, item;
    for(;;)
    {
        printf("\n1:Insert at front(insert)\t2:Remove from left\t3:Remove from right(delete)\t4:Display queue\t5:Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &item);
                insertqfront(item);
                break;
            case 2:
                remvleft();
                break;
            case 3:
                remvright();
                break;
            case 4:
                displayq();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}