//Write a C program to convert a valid infix expression to postfix expression. (Expression includes operators +, -, * and /)
#include<stdio.h>
#include<ctype.h>
#define SIZE 30

struct stack{
    char stk[SIZE];
    int top;
};

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

void push(struct stack *s, char item)
{
    s -> stk[++(s -> top)] = item;
}

char pop(struct stack *s)
{
    return (s -> stk[(s -> top)--]);
}

int main()
{
    char postfix[SIZE], infix[SIZE], ch, c;
    int i = 0, j = 0;
    struct stack s;
    s.top = -1;
    printf("Enter a valid infix expression: ");
    scanf("%s", infix);
    while(infix[i] != 0)
    {
        ch = infix[i++];
        if(ch == '(')
        {
            push(&s, ch);
        }
        else if(isdigit(ch) || isalpha(ch))
        {
            postfix[j++] = ch;
        }
        else if(ch == ')')
        {
            while((c = pop(&s)) != '(')
            {
                postfix[j++] = c;
            }
        }
        else
        {
            while(s.top != -1 && precedence(ch) <= precedence(s.stk[s.top]))
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
    printf("Postfix of infix expression %s is %s\n", infix, postfix);
    return 0;
}