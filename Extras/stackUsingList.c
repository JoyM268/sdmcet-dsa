//Implement stack using linked list
#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int data;
    struct node *next; 
} node;

node *createNode(int item)
{
    node *temp = (node *)malloc(sizeof(node));
    temp -> data = item;
    temp -> next = NULL;
    return temp;
}

void push(node **head, int item)
{
    node *temp = createNode(item);
    temp -> next = *head;
    *head = temp;
}

int pop(node **head)
{
    if(*head == NULL)
    {
        printf("Stack underflow\n");
        return -1;
    }
    int item;
    node *temp = *head;
    item = (*head) -> data;
    *head = (*head) -> next;
    free(temp);
    return item;
}

void display(node *head)
{
    while(head != NULL)
    {
        printf("%d ", head -> data);
        head = head -> next;
    }
    printf("\n");
}

main()
{
    node *head = NULL;
    int choice, item;
    while(1)
    {
        printf("\n1:Push\n2:Pop\n3:Display\n4:Exit\n");
        printf("Enter a choice(1, 2, 3, 4): ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter a element: ");
                scanf("%d", &item);
                push(&head, item);
                break;
            case 2:
                item = pop(&head);
                if(item == -1) break;
                printf("Element %d was poped\n", item);
                break;
            case 3:
                display(head);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid Choice\n");
        }
    }
}