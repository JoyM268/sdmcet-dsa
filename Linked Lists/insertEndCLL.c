//Write a C program to insert a element at the end of circular linked list
#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *link;
} *tail = NULL;

void insertEnd()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the element to be inserted: ");
    scanf("%d", &newNode -> info);
    if(tail == NULL)
    {
        tail = newNode;
        tail -> link = newNode;
        printf("%d\n", tail -> info);
    }
    else
    {
        newNode -> link = tail -> link;
        tail -> link = newNode;
        tail = newNode;
        printf("%d\n", tail -> info);
    }
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
        printf("\n1.Insert end\t2.Display\t3.Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                insertEnd();
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