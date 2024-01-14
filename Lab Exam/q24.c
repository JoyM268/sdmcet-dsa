/* Write a c program to perform following operations using doubly linked list. 
i. Insert at front 
ii. Delete at front */
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    struct node *prev, *next;
    int data;
}*NODE;

NODE createNode()
{
    NODE temp = (NODE)malloc(sizeof(struct node));
    return temp;
}

NODE insertAtFront(NODE head, int item)
{
    NODE temp = createNode();
    temp -> data = item;
    temp -> prev = NULL;
    temp -> next = head;
    if(head != NULL)
        head -> prev = temp;
    return temp;
}

NODE deleteAtFront(NODE head)
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return head;
    }
    NODE temp = head -> next;
    if(temp != NULL)
        temp -> prev = NULL;
    printf("Element %d deleted from the list\n", head -> data);
    free(head);
    return temp;
}

void display(NODE head)
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    NODE temp = head;
    while(temp != NULL)
    {
        printf("%d -> ", temp -> data);
        temp = temp -> next;
    }
    printf("NULL\n");
}

int main()
{
    int choice, item;
    NODE head = NULL;
    for(;;)
    {
        printf("\n1.Insert at front\t2.Delete at front\t3.Display\t4.Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &item);
                head = insertAtFront(head, item);
                break;
            case 2:
                head = deleteAtFront(head);
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