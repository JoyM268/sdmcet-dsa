//Implementation of queues using doubly linked list.
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev, *next;
} *front = NULL, *rear = NULL;

void insertQLL(int value)
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode -> data = value;
    newNode -> next = NULL;
    newNode -> prev = NULL;
    if(front == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear -> next = newNode;
        newNode -> prev = rear;
        rear = newNode;
    }
}

void deleteQLL()
{
    if(front == NULL)
    {
        printf("The queue is empty\n");
    }
    else
    {
        struct node *temp = front;
        front = front -> next;
        if(front != NULL)
            front -> prev = NULL;
        printf("Deleted element is %d\n", temp -> data);
        free(temp);
    }
}

void display()
{
    if(front == NULL)
    {
        printf("The queue is empty\n");
    }
    else
    {
        struct node *temp = front;
        while(temp != NULL)
        {
            printf("%d --> ", temp -> data);
            temp = temp -> next;
        }
        printf("NULL\n");
    }
}

int main()
{
    int choice, item;
    for(;;)
    {
        printf("\n1.Insert\t2.Delete\t3.Display\t4.Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &item);
                insertQLL(item);
                break;
            case 2:
                deleteQLL();
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
