//Write a C program to implement linear Queue using structures and pointers
#include<stdio.h>
#include<stdlib.h>
#define Qsize 4

struct Queue{
    int q[Qsize], f, r;
};

void lqInsertRear(struct Queue *lq, int ele)
{
    if(lq -> r == Qsize - 1)
    {
        printf("Queue overflow\n");
        return;
    }
    lq -> q[++(lq -> r)] = ele;
}

int lqDeleteFront(struct Queue *lq)
{
    if((lq -> f) > (lq -> r) || lq -> r == -1)
    {
        printf("Queue underflow\n");
        if(lq -> f > lq -> r) lq -> f = 0, lq -> r = -1;
        return -1;
    }
    return lq -> q[(lq -> f)++]; 
}

void display(struct Queue lq)
{
    int i;
    if((lq.f > lq.r) || lq.r == -1)
    {
        printf("No elements to display\n");
        return;
    }
    for(i = lq.f; i <= lq.r; i++)
    {
        printf("Queue[%d] = %d\n", i, lq.q[i]);
    }
}

int main()
{
    int ele, choice;
    struct Queue lq;
    lq.f = 0; lq.r = -1;
    for(;;)
    {
        printf("\n1:QInsert@Rear\t2:QDelete@Front\t3:QDisplay\t4:QExit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &ele);
                lqInsertRear(&lq, ele);
                break;
            case 2:
                ele = lqDeleteFront(&lq);
                if(ele == -1)
                {
                    printf("Queue is empty\n");
                }
                else
                {
                    printf("Deleted element is %d\n", ele);
                }
                break;
            case 3:
                printf("Contents of Queue are:\n");
                display(lq);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    }
}