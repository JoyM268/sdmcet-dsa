/* Define  an  input  restricted  deque  as  a  Deque[A  deque  is  an  ordered  set  of  items  from which items may be deleted at either end, 
(remvleft,remvright) and into which items may be inserted at either end(insertleft,insertright)] for which only the operations remvleft, remright and 
insertleft are valid. Show how each of this can be used to represent both stack and queues respectively. */
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

void display()
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
        printf("\n1:Insert at front\t2:Remove from front\t3:Remove from rear\t4:Display\t5:Exit\n");
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
                remvleft();
                break;
            case 3:
                remvright();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}