//Write a C program to insert a element before the given element
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

NODE insertBeforeSLL(NODE first, int key, int ele)
{
    NODE cur = first, temp, prev;
    temp = createNode();
    temp -> info = ele;
    while(cur != NULL)
    {
        if(cur -> info == key)
            break;
        prev = cur;
        cur = cur -> link;
    }
    if(cur == NULL)
    {
        printf("Not found\n");
    }
    else
    {
        temp -> link = cur;
        if(cur == first)
            first = temp;
        else
            prev -> link = temp;
    }
    return first;
}

NODE insertRearSLL(NODE first, int ele)
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

int main()
{
    NODE first = NULL;
    int item, choice, key;
    for(;;)
    {
        printf("\n1.Insert at rear\t2.Insert before\t3.Display\t4.Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &item);
                first = insertRearSLL(first, item);
                break;
            case 2:
                printf("Enter the element to be inserted: ");
                scanf("%d", &item);
                printf("Enter the key: ");
                scanf("%d", &key);
                first = insertBeforeSLL(first, key, item);
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