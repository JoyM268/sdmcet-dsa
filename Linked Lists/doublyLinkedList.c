//Write a C program to perform different operations on doubly linked list
//1.Insert 2.Delete 3.Display
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

NODE insertFrontDLL(NODE first, int ele)
{
    NODE temp = createNode();
    temp -> info = ele;
    temp -> right = NULL;
    temp -> left = NULL;
    printf("%d\n", temp -> info);
    if(first == NULL)
    {
        return temp;
    }
    else
    {
        temp -> right = first;
        first -> left = temp;
        temp -> left = NULL;
        return temp;
    }
}

NODE insertRearDLL(NODE first, int ele)
{
    NODE temp = createNode();
    temp -> info = ele;
    temp -> right = NULL;
    temp -> left = NULL;
    if(first == NULL)
    {
        printf("1st node inserted\n");
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

NODE deleteFrontDLL(NODE first)
{
    if(first == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    else if(first -> right == NULL)
    {
        printf("Deleted element is %d\n", first -> info);
        free(first);
        return NULL;
    }
    else
    {
        NODE cur = first;
        first = first -> right;
        printf("Deleted element is %d\n", cur -> info);
        free(cur);
        first -> left = NULL;
        return first;
    }
}

int main()
{
    NODE first = NULL;
    int choice, ele;
    for(;;)
    {
        printf("\n1.Insert front\t2.Insert rear\t3.Display\t4.Delete front\t5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter element to be inserted: ");
                scanf("%d", &ele);
                first = insertFrontDLL(first, ele);
                break;
            case 2:
                printf("Enter element to be inserted: ");
                scanf("%d", &ele);
                first = insertRearDLL(first, ele);
                break;
            case 3:
                display(first);
                break;
            case 4:
                first = deleteFrontDLL(first);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}