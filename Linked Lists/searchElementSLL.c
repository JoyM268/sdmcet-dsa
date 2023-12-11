//Write a C program to search an element in the linked list if not found insert the element into the list
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

NODE insertRear(NODE first, int ele)
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
        while (cur->link != NULL)
        {
            cur = cur->link;
        }
        cur->link = temp;
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

NODE search(NODE first, int key)
{
    int pos = 0;
    NODE cur = first;
    while(cur != NULL)
    {
        pos++;
        if(cur -> info == key)
        {
            printf("Key %d found at position %d\n", key, pos);
            return first;
        }
        else
        {
            cur = cur -> link;
        }
        if(cur == NULL)
        {
            printf("Key not found\n");
            first = insertRear(first, key);
            return first;
        }
    }
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
                first = insertRear(first, item);
                break;
            case 2:
                printf("Enter the key to be searched: ");
                scanf("%d", &item);
                first = search(first, item);
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