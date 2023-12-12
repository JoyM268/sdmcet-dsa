// C program to combine 2 ordered lists into a singly linked list.
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node *NODE;

NODE createNode(int data)
{
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp -> next = NULL;
    temp -> data = data;
    return temp;
}

NODE insertOrdered(NODE head, int data)
{
    NODE temp = createNode(data);
    if (head == NULL)
        return temp;
    NODE cur = head;
    if (head -> data > data)
    { 
        temp -> next = head;
        return temp;
    }
    while (cur -> next != NULL && cur -> next -> data < data)
    {
        cur = cur->next;
    }
    temp -> next = cur -> next;
    cur -> next = temp;
    return head;
}

NODE mergeList(NODE head1, NODE head2)
{
    if(head1 == NULL)
        return head2;
    if(head2 == NULL)
        return head1;
    NODE temp;
    if(head1 -> data <= head2 -> data)
    {
        temp = head1;
        temp -> next = mergeList(head1 -> next, head2);
    }
    else
    {
        temp = head2;
        temp -> next = mergeList(head1, head2 -> next);
    }
    return temp;
}

void displayList(NODE head)
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while(head != NULL)
    {
        printf("%d -> ", head -> data);
        head = head -> next;
    }
    printf("NULL\n");
}

int main()
{
    NODE head1 = NULL, head2 = NULL;
    int item, choice;
    for(;;)
    {
        printf("\n1.Insert in list 1\t2.Insert in list 2\t3.Display List 1\t4.Display list 2\t5.Merge List\t6.Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &item);
                head1 = insertOrdered(head1, item);
                break;
            case 2:
                printf("Enter the element to be inserted: ");
                scanf("%d", &item);
                head2 = insertOrdered(head2, item);
                break;
            case 3:
                displayList(head1);
                break;
            case 4:
                displayList(head2);
                break;
            case 5:
                head1 = mergeList(head1, head2);
                printf("The merged list is:\n");
                displayList(head1);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    }
}

// Method 2
/*
void swap(NODE *head1, NODE *head2)
{
    NODE temp = *head1;
    *head1 = *head2;
    *head2 = temp;
}

NODE mergeList(NODE head1, NODE head2)
{
    if (head1 -> data > head2 -> data) swap(&head1, &head2);
    NODE newHead = head1;
    while (head1 != NULL && head2 != NULL)
    {
        NODE temp = NULL;
        while (head1 != NULL && head1 -> data <= head2 -> data)
        {
        temp = head1;
        head1 = head1 -> next;
        }
        temp -> next = head2;
        swap(&head1, &head2);
    }
    return newHead;
}
*/