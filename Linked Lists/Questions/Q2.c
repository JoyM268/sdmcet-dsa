//Write a c program to reverse the elements of a given linked lists.
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *createNode(int data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp -> data = data;
    temp -> next = NULL;
    return temp;
}

node *insertAtEnd(node *head, int data)
{
    node *temp = createNode(data);
    if(head == NULL) return temp;
    node *cur = head;
    while(cur -> next != NULL)
    {
        cur = cur -> next;
    }
    cur -> next = temp;
    return head;
}

node *reverseList(node *head)
{
    node *rev = NULL, *temp;
    while(head != NULL) 
    {
        temp = head;
        head = head -> next;
        temp -> next = rev;
        rev = temp;
    }
    return rev;
}

void displayList(node *head)
{

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    node *cur = head;
    while(cur != NULL)
    {
        printf("%d --> ", cur -> data);
        cur = cur -> next;
    }
    printf("NULL\n");
}

int main()
{
    node *head = NULL;
    int choice, item;
    for(;;)
    {
        printf("\n1:Insert\t2:Display\t3:Reverse\t4:Exit\n");
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
                displayList(head);
                break;
            case 3:
                head = reverseList(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}