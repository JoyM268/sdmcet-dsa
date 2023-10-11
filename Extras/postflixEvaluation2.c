//Program to evaluate postfix expression (multi digit numbers)
#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
#define SIZE 1000

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
    int i = 0, res, num1, num2, num, len;
    printf("Enter a valid postfix expression: ");
    scanf("%[^\n]", postfix);
    len = strlen(postfix);
    for(i = 0; i < len; i++)
    {
        ch = postfix[i];
        if(ch == ' ') continue;
        else if(isdigit(ch))
        {
            num = 0;
            while(isdigit(postfix[i]))
            {
                num = num * 10 + (postfix[i] - '0');
                i++;
            }
            push(&s, num);
            i--;
        }
        else
        {
            num2 = pop(&s);
            num1 = pop(&s);
            res = evaluate(num1, ch, num2);
            push(&s, res);
        }
    }
    printf("The result of the evaluated postfix expression is: %d\n", pop(&s));
}
