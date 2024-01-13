// Write a C program to concatenate two singly linked lists and display the result.
#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *link;
};

typedef struct node *NODE;

NODE createNode()
{
    NODE ptr = (NODE)malloc(sizeof(struct node));
    return ptr;
}

NODE insertAtEnd(NODE first, int ele)
{
    NODE temp = createNode();
    temp -> info = ele;
    temp -> link = NULL;
    if(first == NULL)
    {
        return temp;
    }
    else
    {
        NODE cur = first;
        while(cur -> link != NULL)
            cur = cur -> link;
        cur -> link = temp;
        return first;
    }
}

void display(NODE first)
{
    if(first == NULL)
    {
        printf("List is empty\n");
        return;
    }
    else
    {
        NODE cur = first;
        while(cur != NULL)
        {
            printf("%d --> ", cur -> info);
            cur = cur -> link;
        }
        printf("NULL\n");
    }
}

NODE concatenate(NODE first, NODE second)
{
    NODE cur;
    if(first == NULL)
    {
        display(second);
        return second;
    }
    if(second == NULL)
    {
        display(first);
        return first;
    }
    cur = first;
    while(cur -> link != NULL)
    {
        cur = cur -> link;
    }
    cur -> link = second;
    display(first);
    return first;
}

int main()
{
    NODE first = NULL, second = NULL;
    int choice, item;
    for(;;)
    {
        printf("\n1.Insert in list 1\t2.Insert in list 2\t3.Display list 1\t4.Display list 2\t5.Concatenate lists\t6.Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to be inserted: ");
            scanf("%d", &item);
            first = insertAtEnd(first, item);
            break;
        case 2:
            printf("Enter the element to be inserted: ");
            scanf("%d", &item);
            second = insertAtEnd(second, item);
            break;
        case 3:
            display(first);
            break;
        case 4:
            display(second);
            break;
        case 5:
            first = concatenate(first, second);
            second = NULL;
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}