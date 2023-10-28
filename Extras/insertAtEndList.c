//Program to insert element at the end of linked list
#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *link;
};
typedef struct node *NODE;

NODE createNode(int x)
{
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp -> info = x;
    temp -> link = NULL;
};

NODE insertAtEnd(NODE head, int x)
{
    NODE temp1 = createNode(x);
    if(head == NULL)
    {
        return temp1;
    }
    NODE temp2 = head;
    while(temp2 -> link != NULL)
    {
        temp2 = temp2 -> link;
    }
    temp2 -> link = temp1;
    return head; 
}

void display(NODE head)
{
    if(!head) return;
    printf("The contents of the list are: ");
    while(head != NULL)
    {
        printf("%d ", head -> info);
        head = head -> link;
    }
    printf("\n");
}

int main()
{
    NODE head = NULL;
    int choice, item;
    for(;;)
    {
        printf("\n1:Insert\t2:Display\t3:Exit\n");
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
                display(head);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
