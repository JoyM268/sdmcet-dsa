//Program to implement double ended queue
#include<stdio.h>
#include<stdlib.h>
#define N 5

int deque[N], f = -1, r = -1;

void enqueFront(int x)
{
    if((f == 0 && r == N - 1) || (f == r + 1))
    {
        printf("Queue is full\n");
    }
    else if(f == -1 && r == -1)
    {
        f = r = 0;
        deque[f] = x;
    }
    else if(f == 0)
    {
        f = N - 1;
        deque[f] = x;
    }
    else
    {
        f--;
        deque[f] = x;
    }
}

void enqueRear(int x)
{
    if((f == 0 && r == N - 1) || (f == r + 1))
    {
        printf("Queue is full\n");
    }
    else if(f == -1 && r == -1)
    {
        f = r = 0;
        deque[r] = x;
    }
    else if(r == N - 1)
    {
        r = 0;
        deque[r] = x;
    }
    else
    {
        r = r + 1;
        deque[r] = x;
    }
}

void display()
{
    if(f == -1 && r == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    int i = f;
    while(i != r)
    {
        printf("%d ", deque[i]);
        i = (i + 1) % N;
    }
    printf("%d\n", deque[i]);
}

void dequeFront()
{
    if(f == -1 && r == -1)
    {
        printf("Empty queue\n");
    }
    else if(f == r)
    {
        printf("Deleted element is %d\n", deque[f]);
        f = r = -1;
    }
    else if(f == N - 1)
    {
        printf("Deleted element is %d\n", deque[f]);
        f = 0;
    }
    else
    {
        printf("Deleted element is %d\n", deque[f]);
        f++;       
    }
}

void dequeRear()
{
    if(f == -1 && r == -1)
    {
        printf("Empty queue\n");
    }
    else if(f == r)
    {
        printf("Deleted element is %d\n", deque[r]);
        f = r = -1;
    }
    else if(r == 0)
    {
        printf("Deleted element is %d\n", deque[r]);
        r = N - 1;
    }
    else
    {
        printf("Deleted element is %d\n", deque[r]);
        r--;       
    }
}

int main()
{
    int item, choice;
    for(;;)
    {
        printf("\n1:Insert at front\t2:Insert at rear\t3:Delete from front\t4:Delete At rear\t5:Display\t6:Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter item to be inserted: ");
                scanf("%d", &item);
                enqueFront(item);
                break;
            case 2:
                printf("Enter item to be inserted: ");
                scanf("%d", &item);
                enqueRear(item);
                break;
            case 3:
                dequeFront();
                break;
            case 4:
                dequeRear();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}