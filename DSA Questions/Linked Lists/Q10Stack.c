//Implementation of stack using circular linked list
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
} *top = NULL, *tail = NULL;

void push(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode -> data = value;
    if(top == NULL)
    {
        tail = top = newNode;
        newNode -> next = top;
    }
    else
    {
        tail -> next = newNode;
        newNode -> next = top;
        top = newNode;
    }
}

void pop()
{
    if(top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    struct node *temp = top;
    if(top == tail)
    {
        top = tail = NULL;
    }
    else
    {
        top = top -> next;
        tail -> next = top;
    }
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
    do{
        printf("%d --> ", temp -> data);
        temp = temp -> next;
    }while(temp != top);
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