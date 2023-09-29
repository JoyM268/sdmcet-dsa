#include<stdio.h>
#include<ctype.h>
#define SIZE 20

struct stack{
    char stk[SIZE];
    int top;
};

void push(struct stack *s, char ele)
{
    s -> stk[++(s -> top)] = ele;
}

int pop(struct stack *s)
{
    return (s -> stk[(s -> top)--]);
}

int precedence(char operator)
{
    switch(operator)
    {
        case '(': return 1;
        case '+':
        case '-': return 2;
        case '*':
        case '/': 
        case '%': return 3;
    }
}

main()
{
    struct stack s;
    s.top = -1;
    char infix[SIZE], postfix[SIZE], ch, c;
    int i = 0, j = 0;
    printf("Enter a valid infix expression: ");
    scanf("%s", infix);
    while(infix[i] != 0)
    {
        ch = infix[i++];
        if(ch == '(')
        {
            push(&s, ch);
        }
        else if(isalpha(ch) || isdigit(ch))
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
    printf("Postfix of infix expression is %s = %s\n", infix, postfix);
}