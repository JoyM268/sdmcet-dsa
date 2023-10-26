//Write a C program to evaluate a given valid prefix expression. (Expression includes operators +, -, * and /)
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#define SIZE 50

struct stack{
    int stk[SIZE], top;
};

void push(struct stack *s, int ele)
{
    s -> stk[++(s -> top)] = ele;
}

int pop(struct stack *s)
{
    return (s -> stk[(s -> top)--]);
}

int evaluate(int op1, char op, int op2)
{
    switch(op)
    {
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/': return op1 / op2;
        case '^': return pow(op1, op2);
    }
}

int main()
{
    char prefix[SIZE], ch;
    struct stack s;
    s.top = -1;
    int len, i, op1, op2, result;
    printf("Enter a valid prefix expression: ");
    scanf("%s", prefix);
    len = strlen(prefix);
    for(i = len - 1; i >= 0; i--)
    {
        ch = prefix[i];
        if(isdigit(ch))
        {
            push(&s, ch - '0');
        }
        else
        {
            op1 = pop(&s);
            op2 = pop(&s);
            result = evaluate(op1, ch, op2);
            push(&s, result);
        }
    }
    printf("Result of evaluated prefix expression %s is %d\n", prefix, pop(&s));
    return 0;
}