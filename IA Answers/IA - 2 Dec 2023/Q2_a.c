//Write a C function sumlist(struct node *) which returns the sum of integers in a given list 
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *insertAtEnd(struct node *head, int ele)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp -> data = ele;
    temp -> next = NULL;
    if(head == NULL)
        return temp;
    struct node *cur = head;
    while(cur -> next != NULL)
    {
        cur = cur -> next;
    }
    cur -> next = temp;
    return head;
}

void displayList(struct node *head)
{
    if(head == NULL)
    {
        printf("The list is empty\n");
        return;
    }
    while(head != NULL)
    {
        printf("%d -> ", head -> data);
        head = head -> next;
    }
    printf("NULL\n");
}

//Answer:
int sumlist(struct node *head)
{
    int sum = 0;
    while(head != NULL)
    {
        sum += head -> data;
        head = head -> next;
    }
    return sum;
}

int main()
{
    struct node *head = NULL;
    int choice, item;
    for(;;)
    {   
        printf("\n1:Insert at end\t2:Display List\t3:Sum list\t4:Exit\n");
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
                displayList(head);
                break;
            case 3:
                printf("The sum of all integers in list is %d\n", sumlist(head));
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}