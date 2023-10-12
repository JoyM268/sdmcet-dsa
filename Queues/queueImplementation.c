//Write a C program to implement queue implementation
#include<stdio.h>
#include<stdlib.h>
#define QSIZE 5

int choice, item, f, r, q[QSIZE];

void insertRear()
{
    if(r == QSIZE - 1)
    {
        printf("Queue overflow\n");
        return;
    }
    r = r + 1;
    q[r] = item;
}

void deleteFront()
{
    if((f > r) || (r == -1))
    {
        printf("Queue underflow\n");
        return;
    }
    printf("Deleted element is %d\n", q[f++]);
    if(f > r)
        f = 0, r = -1;
}

void Qdisplay()
{
    int i;
    if((f > r) || (r == -1))
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are:\n");
    for(i = f; i <= r; i++)
    {
        printf("%d ", q[i]);
    }
    printf("\n");
}

main()
{
    f = 0; r = -1;
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
                insertRear();
                break;
            case 2:
                deleteFront();
                break;
            case 3:
                Qdisplay();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    }
}