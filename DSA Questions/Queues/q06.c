//Write C function to reverse all the elements in a queue.
#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

int queue[SIZE], front = 0, rear = -1;
void insert(int item)
{
    if(rear == SIZE - 1)
    {
        printf("Queue is fUll\n");
        return;
    }
    queue[++rear] = item;
}

void delete()
{
    if(rear == -1 || front > rear)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("%d deleted from the queue\n", queue[front++]);
    if(front > rear) front = 0, rear = -1;
}

void reverseQueue()
{
    if(rear == -1 || front > rear) return;
    int item = queue[front++];
    reverseQueue();
    if(front > rear) front = 0, rear = -1;
    queue[++rear] = item;
}

//OR
/*
void reverseQueue()
{
    int stack[SIZE], top = -1, i;
    for(i = front; i <= rear; i++)
    {
        stack[++top] = queue[i];
    }
    i = front;
    while(top != -1)
    {
        queue[i] = stack[top--];
    }
}
*/

void display()
{
    if(rear == -1 || front > rear)
    {
        printf("Queue is empty\n");
        return;
    }
    int i;
    for(i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main()
{
    int choice, item;
    for(;;)
    {
        printf("\n1.Insert\t2.Delete\t3.Reverse\t4.Display\t5.Exit\n");
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
                reverseQueue();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    }
}