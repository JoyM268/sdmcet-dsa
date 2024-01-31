// Write a c program to reverse the elements of a given linked lists.
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node *NODE;

NODE createNode(int data)
{
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp -> data = data;
    temp -> next = NULL;
    return temp;
}

NODE insertAtEnd(NODE head, int data)
{
    NODE temp = createNode(data);
    if(head == NULL)
        return temp;
    NODE cur = head;
    while(cur -> next != NULL)
    {
        cur = cur -> next;
    }
    cur -> next = temp;
    return head;
}

NODE reverseList(NODE head)
{
    NODE rev = NULL, temp;
    while(head != NULL)
    {
        temp = head;
        head = head -> next;
        temp -> next = rev;
        rev = temp;
    }
    return rev;
}

void displayList(NODE head)
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    NODE cur = head;
    while(cur != NULL)
    {
        printf("%d - ->  ", cur -> data);
        cur = cur -> next;
    }
    printf("NULL\n");
}

int main()
{
    NODE head = NULL;
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