//Program to perform push, pop, display operations on stack
#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

int s[SIZE], top;
void push(int item)
{
    if(top == SIZE - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    s[top] = item;
}

int pop()
{
    int item_delete;
    if(top == -1)
    {
        return 0;
    }
    else
    {
        item_delete = s[top--];
    }
    return item_delete;
}

void display()
{
    int i;
    if(top == -1)
    {
        printf("Stack Underflow or Stack Empty\n");
        return;
    }
    printf("Contents of stack are: \n");
    for(int i = 0; i <= top; i++)
    {
        printf("%d\n", s[i]);
    }
}

main()
{
    int item, choice, popItem;
    top = -1;
    for(;;)
    {
        printf("\n1:Push\t2:Pop\t3:display\t4:exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter element to be inserted: ");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                popItem = pop();
                if(popItem == 0)
                {
                    printf("Stack empty\n");
                }
                else
                {
                    printf("Item popped or deleted is %d\n", popItem);
                }
                break;
            case 3:
                display();
                break;
            default:
                exit(0);
        }
    }
}