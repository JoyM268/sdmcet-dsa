//Various operations on a doubly linked list. (insert, delete, display)
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next, *prev;
}node;

node *createNode(int data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp -> data = data;
    temp -> next = NULL;
    temp -> prev = NULL;
    return temp;
}

node *insertAtBegin(node *head, int item)
{
    node *temp = createNode(item);
    temp -> next = head;
    if(head != NULL)
        head -> prev = temp;
    return temp;
}

node*insertAtEnd(node *head, int item)
{
    node *temp = createNode(item);
    if(head == NULL) return temp;
    node *cur = head;
    while(cur -> next != NULL)
    {
        cur = cur -> next;
    }
    cur -> next = temp;
    temp -> prev = cur;
    return head;
}

node *insertAtPos(node *head, int item)
{
    int pos, count = 1;
    node *temp = createNode(item);
    printf("Enter the position: ");
    scanf("%d", &pos);
    if(head == NULL && pos == 1) return temp;
    node *cur = head;
    while(cur != NULL && cur -> next != NULL && count < pos)
    {
        cur = cur -> next;
        count++;
    }
    if(cur == NULL || (cur -> next == NULL && pos - 1 != count) || pos < 1)
    {
        printf("Invalid position\n");
        return head;
    }
    if(cur -> next == NULL && count == pos - 1)
    {
        cur -> next = temp;
        temp -> prev = cur;
        return head;
    }
    if(head != cur)
        cur -> prev -> next = temp;
    else
        head = temp;
    temp -> next = cur;
    cur -> prev = temp;
    return head;
}

node *deleteAtBegin(node *head)
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return head;
    }
    node *cur = head;
    head = head -> next;
    if(head != NULL)
        head -> prev = NULL;
    printf("Deleted element is %d\n", cur -> data);
    free(cur);
    return head;
}

node *deleteAtEnd(node *head)
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return head;
    }
    node *cur = head;
    while(cur -> next != NULL)
    {
        cur = cur -> next;
    }
    if(head == cur)
        head = NULL;
    else
        cur -> prev -> next = NULL;
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
    int count = 1, pos;
    printf("Enter the position: ");
    scanf("%d", &pos);
    node *cur = head;
    while(cur != NULL && count < pos)
    {
        count++;
        cur = cur -> next;
    }
    if(cur == NULL || pos < 1)
    {
        printf("Invalid position\n");
        return head;
    }
    if(cur == head)
    {
        head = head -> next;
        if(head != NULL)
            head -> prev = NULL;
    }
    else
    {
        cur -> prev -> next = cur -> next;
        if(cur -> next != NULL)
            cur -> next -> prev = cur -> prev;
    }
    printf("Deleted element is %d\n", cur -> data);
    free(cur);
    return head;
}

void displayList(node *head)
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
                displayList(head);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}