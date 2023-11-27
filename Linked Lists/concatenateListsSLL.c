//Write a C program to concatenate two singly linked list
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

NODE insertFront(NODE first, int ele)
{
    NODE temp = createNode();
    temp -> info = ele;
    printf("Info = %d\n", temp -> info);
    temp -> link = first;
    return temp;
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
        return second;
    }
    if(second == NULL)
    {
        return first;
    }
    cur = first;
    while(cur -> link != NULL)
    {
        cur = cur -> link;
    }
    cur -> link = second;
    return first;
}

int main()
{
    NODE first = NULL, second = NULL;
    int choice, item;
    for(;;)
    {
        printf("\n1.Insert in first\t2.Insert in second\t3.Display first\t4.Display second\t5.Concatenate lists\t6.Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to be inserted: ");
            scanf("%d", &item);
            first = insertFront(first, item);
            break;
        case 2:
            printf("Enter the element to be inserted: ");
            scanf("%d", &item);
            second = insertFront(second, item);
            break;
        case 3:
            display(first);
            break;
        case 4:
            display(second);
            break;
        case 5:
            first = concatenate(first, second);
            printf("The concatenated list is:\n");
            display(first);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}