//Write a C program to insert a element after the given key in a doubly linked list
#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *left, *right;
};

typedef struct node *NODE;

NODE createNode()
{
    NODE ptr = (NODE)malloc(sizeof(struct node));
    return ptr;
}

NODE insertRight(NODE first, int item)
{
    NODE temp, cur, next;
    int ele;
    if(first == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    cur = first;
    while(cur != NULL)
    {
        if(item == cur -> info)
        {
            break;
        }
        cur = cur -> right;
    }
    if(cur == NULL)
    {
        printf("Key not found\n");
        return first;
    }
    next = cur -> right;
    printf("Enter element to be inserted: ");
    scanf("%d", &ele);
    temp = createNode();
    temp -> info = ele;
    cur -> right = temp;
    temp -> left = cur;
    temp -> right = next;
    if(next != NULL)
        next -> left = temp;
    return first;
}

NODE insertRearDLL(NODE first, int ele)
{
    NODE temp = createNode();
    temp -> info = ele;
    temp -> right = NULL;
    temp -> left = NULL;
    if(first == NULL)
    {
        return temp;
    }
    else
    {
        NODE cur = first;
        while(cur -> right != NULL)
        {
            cur = cur -> right;
        }
        temp -> left = cur;
        cur -> right = temp;
        temp -> right = NULL;
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
            cur = cur -> right;
        }
        printf("NULL\n");
    }
}

int main()
{
    NODE first = NULL;
    int choice, ele;
    for(;;)
    {
        printf("\n1.Insert rear\t2.Display\t3.Insert right\t4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter element to be inserted: ");
                scanf("%d", &ele);
                first = insertRearDLL(first, ele);
                break;
            case 2:
                display(first);
                break;
            case 3:
                printf("Enter the key: ");
                scanf("%d", &ele);
                first = insertRight(first, ele);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}