//Program to make a second copy of a list.
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
        {
            cur = cur -> link;
        }
        cur -> link = temp;
        return first;
    }
}

void displayList(NODE List)
{
    if(List == NULL)
    {
        printf("List is empty\n");
        return;
    }
    else
    {
        NODE cur = List;
        while(cur != NULL)
        {
            printf("%d --> ", cur -> info);
            cur = cur -> link;
        }
        printf("NULL\n");
    }
}

NODE createCopy(NODE first)
{
    NODE copy = NULL;
    while(first != NULL)
    {
        copy = insertAtEnd(copy, first -> info);
        first = first -> link;
    }
    return copy;
}

int main()
{
    NODE first = NULL, copy;
    int choice, item;
    for(;;)
    {
        printf("\n1:Insert in list\t2:Display list\t3:Create copy\t4:Exit\n");
        printf("Enter the choice(1, 2, 3, 4): ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &item);
                first = insertAtEnd(first, item);
                break;
            case 2:
                displayList(first);
                break;
            case 3:
                copy = createCopy(first);
                printf("The copy of the list is:\n");
                displayList(copy);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}