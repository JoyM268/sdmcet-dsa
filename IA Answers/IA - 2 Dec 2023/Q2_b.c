//Write a C function to delete an element in a singly linked list from a given position
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *insertAtEnd(struct node *head, int ele)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp -> data = ele;
    temp -> next = NULL;
    if(head == NULL)
        return temp;
    struct node *cur = head;
    while(cur -> next != NULL)
    {
        cur = cur -> next;
    }
    cur -> next = temp;
    return head;
}

void displayList(struct node *head)
{
    if(head == NULL)
    {
        printf("The list is empty\n");
        return;
    }
    while(head != NULL)
    {
        printf("%d -> ", head -> data);
        head = head -> next;
    }
    printf("NULL\n");
}

//Answer:
struct node *delete(struct node *head)
{
    int pos, count = 1;
    if(head == NULL)
    {
        printf("List is empty\n");
        return head;
    }
    printf("Enter the position: ");
    scanf("%d", &pos);
    struct node *cur = head, *prev;
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
    printf("%d deleted\n", cur -> data);
    free(cur);
    return head;
}

int main()
{
    struct node *head = NULL;
    int choice, item;
    for(;;)
    {   
        printf("\n1:Insert at end\t2:Display List\t3:Delete at position\t4:Exit\n");
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
               head =  delete(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}