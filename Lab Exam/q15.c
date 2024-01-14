//Write a C program to search an element in the list and print the position of the element if found otherwise add the element to the list.
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
        return temp;
    NODE cur = first;
    while(cur -> link != NULL)
    {
        cur = cur -> link;
    }
    cur -> link = temp;
    return first;
}

NODE searchElement(NODE first, int ele)
{
    NODE temp = first;
    int pos = 1;
    while(temp != NULL && temp -> info != ele)
    {
        temp = temp -> link;
        pos++;
    }
    if(temp == NULL)
    {
        printf("Element %d not found in list\n", ele);
        first = insertAtEnd(first, ele);
        printf("Element %d inserted into the list\n", ele);
    }
    else
    {
        printf("Element %d found at position %d\n", ele, pos);
    }
    return first;
}

void display(NODE first)
{
    if(first == NULL)
    {
        printf("List is empty\n");
        return;
    }
    NODE cur = first;
    while(cur != NULL)
    {
        printf("%d --> ", cur -> info);
        cur = cur -> link;
    }
    printf("NULL\n");
}

int main()
{
    NODE first = NULL;
    int item, choice;
    for(;;)
    {
        printf("\n1.Insert\t2.Search\t3.Display\t4.Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &item);
                first = insertAtEnd(first, item);
                break;
            case 2:
                printf("Enter the element to be searched: ");
                scanf("%d", &item);
                first = searchElement(first, item);
                break;
            case 3:
                display(first);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}