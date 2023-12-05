//Various operations on a circular linked list. (insert, delete, display)
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

node *insertAtBegin(node *tail, int item)
{
    node *temp = createNode(item);
    if(tail == NULL)
    {
        temp -> next = temp;
        return temp;
    }
    temp -> next = tail -> next;
    tail -> next = temp;
    return tail;
}

node *insertAtEnd(node *tail, int item)
{
    node *temp = createNode(item);
    if(tail == NULL)
    {
        temp -> next = temp;
        return temp;
    }
    temp -> next = tail -> next;
    tail -> next = temp;
    return temp;
}

int lengthOfList(node *tail)
{
    int count = 0;
    if(tail == NULL) return count;
    node *temp = tail -> next;
    do{
        count++;
        temp = temp -> next;
    }while(temp != tail -> next);
    return count;
}

node *insertAtPos(node *tail, int item)
{
    int pos, count = 1, len;
    printf("Enter the position: ");
    scanf("%d", &pos);
    len = lengthOfList(tail);
    if(pos < 1 || pos > len + 1)
    {
        printf("Invalid position\n");
        return tail;
    }
    node *temp = createNode(item);
    if(pos == 1)
    {
        tail = insertAtBegin(tail, item);
        return tail;
    }
    node *cur = tail -> next;
    while(count < pos - 1)
    {
        count++;
        cur = cur -> next;
    }
    temp -> next = cur -> next;
    cur -> next = temp;
    if(pos == len + 1)
        tail = temp;
    return tail;
}

node *deleteAtBegin(node *tail)
{
    if(tail == NULL)
    {
        printf("List is empty\n");
        return tail;
    }
    node *temp = tail -> next;
    if(temp != tail)
        tail -> next = temp -> next;
    else
        tail = NULL;
    printf("Deleted element is %d\n", temp -> data);
    free(temp);
    return tail;
}

node *deleteAtEnd(node *tail)
{
    if(tail == NULL)
    {
        printf("List is empty\n");
        return tail;
    }
    node *temp = tail -> next;
    while(temp -> next != tail)
    {
        temp = temp -> next;
    }
    temp -> next = tail -> next;
    printf("Deleted element is %d\n", tail -> data);
    free(tail);
    if(temp == tail)
        tail = NULL;
    else
        tail = temp;
    return tail;
}

node *deleteAtPos(node *tail)
{
    int pos, len, i = 1;
    if(tail == NULL)
    {
        printf("List is empty\n");
        return tail;
    }
    printf("Enter the position: ");
    scanf("%d", &pos);
    len = lengthOfList(tail);
    if(pos < 1 || pos > len)
    {
        printf("Invalid position\n");
        return tail;
    }
    if(pos == 1)
    {
        tail = deleteAtBegin(tail);
        return tail;
    }
    node *temp1 = tail -> next, *temp2;
    while(i < pos - 1)
    {
        temp1 = temp1 -> next;
        i++;
    }
    temp2 = temp1 -> next;
    if(temp2 == tail)
        tail = temp1;
    temp1 -> next = temp2 -> next;
    printf("Deleted element is %d\n", temp2 -> data);
    free(temp2);
    return tail;
}

void displayList(node *tail)
{
    if(tail == NULL)
    {
        printf("List is empty\n");
        return;
    }
    node *temp = tail -> next;
    while(temp -> next != tail -> next)
    {
        printf("%d -> ", temp -> data);
        temp = temp -> next;
    }
    printf("%d -> ", temp -> data);
}

int main()
{
    node *tail = NULL;
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
                tail = insertAtBegin(tail, item);
                break;
            case 2:
                printf("Enter the element to be inserted: ");
                scanf("%d", &item);
                tail = insertAtEnd(tail, item);
                break;
            case 3:
                printf("Enter the element to be inserted: ");
                scanf("%d", &item);
                tail = insertAtPos(tail, item);
                break;
                case 4:
                tail = deleteAtBegin(tail);
                break;
            case 5:
                tail = deleteAtEnd(tail);
                break;
            case 6:
                tail = deleteAtPos(tail);
                break;
            case 7:
                displayList(tail);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}