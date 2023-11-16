//program to perform different operations on doubly linked list
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *prev, *next;
}node;

node *createNode(int data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp -> data = data;
    temp -> prev = NULL;
    temp -> next = NULL;
    return temp;
}

node *insertAtStart(node *head, int data)
{
    node *temp = createNode(data);
    if(head == NULL)
    {
        return temp;
    }
    temp -> next = head;
    head -> prev = temp;
    return temp;
}

node *insertAtEnd(node *head, int data)
{
    node *temp1 = createNode(data);
    if(head == NULL)
    {
        return temp1;
    }
    node *temp2 = head;
    while(temp2 -> next != NULL)
    {
        temp2 = temp2 -> next;
    }
    temp2 -> next = temp1;
    temp1 -> prev = temp2; 
    return head;
}

void display(node *head)
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

node *deleteAtStart(node *head)
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    node *curr = head;
    head = head -> next;
    if(head != NULL)
    {
        head -> prev = NULL;
    }
    printf("%d deleted from the list\n", curr -> data);
    free(curr);
    return head;
}

node *deleteAtEnd(node *head)
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return head;
    }
    node *curr = head;
    while(curr -> next != NULL)
    {
        curr = curr -> next;
    }
    if(head == curr)
        head = NULL;
    else
        curr -> prev -> next = NULL;
    printf("%d deleted from the list\n", curr -> data);
    free(curr);
    return head;
}

int main()
{
    node *head = NULL;
    int choice, ele;
    for(;;)
    {
        printf("\n1.Insert at start\t2.Insert at end\t3.Display\t4.Delete from start\t5.Delete from end\t6.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter element to be inserted: ");
                scanf("%d", &ele);
                head = insertAtStart(head, ele);
                break;
            case 2:
                printf("Enter element to be inserted: ");
                scanf("%d", &ele);
                head = insertAtEnd(head, ele);
                break;
            case 3:
                display(head);
                break;
            case 4:
                head = deleteAtStart(head);
                break;
            case 5:
                head = deleteAtEnd(head);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}