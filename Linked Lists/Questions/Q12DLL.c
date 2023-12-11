//Write a C program to concatenate two doubly linked lists and display the result. 
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

NODE concatenateDLL(NODE first, NODE second)
{
    NODE cur = first;
    if(first == NULL)
    {
        display(second);
        return second;
    }
    if(second == NULL)
    {
        display(first);
        return first;
    }
    while(cur -> right != NULL)
    {
        cur = cur -> right;
    }
    cur -> right = second;
    second -> left = cur;
    display(first);
    return first;
}

int main()
{
    NODE first = NULL, second = NULL;
    int choice, ele;
    for(;;)
    {
        printf("\n1.Insert in list 1\t2.Insert in list 2\t3.Display list 1\t4.Display list 2\t5.Concatenate lists\t6.Exit\n");
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
                printf("Enter element to be inserted: ");
                scanf("%d", &ele);
                second = insertRearDLL(second, ele);
                break;
            case 3:
                display(first);
                break;
            case 4:
                display(second);
                break;
            case 5:
                first = concatenateDLL(first, second);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}