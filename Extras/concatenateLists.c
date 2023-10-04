//Program to concatenate two lists
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} node;

node *createNode(int data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp -> data = data;
    temp -> next = NULL;
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
    return head;
}

node *createList(int n)
{
    node *head = NULL;
    if(n == 0) return head;
    int num;
    printf("Enter %d elements: ", n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        head = insertAtEnd(head, num);
    }
    return head;
}

node *concatenate(node *head1, node *head2)
{
    if(head1 == NULL)
    {
        return head2;
    }
    node *temp = head1;
    while(temp -> next != NULL)
    {
        temp = temp -> next;
    }
    temp -> next = head2;
    return head1;
}

void printList(node *head)
{
    while(head != NULL)
    {
        printf("%d ", head -> data);
        head = head -> next;
    }
    printf("\n");
}

void freeList(node *head)
{
    node *temp;
    while(head != NULL)
    {
        temp = head;
        head = head -> next;
        free(temp);
    }
}

main()
{
    int n1, n2;
    node *head1, *head2;
    printf("Enter the number of elements in list 1: ");
    scanf("%d", &n1);
    head1 = createList(n1);
    printf("Enter the number of elements in list 2: ");
    scanf("%d", &n2);
    head2 = createList(n2);
    head1 = concatenate(head1, head2);
    printf("The contents of concatenated list is: ");
    printList(head1);
    freeList(head1);
}