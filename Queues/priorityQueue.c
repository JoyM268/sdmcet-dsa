//Write a C program to implement priority queue
#include<stdio.h>
#include<stdlib.h>
#define Qsize 5

void pqMinInsert(int item, int q[], int *r)
{
    int j;
    if(*r == Qsize - 1)
    {
        printf("Queue is full\n");
        return;
    }
    j = *r;
    while(j >= 0 && item < q[j])
    {
        q[j + 1] = q[j];
        j--;
    }
    q[j + 1] = item;
    *r = *r + 1;
}

void pqMinDelete(int q[], int *f, int *r)
{
    if(*f > *r)
    {
        printf("Queue underflow\n");
        return;
    }
    printf("Deleted element is %d\n", q[(*f)++]);
    if(*f > *r)
    {
        *f = 0, *r = -1;
    }
}

void display(int q[], int f, int r)
{
    int i;
    if(f > r)
    {
        printf("Queue is empty");
        return;
    }
    printf("Contents of queue are: ");
    for(i = f; i <= r; i++)
    {
        printf("%d ", q[i]);
    }
}

int main()
{
    int q[Qsize], f = 0, r = -1, item, choice;
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
                pqMinInsert(item, q, &r);
                break;
            case 2:
                pqMinDelete(q, &f, &r);
                break;
            case 3:
                display(q, f, r);
                printf("\n");
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    }
    return 0;
}