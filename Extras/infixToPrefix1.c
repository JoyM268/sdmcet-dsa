//Program to convert infix to prefix expression
//Method 1
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define SIZE 50

struct stack{
    char stk[SIZE];
    int top;
};

void push(struct stack *s, char item)
{
    s -> stk[++(s -> top)] = item;
}

char pop(struct stack *s)
{
    return s -> stk[(s -> top)--];
}

int precedence(char operator)
{
    switch(operator)
    {
        case ')': return 1;
        case '+':
        case '-': return 2;
        case '*':
        case '/': return 3;
    }
}

void swap(char *ch1, char *ch2)
{
    char temp = *ch1;
    *ch1 = *ch2;
    *ch2 = temp;
}

void reverse(char *str)
{
    int i, len = strlen(str);
    for(i = 0; i < len/2; i++)
    {
        swap(&str[i], &str[len - i - 1]);
    }
}

main()
{
    char prefix[SIZE], infix[SIZE], ch;
    struct stack s;
    s.top = -1;
    int i, j = 0, len;
    printf("Enter a valid infix expression: ");
    scanf("%s", infix);
    len = strlen(infix);
    for(i = len - 1; i >= 0; i--)
    {
        ch = infix[i];
        if(ch == ')')
        {
            push(&s, ch);
        }
        else if(isalnum(ch))
        {
            prefix[j++] = ch;
        }
        else if(ch == '(')
        {
            while((ch = pop(&s)) != ')')
            {
                prefix[j++] = ch;
            }
        }
        else
        {
            while(precedence(ch) < precedence(s.stk[s.top]) && s.top != -1)
            {
                prefix[j++] = pop(&s);
            }
            push(&s, ch);
        }
    }
    while(s.top != -1)
    {
        prefix[j++] = pop(&s);
    }
    prefix[j] = '\0';
    reverse(prefix);
    printf("The prefix expression is: %s\n", prefix);
}