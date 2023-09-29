#include<stdio.h>
#include<ctype.h>
#define SIZE 20

struct stack{
    char stk[SIZE];
    int top;
};

void push(struct stack *s, char item)
{
    s -> stk[++(s -> top)] = item;
}

int pop(struct stack *s)
{
    return s -> stk[s -> top--];
}

int precedence(char operator)
{
    switch(operator)
    {
        case '(': return 1;
        case '+':
        case '-': return 2;
        case '*':
        case '/': return 3;
    }
}

main()
{
    struct stack s;
    s.top = -1;
    int i = 0, j = 0;
    char infix[SIZE], postfix[SIZE], ch;
    printf("Enter a valid infix expression: ");
    scanf("%s", infix);
    while(infix[i])
    {
        ch = infix[i++];
        if(ch == '(')
        {
            push(&s, ch);
        }
        else if(isalnum(ch))
        {
            postfix[j++] = ch;
        }
        else if(ch == ')')
        {
            while((ch = pop(&s)) != '(')
            {
                postfix[j++] = ch;
            }
        }
        else
        {
            while(precedence(ch) <= precedence(s.stk[s.top]) && s.top != -1)
            {
                postfix[j++] = pop(&s);
            }
            push(&s, ch);
        }
    }
    while(s.top != -1)
    {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
    printf("The converted postfix expression is %s\n", postfix);
}