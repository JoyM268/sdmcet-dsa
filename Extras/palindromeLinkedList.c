//Program to check if the contents of linked list forms a palindrome or not
#include<stdio.h>
#include<stdlib.h>

typedef enum {false, true} bool;

typedef struct node{
    char data;
    struct node *next;
} node;

node *createNode(char data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp -> data = data;
    temp -> next = NULL;
    return temp;
}

node *insertAtEnd(node *head, char ele)
{
    node *temp1 = createNode(ele);
    if(head == NULL)
    {
        return temp1;
    }
    node *temp2 = head;
    while(temp2 -> next != NULL)
    {
        temp2 = temp2 -> next;
    }
    temp2 -> next = temp1;
    return head;
}

node *middleNode(node *head)
{
    node *slow, *fast;
    slow = fast = head;
    while(fast -> next != NULL && fast -> next -> next != NULL)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}

node *reverse(node *head)
{
    node *prev = NULL;
    node *curr = head;
    node *end;
    while(curr != NULL)
    {
        end = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = end;
    }
    return prev;
}

bool isPalindrome(node *head)
{
    node *mid = middleNode(head);
    mid -> next = reverse(mid -> next);
    mid = mid -> next;
    while(mid != NULL)
    {
        if(head -> data != mid -> data)
        {
            return false;
        }
        head = head -> next;
        mid = mid -> next;
    }
    return true;
}

node *stringToList(char *str)
{
    node *head = NULL;
    while(*str)
    {
        head = insertAtEnd(head, *str);
        str++;
    }
    return head;
}

int main()
{
    char str[50];
    printf("Enter the input data: ");
    scanf("%s", str);
    node *head = stringToList(str);
    if(isPalindrome(head))
    {
        printf("The contents of list forms a palindrome\n");
        return 0;
    }
    printf("The contents of list does not forms a palindrome\n");
    return 0;
}