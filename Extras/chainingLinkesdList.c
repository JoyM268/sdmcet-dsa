//Program to implement chaining usinng linked list
#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

typedef struct node{
    int data;
    struct node *next;
} node;

node *chain[SIZE];
void makeNULL()
{
    for(int i = 0; i < SIZE; i++)
    {
        chain[i] = NULL;
    }
} 

node *createNode(int item)
{
    node *temp = (node *)malloc(sizeof(node));
    temp -> data = item;
    temp -> next = NULL;
    return temp;
}

int searchNode(node *head, int item)
{
    if(head == NULL) return 0;
    while(head != NULL)
    {
        if(head -> data == item)
        {
            return 1;
        }
        head = head -> next;
    }
    return 0;
} 

node *insertNode(node *head, int item)
{
    if(searchNode(head, item)) return head;
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

void displayList(node *head)
{
    while(head != NULL)
    {
        printf("%d -> ", head -> data);
        head = head -> next;
    }
    printf("NULL\n");
}

node *deleteNode(node *head, int item)
{
    node *temp1 = NULL, *temp2 = head;
    if(head -> data == item)
    {
        temp1 = head;
        head = head -> next;
        free(temp1);
        return head;
    }
    if(!searchNode(head, item)) return head;
    while(temp2 != NULL)
    {
        if(temp2 -> data == item) break;
        temp1 = head;
        temp2 = temp2 -> next;
    }
    temp1 -> next = temp2 -> next;
    free(temp2);
    return head;
}

void insertInChain(int item)
{
    int index = item % SIZE;
    chain[index] = insertNode(chain[index], item);           
}

void searchInChain(int item)
{
    int index = item % SIZE;
    if(searchNode(chain[index], item))
    {
        printf("%d found\n", item);
        return;
    }
    printf("%d not found\n", item);
}

void deleteInChain(int item)
{
    int index = item % SIZE;
    chain[index] = deleteNode(chain[index], item);
}

void displayChain()
{
    for(int i = 0; i < SIZE; i++)
    {
        displayList(chain[i]);
    }
}

int main()
{
    int choice, item;
    for(;;)
    {
        printf("\n1.Insert\t2.Search\t3.Delete\t4.Display\t5.Exit\n");
        printf("Enter the choice(1, 2, 3, 4, 5): ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter the element: ");
                scanf("%d", &item);
                insertInChain(item);
                break;
            case 2:
                printf("Enter the element: ");
                scanf("%d", &item);
                searchInChain(item);
                break;
            case 3:
                printf("Enter the element: ");
                scanf("%d", &item);
                deleteInChain(item);
                break;
            case 4:
                printf("The contents of the chain are:\n");
                displayChain();
                printf("\n");
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    }
    return 0;
}