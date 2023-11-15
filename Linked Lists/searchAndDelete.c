//Write a C program to search and delete a element from linked list
//Write a C program to find the length of the linked list
#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *link;
};

typedef struct node *NODE;

NODE searchAndDelete(NODE first, int key)
{
    NODE cur = first, prev = NULL;
    if(first -> link == NULL && first -> info == key)
    {
        printf("%d deleted from the list\n", first -> info);
        free(cur);
        return NULL;
    }
    if(key == first -> info)
    {
        printf("%d deleted from the list\n", first -> info);
        first = first -> link;
        free(cur);
        return first;
    }
    while(cur != NULL)
    {
        if(cur -> info == key)
        {
            prev -> link = cur -> link;
            printf("%d deleted from the list\n", cur -> info);
            free(cur);
            return first;
        }
        else
        {
            prev = cur;
            cur = cur -> link;
        }
    }
    if(cur == NULL)
    {
        printf("%d not found\n", key);
        return first;
    }
}

NODE createNode()
{
    NODE ptr = (NODE)malloc(sizeof(struct node));
    return ptr;
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
    int item, choice;
    for(;;)
    {
        printf("\n1.Insert at rear\t2.Search and delete\t3.Display\t4.Exit\n");
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
                printf("Enter the element to be deleted: ");
                scanf("%d", &item);
                first = searchAndDelete(first, item);
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