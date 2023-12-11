//Various operations on a singly linked list. (insert, delete, display)
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

node *insertAtBegin(node *head, int item)
{
    node *temp = createNode(item);
    temp -> next = head;
    return temp;
}

node *insertAtEnd(node *head, int item)
{
    node *temp = createNode(item);
    if(head == NULL) return temp;
    node *cur = head;
    while(cur -> next != NULL)
    {
        cur = cur -> next;
    }
    cur -> next = temp;
    return head;
}

node *insertAtPos(node *head, int item)
{
    int pos, count = 1;
    node *prev, *cur = head;
    printf("Enter the position: ");
    scanf("%d", &pos);
    node *temp = createNode(item);
    if(head == NULL && pos == 1)
        return temp;
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
    if(cur == head)
    {
        temp -> next = head;
        head = temp;
    }
    else
    {
        temp -> next = cur;
        prev -> next = temp;
    }
    return head;
}

node *deleteAtBegin(node *head)
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return head;
    }
    node *temp = head;
    head = head -> next;
    printf("Deleted element is %d\n", temp -> data);
    free(temp);   
    return head;
}

node *deleteAtEnd(node *head)
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return head;
    }
    node *cur = head, *prev;
    while(cur -> next != NULL)
    {
        prev = cur;
        cur = cur -> next;
    }
    if(cur == head)
        head = head -> next;
    else
        prev -> next = NULL;
    printf("Deleted element is %d\n", cur -> data);
    free(cur);
    return head;
}

node *deleteAtPos(node *head)
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return head;
    }
    int pos, count = 1;
    printf("Enter the position: ");
    scanf("%d", &pos);
    node *cur = head, *prev;
    while(cur != NULL && count < pos)
    {
        prev = cur;
        cur = cur -> next;
        count++;
    }
    if(pos < 1 || cur == NULL)
    {
        printf("Invalid position\n");
        return head;
    }
    if(cur == head)
        head = head -> next;
    else
        prev -> next = cur -> next;
    printf("Deleted element is %d\n", cur -> data);
    free(cur);
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

int main()
{
    node *head = NULL;
    int item, choice;
    for(;;)
    {
        printf("\n1:Insert At Begin\t2:Insert At End\t3:Insert At Position\t4:Delete At Begin\t5:Delete At End\t6:Delete At Position\t7:Display\t8:Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &item);
                head = insertAtBegin(head, item);
                break;
            case 2:
                printf("Enter the element to be inserted: ");
                scanf("%d", &item);
                head = insertAtEnd(head, item);
                break;
            case 3:
                printf("Enter the element to be inserted: ");
                scanf("%d", &item);
                head = insertAtPos(head, item);
                break;
            case 4:
                head = deleteAtBegin(head);
                break;
            case 5:
                head = deleteAtEnd(head);
                break;
            case 6:
                head = deleteAtPos(head);
                break;
            case 7:
                display(head);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
