//Write a C program to implement different operations of singly linked list.
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

//Write a C module to create a list of nodes by inserting an element at front end.
NODE insert_front_sll(NODE first, int ele)
{
    NODE temp = createNode();
    temp -> info = ele;
    printf("--> %d\n", temp -> info);
    temp -> link = first;
    return temp;
}

//Write a C module to create a list of nodes by inserting an element at rear end.
NODE insert_rear_sll(NODE first, int ele)
{
    NODE temp = createNode();
    temp -> info = ele;
    temp -> link = NULL;
    if(first == NULL)
    {
        printf("First node to the list is inserted\n");
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

//Write a C module to print the list.
void display_sll(NODE first)
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

//Write a C module to delete the node from the front end
NODE delete_front_sll(NODE first)
{
    if(first == NULL)
    {
        printf("No elements in the list to delete\n");
        return NULL;
    }
    else if(first -> link == NULL)
    {
        printf("Deleted element is %d\n", first -> info);
        free(first);
        return NULL;
    }
    else
    {
        NODE cur = first;
        first = first -> link;
        printf("Deleted element is %d\n", cur -> info);
        free(cur);
        return first;
    }
}

//Write a C module to delete the node from the rear end
NODE delete_rear_sll(NODE first)
{
    if(first == NULL)
    {
        printf("No elements in the list to delete\n");
        return NULL;
    }
    else if(first -> link == NULL)
    {
        printf("Deleted element is %d\n", first -> info);
        free(first);
        return NULL;
    }
    else
    {
        NODE prev = NULL, cur = first;
        while(cur -> link != NULL)
        {
            prev = cur;
            cur = cur -> link;
        }        
        printf("Deleted element is %d\n", cur -> info);
        free(cur);
        prev -> link = NULL;
        return first;
    }
}

int main()
{
    NODE first = NULL;
    int choice, ele;
    for(;;)
    {
        printf("\n1.Insert front\t2.Insert rear\t3.Display\t4.Delete front\t5.Delete rear\t6.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter element to be inserted: ");
                scanf("%d", &ele);
                first = insert_front_sll(first, ele);
                break;
            case 2:
                printf("Enter element to be inserted: ");
                scanf("%d", &ele);
                first = insert_rear_sll(first, ele);
                break;
            case 3:
                display_sll(first);
                break;
            case 4:
                first = delete_front_sll(first);
                break;
            case 5:
                first = delete_rear_sll(first);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}