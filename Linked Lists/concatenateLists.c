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

NODE insertRearSLL(NODE first, int item)
{
    NODE temp = createNode();
    temp -> info = item;
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

void displaySLL(NODE first)
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

NODE concatenateList(NODE first, NODE second)
{
    if(first == NULL)
    {
        return second;
    }
    else if(second == NULL)
    {
        return first;
    }
    else
    {
        NODE temp = first;
        while(temp -> link != NULL)
        {
            temp = temp -> link;
        }
        temp -> link = second;
    }
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
            first = insertRearSLL(first, item);
            break;
        case 2:
            printf("Enter the element to be inserted: ");
            scanf("%d", &item);
            second = insertRearSLL(second, item);
            break;
        case 3:
            displaySLL(first);
            break;
        case 4:
            displaySLL(second);
            break;
        case 5:
            first = concatenateList(first, second);
            second = NULL;
            printf("List first and second concatenated\n");
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}