/* Show how to implement a stack of integers in C by using an array int s[stacksize] where s[0] is used to contain the index of the top element of the stack
and s[1] through s[stacksize-1] contain the elements on the stack. Write C declaration and functions push(), pop() and empty() for this implementation. */
#include<stdio.h>
#include<stdlib.h>
#define stackSize 5

int s[stackSize] = {0};
int empty()
{
    if(!s[0]) return 1;
    return 0;
}

void push(int item)
{
    if(s[0] == stackSize - 1)
    {
        printf("Stack overflow\n");
        return;
    }  
    s[++s[0]] = item;
}

int pop()
{
    if(empty())
    {
        printf("Stack underflow\n");
        return -1;
    }
    return s[s[0]--];
}

void display()
{
    if(empty())
    {
        printf("Stack underflow\n");
        return;
    }
    int i;
    for(i = 1; i <= s[0]; i++)
        printf("%d ", s[i]);
    printf("\n");
}

int main()
{
    int item, choice, popItem;
    for(;;)
    {
        printf("\n1:Push\t2:Pop\t3:display\t4.Check empty\t5:exit\n");
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
                if(popItem != -1)
                    printf("%d deleted from the stack\n", popItem);
                break;
            case 3:
                display();
                break;
            case 4:
                if(empty())
                    printf("Stack is empty\n");
                else
                    printf("Stack is not empty\n");
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}