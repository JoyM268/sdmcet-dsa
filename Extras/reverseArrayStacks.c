//Program to reverse a string using stack
#include<stdio.h>
#include<string.h>
#define SIZE 50

struct stack{
    int stk[SIZE];
    int top;
} s;

void push(int item)
{
    if(s.top == SIZE - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    s.stk[++s.top] = item;
}

int pop()
{
    if(s.top == -1)
    {
        printf("Stack underflow\n");
        return -1;
    }
    return s.stk[s.top--];
}

void reverseString(char *str)
{
    int len = strlen(str), i;
    for(i = 0; i < len; i++)
    {
        push(str[i]);
    }
    i = 0;
    while(s.top != -1)
    {
        str[i] = pop();
        i++;
    }
}

main()
{
    s.top = -1;
    char str[SIZE];
    printf("Enter a input string: ");
    scanf("%[^\n]", str);
    reverseString(str);
    printf("Reversed string: %s\n", str);
}