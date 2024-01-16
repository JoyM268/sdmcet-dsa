//Write a c program to insert an element at a given position of the linked list.
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}*NODE;

NODE createNode()
{
    NODE temp = (NODE)malloc(sizeof(struct node));
    return temp;
}

NODE insertAtPos(NODE head, int data)
{
    int pos, count = 1;
    printf("Enter the position: ");
    scanf("%d", &pos);
    NODE temp = createNode();
    temp -> data = data;
    temp -> next = NULL;
    if(pos == 1 && head == NULL)
        return temp;
    NODE cur = head, prev;
    while(cur != NULL && count < pos)
    {
        count++;
        prev = cur;
        cur = cur -> next;
    }
    if((cur == NULL && pos != count) || pos < 1)
    {
        printf("Invalid position\n");
        return head;
    }
    temp -> next = cur;
    if(cur == head)
        return temp;
    prev -> next = temp;
    return head;
}

NODE insertAtEnd(NODE head, int data)
{
    NODE temp = createNode();
    temp -> data = data;
    temp -> next = NULL;
    if(head == NULL)
        return temp;
    NODE cur = head;
    while(cur -> next != NULL)
        cur = cur -> next;
    cur -> next = temp;
    return head;   
}

void display(NODE head)
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while(head != NULL)
    {
        printf("%d -> ", head -> data);
        head = head -> next;
    }
    printf("NULL\n");
}

int main()
{
    NODE head = NULL;
    int choice, item;
    for(;;)
    {
        printf("\n1.Insert at end\t2.Insert at position\t3.Display\t4.Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &item);
                head = insertAtEnd(head, item);
                break;
            case 2:
                printf("Enter the element to be inserted: ");
                scanf("%d", &item);
                head = insertAtPos(head, item);
                break;
            case 3:
                display(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");    
        }
    }
    return 0;
}