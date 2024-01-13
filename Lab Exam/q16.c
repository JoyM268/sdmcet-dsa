/* Write a c function search(l,x) that accepts a pointer ‘l’ to a list of integers and an integer x and returns a pointer to a node containing x, 
if it exists and the null pointer otherwise. Write another function srchinsrt(l,x), that adds ‘x’ to ‘l’ if it is not found and always returns a 
pointer to a node containing ‘x’. Develop C program for the same. */
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
    NODE cur = first;
    while(cur -> link != NULL)
    {
        cur = cur -> link;
    }
    cur -> link = temp;
    return first;
}

NODE insertAtBegin(NODE first, int ele)
{
    NODE temp = createNode();
    temp -> info = ele;
    temp -> link = first;
    return temp;
}

void displayList(NODE first)
{
    if(first == NULL)
    {
        printf("List is empty\n");
        return;
    }
    NODE cur = first;
    while(cur != NULL)
    {
        printf("%d --> ", cur -> info);
        cur = cur -> link;
    }
    printf("NULL\n");
}

NODE search(NODE l, int x)
{
    while(l != NULL)
    {
        if(l -> info == x)
            return l;
        l = l -> link;
    }
    return NULL;
}

NODE searchInsert(NODE l, int x)
{
    NODE node = search(l, x);
    if(node)
    {
        printf("%d exists in the list\n", node -> info);
        return l;
    }
    printf("%d does not exist in the list\n", x);
    l = insertAtBegin(l, x);
    printf("%d inserted into the list\n", l -> info);
    return l;
}

int main()
{
    NODE first = NULL;
    int choice, item;
    for(;;)
    {
        printf("\n1:Insert in list\t2:Display list\t3:Search Element\t4:Insert Search\t5:Exit\n");
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
                printf("Enter the key element: ");
                scanf("%d", &item);
                if(search(first, item))
                    printf("%d found\n", item);
                else
                    printf("%d not found\n", item);
                break;
            case 4:
                printf("Enter the key element: ");
                scanf("%d", &item);
                first = searchInsert(first, item);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
} 