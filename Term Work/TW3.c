/* Write a C program to implement the following on circular queue:  
i. insert() 
ii. delete()  
iii. display() */
#include<stdio.h>
#include<stdlib.h>
#define Qsize 5

int queue[Qsize], f = 0, r = -1, count = 0;

void insert(int item)
{
    if(count == Qsize)
    {
        printf("Queue overflow\n");
        return;
    }
    r = (r + 1) % Qsize;
    queue[r] = item;
    count++;
}

void delete()
{
    if(count == 0)
    {
        printf("Queue underflow\n");
        return;
    }
    printf("The deleted element is: %d\n", queue[f]);
    f = (f + 1) % Qsize;
    count--;
}

void display()
{
    int i, temp = f;
    if(count == 0)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Contents of queue are:\n");
    for(i = 1; i <= count; i++)
    {
        printf("%d\t%d\n", temp, queue[temp]);
        temp = (temp + 1) % Qsize;
    }
}

int main()
{
    int item, choice;
    for(;;)
    {
        printf("\n1:Insert@Rear\t2:Delete@Front\t3:Display\t4:Exit\n");
        printf("Enter the choice(1, 2, 3, 4): ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter item to be inserted: ");
                scanf("%d", &item);
                insert(item);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}