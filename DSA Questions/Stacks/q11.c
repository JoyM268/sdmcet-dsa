/* Write C functions for the following operations of stack. 
i. Push()   ii. Pop()   iii. Peek() */
#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

int stack[SIZE], top = -1;
void push(int item)
{
    if(top == SIZE - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = item;
}

int pop()
{
    if(top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

int peek()
{
    if(top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top];
}

void display()
{
    if(top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }
    int i;
    for(i = 0; i <= top; i++)
        printf("%d ", stack[i]);
    printf("\n");
}

int main()
{
    int choice, item, popItem, topItem;
    for(;;)
    {
        printf("\n1.Push\t2.Pop\t3.Peek\t4.Display\t5.Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                popItem = pop();
                if(popItem != -1)
                    printf("Element %d deleted from the stack\n", popItem);
                break;
            case 3:
                topItem = peek();
                if(topItem != -1)
                    printf("%d is the element at the top of stack\n", topItem);
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
    return 0;
}