//Program to find middle node of a singly linked list
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
}

node *insertAtEnd(node *head, int item)
{
    node *temp1 = createNode(item);
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

node *middleNode(node *head)
{
    node *slow = head, *fast = head;
    while(fast -> next != NULL && fast -> next -> next != NULL)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
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
    node *head;
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    head = createList(n);
    node *mid = middleNode(head);
    printf("The content of the middle node is: %d\n", mid -> data);
    freeList(head);
}