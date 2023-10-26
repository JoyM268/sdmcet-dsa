// Write a C program to convert a valid parenthesized infix expression to prefix expression. (Expression includes operators +, -, * and /)
#include<stdio.h>
#include<string.h>
#include<ctype.h>
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
    return (s -> stk[(s -> top)--]);
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
        case '^': return 4;
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

int main()
{
    struct stack s;
    s.top = -1;
    char infix[SIZE], prefix[SIZE], ch, c;
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
        else if(isdigit(ch) || isalpha(ch))
        {
            prefix[j++] = ch;
        }
        else if(ch == '(')
        {
            while((c  = pop(&s)) != ')')
            {
                prefix[j++] = c;
            }
        }
        else
        {
            while(s.top != -1 && precedence(ch) < precedence(s.stk[s.top]))
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
    printf("The prefix of infix expresion %s is %s\n", infix, prefix);
    return 0;
}
