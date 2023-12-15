//Write a C function, append(struct node *list1, struct node *list2) to concatenate two doubly linked lists and show the appended list2 to list1
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next, *prev;
};

struct node *insertAtEnd(struct node *head, int ele)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp -> data = ele;
    temp -> next = NULL;
    temp -> prev = NULL;
    if(head == NULL)
        return temp;
    struct node *cur = head;
    while(cur -> next != NULL)
    {
        cur = cur -> next;
    }
    cur -> next = temp;
    temp -> prev = cur;
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
struct node *append(struct node *list1, struct node *list2)
{
    if(list1 == NULL)
    {
        displayList(list2);
        return list2;
    }
    if(list2 == NULL)
    {
        displayList(list1);
        return list1;
    }
    struct node *temp = list1;
    while(temp -> next != NULL)
    {
        temp = temp -> next;
    }
    temp -> next = list2;
    list2 -> prev = temp;
    displayList(list1);
    return list1;
}

int main()
{
    struct node *list1 = NULL, *list2 = NULL;
    int choice, item;
    for(;;)
    {   
        printf("\n1:Insert in list1\t2:Insert in List 2\t3:Display List 1\t4:Display List 2\t5:Concatenate lists\t6:Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &item);
                list1 = insertAtEnd(list1, item);
                break;
            case 2:
                printf("Enter the element to be inserted: ");
                scanf("%d", &item);
                list2 = insertAtEnd(list2, item);
                break;
            case 3:
                displayList(list1);
                break;
            case 4:
                displayList(list2);
                break;
            case 5:
                list1 = append(list1, list2);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}