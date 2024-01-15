//Write a C program to create an ordered (ascending) linked list for the given set of data.
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

NODE insertOrderedList(NODE first, int ele)
{
    NODE temp = createNode();
    temp -> info = ele;
    temp -> link = NULL;
    if(first == NULL)
    {
        return temp;
    }
    if(ele < first -> info)
    {
        temp -> link = first;
        return temp;
    }
    NODE cur = first, prev = NULL;
    while(cur != NULL && ele > cur -> info)
    {
        prev = cur;
        cur = cur -> link;
    }
    prev -> link = temp;
    temp -> link = cur;
    return first;
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

int main()
{
    NODE first = NULL;
    int choice, item;
    for(;;)
    {
        printf("\n1:Insert\t2:Display\t3:Exit\n");
        printf("Enter the choice(1, 2, 3): ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &item);
                first = insertOrderedList(first, item);
                break;
            case 2:
                display(first);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}