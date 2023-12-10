//Write a C program to perform different delete operation on circular linked list
#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *link;
} *tail = NULL;


void deleteBeginCLL()
{
    struct node *temp;
    temp = tail -> link;
    if(tail == NULL)
    {
        printf("List is empty\n");
    }
    else if(temp -> link == temp)
    {
        tail = NULL;
        printf("Deleted element %d\n", temp -> info);
        free(temp);
    }
    else
    {
        tail -> link = temp -> link;
        printf("Deleted element %d\n", temp -> info);
        free(temp);
    }
}

void deleteEndCLL()
{
    struct node *cur, *prev;
    if(tail == NULL)
    {
        printf("List is empty\n");
        return;
    }
    cur = tail -> link;
    if(cur -> link == cur)
    {
        tail = NULL;
        printf("Deleted element %d\n", cur -> info);
        free(cur);
    }
    else
    {
        while(cur -> link != tail -> link)
        {
            prev = cur;
            cur = cur -> link;
        }
        prev -> link = tail -> link;
        tail = prev;
        printf("Deleted element %d\n", cur -> info);
        free(cur);
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

void deleteAtPos()
{
    struct node *cur, *nextNode;
    int pos, i = 1, length;
    cur = tail -> link;
    printf("Enter the position: ");
    scanf("%d", &pos);
    length = lengthOfList();
    if(pos < 1 || pos > length)
    {
        printf("Invalid position");
    }
    else if(pos == 1)
    {
        deleteBeginCLL();
    }
    else
    {
        while(i < pos - 1)
        {
            cur = cur -> link;
            i++;
        }
        nextNode = cur -> link;
        if(nextNode == tail)
            tail = cur;
        cur -> link = nextNode -> link;
        printf("Deleted element %d\n", nextNode -> info);
        free(nextNode);
    }
}

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
        printf("\n1.Insert begin\t2.Display\t3.Delete at begin\t4.Delete at end\t5.Delete at position\t6.Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                insertBeginCLL();
                break;
            case 2:
                display();
                break;
            case 3:
                deleteBeginCLL();
                break;
            case 4:
                deleteEndCLL();
                break;
            case 5:
                deleteAtPos();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}