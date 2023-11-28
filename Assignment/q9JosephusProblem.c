//Josephus Problem
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 30
struct node{
    char name[SIZE];
    struct node *next;
};

struct node *insertName(struct node *tail, char *name)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp -> next = NULL;
    strcpy(temp -> name, name);
    if(tail == NULL)
    {
        temp -> next = temp;
        return temp;
    }   
    temp -> next = tail -> next;
    tail -> next = temp;
    return temp;
}

struct node *create(struct node *tail)
{
    int n, i;
    char name[SIZE];
    printf("Enter the number of soldiers: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        printf("Enter the name of soldier %d: ", i + 1);
        scanf("%s", name);
        tail = insertName(tail, name);
    }
    return tail;
}

void eliminateSoldier(struct node *tail, int n)
{
    int i;
    struct node *cur = tail -> next, *prev = tail;
    while(cur -> next != cur)
    {
        for(i = 0; i < n - 1; i++)
        {
            prev = cur;
            cur = cur -> next;
        }
        prev -> next = cur -> next;
        printf("%s has been eliminated\n", cur -> name);
        free(cur);
        cur = prev -> next;
    }
    printf("The soldier who escapes is: %s\n", cur -> name);
}

void display(struct node *tail)
{
    struct node *temp = tail -> next;
    if(tail == NULL)
    {
        printf("No soldiers\n");
        return;
    }
    while(temp -> next != tail -> next)
    {
        printf("%s -> ", temp -> name);
        temp = temp -> next;
    }
    printf("%s -> ", temp -> name);
}

int main()
{
    int n;
    struct node *tail = NULL;
    tail = create(tail);
    printf("\nThe soldiers are:\n");
    display(tail);
    printf("\n\nEnter the value of n: ");
    scanf("%d", &n);
    printf("\n");
    eliminateSoldier(tail, n);
    return 0;
}