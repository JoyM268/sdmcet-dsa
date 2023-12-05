//Write C program to insert a element at a particular position in circular linked list
#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *link;
} *tail = NULL;

void insertBeginCLL()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the element to be inserted: ");
    scanf("%d", &newNode -> info);
    if(tail == NULL)
    {
        tail = newNode;
        tail -> link = newNode;
        printf("%d -->\n", tail -> info);
    }
    else
    {
        newNode -> link = tail -> link;
        tail -> link = newNode;
        printf("%d -->\n", newNode -> info);
    }
}

int lengthOfList()
{
    if(tail == NULL) return 0;
    struct node *temp = tail -> link;
    int count = 0;
    do{
        count++;
        temp = temp -> link;
    }while(temp != tail -> link);
    return count;
}

void insertAtPosCLL()
{
    struct node *newNode, *temp;
    int pos, i = 1, l;
    printf("Enter the position: ");
    scanf("%d", &pos);
    l = lengthOfList();
    if(pos < 1 || pos > l)
    {
        printf("Invalid position\n");
    }
    else if(pos == 1)
    {
        insertBeginCLL();
    }
    else
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the info: ");
        scanf("%d", &newNode -> info);
        newNode -> link = NULL;
        temp = tail -> link;
        while(i < pos - 1)
        {
            temp = temp -> link;
            i++;
        }
        newNode -> link = temp -> link;
        temp -> link = newNode;
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
        printf("\n1.Insert at begin\t2.Insert at position\t3.Display\t4.Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                insertBeginCLL();
                break;
            case 2:
                insertAtPosCLL();
                break;
            case 3:
                display();
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}