//Program to pairwise swap elements of a linked list Given a singly linked list of size N. The task is to swap elements in the linked list pairwise.
//For example, if the input list is 1 2 3 4, the resulting list after swaps will be 2 1 4 3.
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} node;

node *createNode(int item)
{
    node *head = (node *)malloc(sizeof(node));
    head -> data = item;
    head -> next = NULL;
    return head;
}

node *insertAtEnd(node *head, int item)
{
    node *temp1 = createNode(item);
    if(head == NULL) return temp1;
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
    printf("Enter %d elements: ", n);
    int item;
    node *head = NULL;
    while(n--)
    {
        scanf("%d", &item);
        head = insertAtEnd(head, item);
    }
    return head;
}

node *pairwiseSwap(node *head)
{
    node *node1, *node2, *prev = NULL, *temp;
    if(head -> next == NULL) return head;
    do{
        if(prev == NULL)
        {
            node1 = head;
            node2 = head -> next;
            head = node2;
        }
        else
        {
            node1 = node1 -> next -> next;
            node2 = node2 -> next -> next;
            prev -> next = node2;
        }
        node1 -> next = node2 -> next;
        node2 -> next = node1;
        temp = node1;
        node1 = node2;
        node2 = temp;
        prev = node2;
    } while(node2 -> next != NULL && node2 -> next -> next != NULL);
    return head;
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
    node *head;
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    head = createList(n);
    printf("List before pairwise swap:\n");
    display(head);
    printf("List after pairwise swap:\n");
    head = pairwiseSwap(head);
    display(head);
    return 0;
}