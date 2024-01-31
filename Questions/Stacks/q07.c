/* Convert the following given infix expressions to postfix and prefix expressions respectively.  
i. A+B*(C-(D/E)^G) 
ii. F-(K/(H*S)^J)+X 
Also write a C function void conversion_infix_to_postfix(struct stack *s, char infix[]), to convert infix expression to postfix expression.*/

/* Answers:
i. Postfix: ABCDE/G^-*+
   Prefix: +A*B-C^/DEG
ii. Postfix: FKHS*J^/-X+
    Prefix: +-F/K^*HSJX
*/ 

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define SIZE 100

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

void conversion_infix_to_postfix(struct stack *s, char infix[])
{
    int i = 0, j = 0;
    char ch, c, postfix[SIZE];
    while(infix[i] != '\0')
    {
        ch = infix[i++];
        if(ch == '(')
            push(s, ch);
        else if(isalnum(ch))
            postfix[j++] = ch;
        else if(ch == ')')
        {
            while((c = pop(s)) != '(')
                postfix[j++] = c;
        }
        else
        {
            while(s -> top != -1 && precedence(ch) <= precedence(s -> stk[s -> top]))
                postfix[j++] = pop(s);
            push(s, ch);
        }
    }
    while(s -> top != -1)
        postfix[j++] = pop(s);
    postfix[j] ='\0';
    printf("Postfix expression for the infix expression %s is %s\n", infix, postfix);
}

int main()
{
    struct stack s;
    s.top = -1;
    char infix[SIZE];
    printf("Enter a valid infix expression: ");
    scanf("%s", infix);
    conversion_infix_to_postfix(&s, infix);
    return 0;
}