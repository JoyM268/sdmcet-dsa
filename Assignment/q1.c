//Program to convert infix to prefix expression
#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
#define SIZE 100

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
    return (s -> stk[s -> top--]);
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

void changeParenthesis(char *str)
{
    int i, len = strlen(str);
    for(i = 0; i < len; i++)
    {
        if(str[i] == '(')
        {
            str[i] = ')';
        }
        else if(str[i] == ')')
        {
            str[i] = '(';
        }
    }
}

int main()
{
    struct stack s;
    s.top = -1;
    int i = 0, j = 0;
    char infix[SIZE], prefix[SIZE], ch, c;
    printf("Enter a valid infix expression: ");
    scanf("%s", infix);
    reverse(infix);
    changeParenthesis(infix);
    while(infix[i])
    {
        ch = infix[i++];
        if(ch == '(')
        {
            push(&s, ch);
        }
        else if(isalpha(ch) || isdigit(ch))
        {
            prefix[j++] = ch;
        }
        else if(ch == ')')
        {
            while((c = pop(&s)) != '(')
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
    printf("The prefix expression is: %s\n", prefix);
    return 0;
}