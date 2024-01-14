/* Write a C routines for implementation of an ascending priority queue whith following operations:
pqinsert()
pqmindelete()
pqempty() */
#include<stdio.h>
#include<stdlib.h>
#define QSIZE 5

int queue[QSIZE], front = 0, rear = -1;
int pqempty()
{
    if(front > rear) return 1;
    return 0;
}

void pqinsert(int item)
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

void pqmindelete()
{
    if(pqempty())
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Deleted element is %d\n", queue[front++]);
    if(front > rear)
        front = 0, rear = -1;
}

void display()
{
    int i;
    if(pqempty())
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
        printf("\n1:Insert\t2:Delete\t3:Display\t4.Check empty\t5:Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &item);
                pqinsert(item);
                break;
            case 2:
                pqmindelete();
                break;
            case 3:
                display();
                printf("\n");
                break;
            case 4:
                if(pqempty())
                    printf("Queue is empty\n");
                else
                    printf("Queue is not empty\n");
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}