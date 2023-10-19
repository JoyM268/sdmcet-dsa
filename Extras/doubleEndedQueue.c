//Program to implement double ended queue
#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

int queue[SIZE], front = -1, rear = -1;

void insertRear(int item)
{
    if(front == 0 && rear == SIZE - 1 || front == rear + 1)
    {
        printf("Queue is full\n");
        return;
    }
    else if(front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = item;
    }
    else if(rear == SIZE - 1)
    {
        rear = 0;
        queue[rear] = item;
    }
    else
    {
        queue[++rear] = item;
    }
}

void insertFront(int item)
{
    if(front == 0 && rear == SIZE - 1 || front == rear + 1)
    {
        printf("Queue is full\n");
        return;
    }
    else if(front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[front] = item;
    }
    else if(front == 0)
    {
        front = SIZE - 1;
        queue[front] = item;
    }
    else
    {
        queue[--front] = item;
    }
}

int removeFront()
{
    int item;
    if(front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
        return -1;
    }
    else if(front == rear)
    {
       item = queue[front];
       front = rear = -1;
    }
    else if(front == SIZE - 1)
    {
        item = queue[front];
        front = 0;
    }
    else
    {
        item = queue[front++];       
    }
    return item;
}

int removeRear()
{
    int item;
    if(front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
        return -1;
    }
    else if(front == rear)
    {
        item = queue[rear];
        front = rear = -1;
    }
    else if(rear == 0)
    {
        item = queue[rear];
        rear = SIZE - 1;
    }
    else
    {
        item = queue[rear--];       
    }
    return item;
}

void display()
{
    if(front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("The contents of the queue are:\n");
    for(int i = front; i != rear; i = (i + 1) % SIZE)
    {
        printf("queue[%d] = %d\n", i, queue[i]);
    }
    printf("queue[%d] = %d\n", rear, queue[rear]);
}

int main()
{
    int item, choice;
    for(;;)
    {
        printf("\n1:Insert at front\n");
        printf("2:Insert at rear\n");
        printf("3:Delete at front\n");
        printf("4:Delete at rear\n");
        printf("5:Display\n");
        printf("6:Exit\n");
        printf("Enter the choice(1, 2, 3, 4, 5, 6): ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter a element: ");
                scanf("%d", &item);
                insertFront(item);
                break;
            case 2:
                printf("Enter a element: ");
                scanf("%d", &item);
                insertRear(item);
                break;
            case 3:
                item = removeFront();
                if(item != -1)
                {
                    printf("Element %d deleted\n", item);
                }
                break;
            case 4:
                item = removeRear();
                if(item != -1)
                {
                    printf("Element %d deleted\n", item);
                }
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    }
}