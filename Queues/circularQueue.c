//Write a C program to implement a circular queue
#include<stdio.h>
#include<stdlib.h>
#define Qsize 5

void cqInsert(int item, int q[], int *r, int *cnt)
{
    if(*cnt == Qsize)
    {
        printf("Queue overflow\n");
        return;
    }
    *r = (*r + 1) % Qsize;
    q[*r] = item;
    *cnt += 1;
}

void cqDelete(int q[], int *f, int *count)
{
    if(*count == 0)
    {
        printf("Queue underflow\n");
        return;
    }
    printf("The deleted element is %d\n", q[*f]);
    *f = (*f + 1) % Qsize;
    *count -= 1;
}

void cqDisplay(int q[], int cnt, int f)
{
    int i;
    if(cnt == 0)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Contents of queue are:\n");
    for(i = 1; i <= cnt; i++)
    {
        printf("%d\t%d\n", f, q[f]);
        f = (f + 1) % Qsize;
    }
} 

int main()
{
    int q[Qsize], count = 0, f = 0, r = -1, choice, item;
    for(;;)
    {
        printf("\n1:QInsert@Rear\t2:QDelete@Front\t3:QDisplay\t4:QExit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter item to be inserted: ");
                scanf("%d", &item);
                cqInsert(item, q, &r, &count);
                break;
            case 2:
                cqDelete(q, &f, &count);
                break;
            case 3:
                cqDisplay(q, count, f);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    }
}