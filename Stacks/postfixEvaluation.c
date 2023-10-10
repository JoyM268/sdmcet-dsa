//Write a C program to evaluate a given valid postfix expression using stack implementation
#include<stdio.h>
#include<ctype.h>
#include<math.h>
#define SIZE 20

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
    int i = 0, result, op1, op2;
    char ch, postfix[SIZE];
    struct stack s;
    s.top = -1;
    printf("Enter valid infix expression: ");
    scanf("%s", postfix);
    while(postfix[i] != '\0')
    {
        ch = postfix[i++];
        if(isdigit(ch))
        {
            push(&s, ch - '0');
        }
        else
        {
            op2 = pop(&s);
            op1 = pop(&s);
            result = evaluate(op1, ch, op2);
            push(&s, result);
        }
    }
    printf("Result of evaluated postfix expression %s is %d\n", postfix, pop(&s));
}