//Program to remove the duplicate element of the list
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

void displayList(NODE first)
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

NODE removeDuplicate(NODE first)
{
    NODE temp1 = first, temp2, prev;
    while(temp1 != NULL)
    {
        temp2 = temp1 -> link;
        prev = temp1;
        while(temp2 != NULL)
        {
            if(temp1 -> info == temp2 -> info)
            {
                prev -> link = temp2 -> link;
                free(temp2);
                temp2 = prev -> link;
                continue;
            }
            prev = temp2;
            temp2 = temp2 -> link;
        }
        temp1 = temp1 -> link;
    } 
    return first;
}

int main()
{
    NODE first = NULL;
    int choice, item;
    for(;;)
    {
        printf("\n1:Insert in list\t2:Display list\t3:Remove duplicates\t4:Exit\n");
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
                first = removeDuplicate(first);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}