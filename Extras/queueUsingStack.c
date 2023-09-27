//Program to implement queue using stack
#include<stdio.h>
#define SIZE 50

typedef struct{
    int stk[SIZE], top;
}stack;

void push(stack *s, int item)
{
    s -> stk[++s -> top] = item;
}

int pop(stack *s)
{
    return s -> stk[s -> top--];
}

void display(stack *s)
{
    if(s -> top == -1)
    {
        printf("Queue is empty");
        return;
    }
    int i;
    printf("Elements in the queue: ");
    for(i = 0; i <= s -> top; i++)
    {
        printf("%d ", s -> stk[i]);
    }
    printf("\n");
}

void enqueue(stack *s1, int item)
{
    if(s1 -> top == SIZE - 1)
    {
        printf("Queue is full\n");
        return;
    }
    push(s1, item);
}

int dequeue(stack *s1)
{
    if(s1 -> top == -1)
    {
        printf("Queue is empty\n");
        return -1;
    }
    int temp, item;
    stack s2;
    s2.top = -1;
    while(s1 -> top != -1)
    {
        temp = pop(s1);
        push(&s2, temp);
    }
    item = pop(&s2);
    while(s2.top != -1)
    {
        temp = pop(&s2);
        push(s1, temp);
    }
    return item;
}

main()
{
    stack s;
    s.top = -1;
    int item, choice;
    do{
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter a choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter a element: ");
                scanf("%d", &item);
                enqueue(&s, item);
                break;
            case 2:
                item = dequeue(&s);
                if(item == -1) break;
                printf("Element %d was poped\n", item);
                break;
            case 3:
                display(&s);
                break;
            case 4:
                break;
            default:
                printf("Invalid choice\n");               
        }
    } while(choice != 4);
}