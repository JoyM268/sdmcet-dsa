//Program to reverse a linked list
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
node *readElements(int n)
{
    node *head = NULL;
    int num;
    printf("Enter %d elemets: ", n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        head = insertAtEnd(head, num);
    }
    return head;
}

node *reverseList(node *head)
{
    node *curr = head, *prev = NULL, *end;
    while(curr != NULL)
    {
        end = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = end;
    }
    return prev;
}

void displayList(node *head)
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
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    node *head = readElements(n);
    printf("The elements before reverse:\n");
    displayList(head);
    head = reverseList(head);
    printf("\nThe elements after reverse:\n");
    displayList(head);
    return 0;
}
