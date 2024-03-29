//Write a C program to simulate stack and queue using linked list.
//Stack:
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
}*top = NULL;

void push(int value)
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode -> data = value;
    newNode -> link = top;
    top = newNode;
}

void pop()
{
    if(top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    struct node *temp = top;
    printf("Deleted element is %d\n", temp -> data);
    top = temp->link;
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
    while (temp != NULL)
    {
        printf("%d --> ", temp -> data);
        temp = temp -> link;
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