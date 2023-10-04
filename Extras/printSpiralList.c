//Program to print elements in the linked list in a spiral order
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} node;

node *createNode(int data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp -> next = NULL;
    temp -> data = data;
    return temp;
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

node *reverse(node *head, node *mid)
{
    node *prev = mid;
    node *curr = head;
    node *end;
    while(curr != mid)
    {
        end = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = end;
    }

    return prev;
}

void printSpiral(node *head)
{
    node *mid = middleNode(head);
    mid = mid -> next;
    head = reverse(head, mid);
    node *temp1 = head, *temp2 = mid;
    while(temp1 != mid)
    {
        printf("%d ", temp1 -> data);
        if(temp2 != NULL) 
        {
            printf("%d ", temp2 -> data);
            temp2 = temp2 -> next;
        }
        temp1 = temp1 -> next;
    }
    head = reverse(head, mid);
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
    node *head = NULL;
    int i, n, num;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &num);
        head = insertAtEnd(head, num);
    }
    printf("The contents of the list in spiral order are: ");
    printSpiral(head);
    printf("\n\n");
    freeList(head);
}