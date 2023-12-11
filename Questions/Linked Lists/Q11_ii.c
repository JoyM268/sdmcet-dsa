//Program to form a list containing the union of the elements of two lists
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

NODE insertOrderedList(NODE list, int ele)
{
    NODE temp = createNode();
    temp -> info = ele;
    temp -> link = NULL;
    if(list == NULL)
    {
        return temp;
    }
    if(ele < list -> info)
    {
        temp -> link = list;
        return temp;
    }
    NODE cur = list, prev = NULL;
    while(cur != NULL && ele > cur -> info)
    {
        prev = cur;
        cur = cur -> link;
    }
    prev -> link = temp;
    temp -> link = cur;
    return list;
}

void displayList(NODE List)
{
    if(List == NULL)
    {
        printf("List is empty\n");
        return;
    }
    else
    {
        NODE cur = List;
        while(cur != NULL)
        {
            printf("%d --> ", cur -> info);
            cur = cur -> link;
        }
        printf("NULL\n");
    }
}

int searchElement(NODE list, int ele)
{
    while(list != NULL)
    {
        if(list -> info == ele)
            return 1;
        list = list -> link;
    }
    return 0;
}

void unionOfList(NODE list1, NODE list2)
{
    NODE unionList = NULL;
    while(list1 != NULL)
    {
        if(!searchElement(unionList, list1 -> info))
            unionList = insertOrderedList(unionList, list1 -> info);
        list1 = list1 -> link;
    }
    while(list2 != NULL)
    {
        if(!searchElement(unionList, list2 -> info))
            unionList = insertOrderedList(unionList, list2 -> info);
        list2 = list2 -> link;
    }
    printf("The union list is:\n");
    displayList(unionList);
}

int main()
{
    NODE list1 = NULL, list2 = NULL;
    int choice, item;
    for(;;)
    {
        printf("\n1.Insert in List 1\t2.Insert in List 2\t3.Display List 1\t4.Display List 2\t5.Union of lists\t6.Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to be inserted: ");
            scanf("%d", &item);
            list1 = insertOrderedList(list1, item);
            break;
        case 2:
            printf("Enter the element to be inserted: ");
            scanf("%d", &item);
            list2 = insertOrderedList(list2, item);
            break;
        case 3:
            displayList(list1);
            break;
        case 4:
            displayList(list2);
            break;
        case 5:
            unionOfList(list1, list2);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}