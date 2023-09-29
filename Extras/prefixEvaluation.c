#include<stdio.h>
#include<ctype.h>
#include<string.h>
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
    return (s -> stk[(s -> top)--]);
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
    char prefix[SIZE], ch;
    int i, len, num1, num2, res;
    printf("Enter a valid prefix expression: ");
    scanf("%s", prefix);
    len = strlen(prefix);
    for(i = len - 1; i >= 0; i--)
    {
        ch = prefix[i];
        if(isdigit(ch))
        {
            push(&s, (ch - '0'));
        }
        else
        {
            num1 = pop(&s);
            num2 = pop(&s);
            res = evaluate(num1, ch, num2);
            push(&s, res);
        }
    }
    printf("Result of the evaluated prefix expresion is: %d\n", pop(&s));
}