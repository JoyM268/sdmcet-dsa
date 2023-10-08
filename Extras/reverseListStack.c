//Program to reverse a linked list using stack
#include<stdio.h>
#include<stdlib.h>
#define SIZE 50

typedef struct node{
    int data;
    struct node *next;
} node;

typedef struct{
    int stk[SIZE], top;
} stack;

node *createNode(int data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp -> next = NULL;
    temp -> data = data;
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
    int item;
    node *head = NULL;
    printf("Enter %d elements: ", n);
    while(n--)
    {
        scanf("%d", &item);
        head = insertAtEnd(head, item);
    }
    return head;
}

void push(stack *s, int item)
{
    s -> stk[++s -> top] = item;
}

int pop(stack *s)
{
    return s -> stk[s -> top--];
}

void reverseList(node *head)
{
    stack s;
    s.top = -1;
    node *temp = head;
    while(temp != NULL)
    {
        push(&s, temp -> data);
        temp = temp -> next;
    }
    while(head != NULL)
    {
        head -> data = pop(&s);
        head = head -> next;
    }
}

void display(node *head)
{
    while(head != NULL)
    {
        printf("%d -> ", head -> data);
        head = head -> next;
    }
    printf("NULL\n");
}

int main()
{
    int n;
    node *head = NULL;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    head = createList(n);
    printf("The list before reverse:\n");
    display(head);
    printf("The list after reverse:\n");
    reverseList(head);
    display(head);
    return 0;
}