//Write a c function int Balance_expression(struct stack *s, char exp []) to check whether the given input expression is balanced expression or not.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 50

struct stack{
    char stk[SIZE];
    int top;
};

void push(struct stack *s, int item)
{
    s -> stk[++(s -> top)] = item;
}

int pop(struct stack *s)
{
    return s -> stk[(s -> top)--];
}

int checkMatch(char a, char b)
{
    return ((a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']'));
}

int Balance_expression(struct stack *s, char exp[])
{
    int len = strlen(exp), i, popItem;
    for(i = 0; i < len; i++)
    {
        if(exp[i] == '{' || exp[i] == '[' || exp[i] == '(')
            push(s, exp[i]);
        else if(exp[i] == '}' || exp[i] == ')' || exp[i] == ']')
        {
            if(s -> top == -1)
            {
                printf("Right parenthesis more than left parenthesis\n");
                return 0;
            }
            popItem = pop(s);
            if(!checkMatch(popItem, exp[i]))
            {
                printf("Mismatch parenthesis\n");
                printf("%c and %c\n", popItem, exp[i]);
                return 0;
            }
        }
    }
    if(s -> top != -1)
    {
        printf("Left parenthesis more than right parenthesis\n");
        return 0;
    }
    return 1;
}

int main()
{
    struct stack s;
    s.top = -1;
    char exp[SIZE];
    printf("Enter the expression: ");
    scanf("%s", exp);
    if(Balance_expression(&s, exp))
        printf("The expression %s is balanced\n");
    else
        printf("The expression %s is unbalanced\n");
    return 0;
}