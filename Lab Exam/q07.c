//Write C program to implement an Ascending Priority Queue accepting integers as an input and ensure priority at the time of insertion. 
#include<stdio.h>
#include<stdlib.h>
#define QSIZE 5

int queue[QSIZE], front = 0, rear = -1;
void pqMinInsert(int item)
{
    if(rear == QSIZE - 1)
    {
        printf("Queue is full\n");
        return;
    }
    int j = rear;
    while(j >= 0 && item < queue[j])
    {
        queue[j + 1] = queue[j];
        j--;
    }
    queue[j + 1] = item;
    rear = rear + 1;
}

void pqMinDelete()
{
    if(front > rear)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Deleted element is %d\n", queue[front++]);
    if(front > rear)
    {
        front = 0, rear = -1;
    }
}

void display()
{
    int i;
    if(front > rear)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("The contents of queue are: ");
    for(i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
}

int main()
{
    int choice, item;
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
                pqMinInsert(item);
                break;
            case 2:
                pqMinDelete();
                break;
            case 3:
                display();
                printf("\n");
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}