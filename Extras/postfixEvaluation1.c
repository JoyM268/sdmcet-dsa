//Program to evaluate postfix expression (only single digit numbers)
#include<stdio.h>
#include<ctype.h>
#include<math.h>
#define SIZE 20

struct stack{
    int stk[SIZE];
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

int evaluate(int num1, char operator, int num2)
{
    switch(operator)
    {
        case '^': return pow(num1, num2);
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case '*': return num1 * num2;
        case '/': return num1 / num2;
    }
}

main()
{
    struct stack s;
    s.top = -1;
    char postfix[SIZE], ch;
    int i = 0, res, num1, num2;
    printf("Enter a valid postfix expression: ");
    scanf("%s", postfix);
    while(postfix[i])
    {
        ch = postfix[i];
        if(isdigit(ch))
        {
            push(&s, ch - '0');
        }
        else
        {
            num2 = pop(&s);
            num1 = pop(&s);
            res = evaluate(num1, ch, num2);
            push(&s, res);
        }
        i++;
    }
    printf("The result of the evaluated postfix expression is: %d\n", pop(&s));
}