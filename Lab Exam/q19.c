//Write a c program to delete an element from the given position of the linked list.
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    struct node *next;
    int data;
}*NODE;

NODE createNode()
{
    NODE temp = (NODE)malloc(sizeof(struct node));
    return temp;
}

NODE insertAtEnd(NODE head, int item)
{
    NODE temp = createNode();
    temp -> data = item;
    temp -> next = NULL;
    if(head == NULL) return temp;
    NODE cur = head;
    while(cur -> next != NULL)
    {
        cur = cur -> next;
    }
    cur -> next = temp;
    return head;
}

NODE deleteAtPos(NODE head)
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return head;
    }
    NODE prev, cur = head;
    int count = 1, pos;
    printf("Enter the position: ");
    scanf("%d", &pos);
    while(cur != NULL && count < pos)
    {
        prev = cur;
        cur = cur -> next;
        count++;
    }
    if(cur == NULL || pos < 1)
    {
        printf("Invalid position\n");
        return head;
    }
    if(cur == head)
        head = head -> next;
    else
        prev -> next = cur -> next;
    printf("%d deleted from position %d in the list\n", cur -> data, pos);
    free(cur);
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
    int item, choice;
    for(;;)
    {
        printf("\n1.Insert at end\t2.Delete at position\t3.Display list\t4.Exit\n");
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
                head = deleteAtPos(head);
                break;
            case 3:
                display(head);
                break;
            case 4:
                exit(0);
            default:
                printf("invalid choice\n");
        }
    }
    return 0;
}