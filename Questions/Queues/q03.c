// Write C routines to implement queue operations using output restricted deque for which the operations removeleft(), insertright() and insertleft() are valid.
#include<stdio.h>
#include<stdlib.h>
#define Qsize 5

int dequeue[Qsize], front = -1, rear = -1;
void insertleft(int item)
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

void insertright(int item)
{
    if((front == 0 && rear == Qsize - 1) || (front == rear + 1))
    {
        printf("Queue is full\n");
    }
    else if(front == -1 && rear == -1)
    {
        front = rear = 0;
    }
    else if(rear == Qsize - 1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }
    dequeue[rear] = item;
}

void removeleft()
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
        printf("\n1:Insert at left\t2:Insert at right\t3:Remove from left\t4:Display queue\t5:Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &item);
                insertleft(item);
                break;
            case 2:
                printf("Enter the element to be inserted: ");
                scanf("%d", &item);            
                insertright(item);
                break;
            case 3:
                removeleft();
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