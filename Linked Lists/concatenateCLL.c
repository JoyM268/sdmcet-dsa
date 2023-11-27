//Write a C program to concatenate two circular linked list
#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *link;
};
typedef struct node *NODE;

void display(NODE tail)
{
    NODE temp;
    if(tail == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        temp = tail -> link;
        while(temp -> link != tail -> link)
        {
            printf("%d --> ", temp -> info);
            temp = temp -> link;
        }
        printf("%d -->\n", temp -> info);
    }
}

NODE concatenateCLL(NODE list1, NODE list2)
{
    NODE p;
    if(list2 == NULL) 
        return list1;
    if(list1 == NULL)
        return list2;
    p = list1 -> link;
    list1 -> link = list2 -> link;
    list2 -> link = p;
    list1 = list2;
    printf("Concatenated List is:\n");
    display(list1);
    return list1;
}

NODE insertAtEnd(NODE tail)
{
    NODE newNode = (NODE)malloc(sizeof(struct node));
    printf("Enter the element to be inserted: ");
    scanf("%d", &newNode -> info);
    if(tail == NULL)
    {
        tail = newNode;
        tail -> link = newNode;
    }
    else
    {
        newNode -> link = tail -> link;
        tail -> link = newNode;
        tail = newNode;
    }
    return tail;
}

int main()
{
    int choice;
    NODE list1 = NULL, list2 = NULL;
    for(;;)
    {
        printf("\n1.Insert in list 1\t2.Insert in list 2\t3.Display list 1\t4.Display list 2\t5.Concatenate lists\t6.Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                list1 = insertAtEnd(list1);
                break;
            case 2:
                list2 = insertAtEnd(list2);
                break;
            case 3:
                display(list1);
                break;
            case 4:
                display(list2);
                break;
            case 5:
                list1 = concatenateCLL(list1, list2);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}