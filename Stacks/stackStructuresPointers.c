//Program to perform push, pop, display operations on stack using structures and pointers
#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

struct stack{
    int stk[SIZE], top;
};

void pushstk(struct stack *s, int ele)
{
    if(s -> top == SIZE - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    s -> stk[++(s -> top)] = ele;
}

int popstk(struct stack *s)
{
    if(s -> top == -1)
    {
        return 0;
    }
    return s -> stk[(s -> top)--];
}

void display(struct stack s)
{
    int i;
    if(s.top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    for(i = 0; i <= s.top; i++)
    {
        printf("stk[%d] = %d\n", i, s.stk[i]);
    }
}

main()
{
    int choice, ele, popElement;
    struct stack s;
    s.top = -1;
    for(;;)
    {
        printf("\n1:Push\n2:Pop\n3:Display\n4:Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &ele);
                pushstk(&s, ele);
                break;
            case 2:
                popElement = popstk(&s);
                if(popElement == 0)
                {
                    printf("No element to pop\n");
                }
                else
                {
                    printf("Element popped is %d\n", popElement);
                }
                break;
            case 3:
                display(s);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid Choice\n");
        }
    }
}