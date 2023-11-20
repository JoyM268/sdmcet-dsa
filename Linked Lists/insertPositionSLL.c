//Write a C program to insert a element at a position in linked list
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

NODE insertPositionSLL(NODE first, int pos, int ele)
{
    NODE prev, cur;
    int count;
    NODE temp = createNode();
    temp -> info = ele;
    temp -> link = NULL;
    if(first == NULL && pos == 1)
        return temp;
    count = 1;
    prev = NULL;
    cur = first;
    while(cur != NULL && count != pos)
    {
        prev = cur;
        cur = cur -> link;
        count++;
    }
    if(count == pos)
    {
        temp -> link = cur;
        if(cur == first)
            first = temp;
        else
            prev -> link = temp;
        return first;
    }
    if(cur == NULL && pos != count)
    {
        printf("Invalid position\n");
        return first;
    }
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
    int item, choice, pos;
    for(;;)
    {
        printf("\n1.Insert at rear\t2.Insert at position\t3.Display\t4.Exit\n");
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
                printf("Enter the position: ");
                scanf("%d", &pos);
                first = insertPositionSLL(first, pos, item);
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