//Program to bubble sort a linked list
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *createNode(int data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp -> next = NULL;
    temp -> data = data;
    return temp;
}

node *insertElement(node *head, int data)
{
    node *temp = createNode(data);
    if(head == NULL) return temp;
    node *curr = head;
    while(curr -> next != NULL)
    {
        curr = curr -> next;
    }
    curr -> next = temp;
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

void swap(node **a, node **b)
{
    int temp = (*a) -> data;
    (*a) -> data = (*b) -> data;
    (*b) -> data = temp;
}

void bubbleSort(node *head)
{
    if(!head) return;
    node *last = NULL, *first;
    int swapped;
    do
    {
        first = head;
        swapped = 0;
        while(first -> next != last)
        {
            if(first -> data > first -> next -> data)
            {
                swap(&first, &first -> next);
                swapped = 1;
            }
            first = first -> next;
        }
        last = first;
    } while(swapped);    
}

int main()
{
    node *head = NULL;
    int item, choice;
    for(;;)
    {
        printf("\n1.Insert\t2.Display\t3.Sort\t4.Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &item);
                head = insertElement(head, item);
                break;
            case 2:
                display(head);
                break;
            case 3:
                bubbleSort(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}