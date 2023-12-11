//Implementation of stack using doubly linked list.
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev, *next;
} *top = NULL;

void push(int value)
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode -> data = value;
    newNode -> prev = NULL;
    newNode -> next = top;
    if(top != NULL)
        top -> prev = newNode;
    top = newNode;
}

void pop()
{
    if(top == NULL)
    {
        printf("Stack is empty\n");
    }
    struct node *temp = top;
    top = top -> next;
    if(top != NULL)
        top -> prev = NULL;
    printf("Deleted element is %d\n", temp -> data);
    free(temp);
}

void display()
{
    if(top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    struct node *temp = top;
    while(temp != NULL)
    {
        printf("%d --> ", temp -> data);
        temp = temp -> next;
    }
    printf("NULL\n");
}

int main()
{
    int choice, item;
    for(;;)
    {
        printf("\n1.Push\t2.Pop\t3.Display\t4.Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0); 
            default:
                printf("Invalid Choice\n");
        }
    }
    return 0;
}
