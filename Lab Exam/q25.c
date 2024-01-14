/* Show how to implement a queue of integers using an array q[10], where q[0] is used to indicate the front of the queue, q[1] is used to indicate its rear and
q[2] through q[9] are used to contain queue elements. Also, show how to initialize such an array to represent empty queue and write routines dequeue, enqueue 
and empty for such an implementation. */ 
#include<stdio.h>
#include<stdlib.h>

int q[10] = {2, 1};
int empty()
{
    return (q[0] > q[1] || q[1] == 1);
}

void enqueue(int item)
{
    if(q[1] == 9)
    {
        printf("Queue is full\n");
        return;
    }
    q[++q[1]] = item;
}

void dequeue()
{
    if(empty())
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Element %d deleted from the queue\n", q[q[0]++]);
    if(q[0] > q[1])
        q[0] = 2, q[1] = 1;
}

void display()
{
    if(empty())
    {
        printf("Queue is empty\n");
        return;
    }
    int i;
    for(i = q[0]; i <= q[1]; i++)
    {
        printf("%d ", q[i]);
    }
    printf("\n");
}

int main()
{
    int item, choice;
    for(;;)
    {
        printf("\n1.Insert at rear\t2.Delete at front\t3.Display queue\t4.Check empty\t5.Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter item to be inserted: ");
                scanf("%d", &item);
                enqueue(item);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                if(empty())
                    printf("Queue is empty\n");
                else
                    printf("Queue is not empty\n");
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    }
    return 0;
}