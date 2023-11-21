//Write a C program to create a singly circular linked list
#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *link;
} *head, *tail;

void createCLL()
{
    struct node *newNode;
    int choice = 1;
    head = NULL;
    while(choice == 1)
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d", &newNode -> info);
        newNode -> link = NULL;
        if(head == NULL)
        {
            head = tail = newNode;
            tail -> link = head;
        }
        else
        {
            tail -> link = newNode;
            tail = newNode;
            tail -> link = head;
        }
        printf("Enter 1 to continue and 2 to exit\n");
        scanf("%d", &choice);
    }
    printf("%d\n", tail -> link -> info);
}

void display()
{
    struct node *temp;
    if(tail == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        temp = tail -> link;
        while(temp -> link != tail -> link)
        {
            printf("%d --> ", temp -> info);
            temp = temp -> link;
        }
        printf("%d -->\n", temp -> info);
    }
}

int main()
{
    int choice;
    for(;;)
    {
        printf("\n1.Create circular list\t2.Display\t3.Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                createCLL();
                break;
            case 2:
                display();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}