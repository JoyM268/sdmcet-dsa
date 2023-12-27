//Write a C program to construct an expression tree for a given postfix expression and evaluate the expression and print the result.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define SIZE 50

struct node{
    char data;
    struct node *left, *right;
};
typedef struct node *NODE;

NODE createNode(char item)
{
    NODE root = (NODE)malloc(sizeof(struct node));
    root -> data = item;
    root -> left = NULL;
    root -> right = NULL;
    return root;
}

NODE constructBinaryExpTree(char postfix[])
{
    char ch;
    NODE temp, stack[SIZE];
    int i, len = strlen(postfix), top = -1;
    for(i = 0; i < len; i++)
    {
        ch = postfix[i];
        temp = createNode(ch);
        if(isalnum(ch))
        {
            stack[++top] =  temp;
        }
        else
        {
            temp -> right = stack[top--];
            temp -> left = stack[top--];
            stack[++top] = temp;
        }
    }
    return stack[top--];
}

float evaluateExpTree(NODE root)
{
    if(root == NULL) return 0;
    float num;
    float op1 = evaluateExpTree(root -> left);
    float op2 = evaluateExpTree(root -> right);
    switch(root -> data)
    {
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/': return op1 / op2;
        default:
            if(isalpha(root -> data))
            {
                printf("Enter value of %c: ", root -> data);
                scanf("%f", &num);
                return num;
            }
            else
                return root -> data - '0';
    }
}

void inorderPrint(NODE root)
{
    if(root == NULL) return;
    inorderPrint(root -> left);
    printf("%c", root -> data);
    inorderPrint(root -> right);
}


void preorderPrint(NODE root)
{
    if(root == NULL) return;
    printf("%c", root -> data);
    preorderPrint(root -> left);
    preorderPrint(root -> right);
}


void postorderPrint(NODE root)
{
    if(root == NULL) return;
    postorderPrint(root -> left);
    postorderPrint(root -> right);
    printf("%c", root -> data);
}

int main()
{
    char postfix[SIZE];
    printf("Enter a valid postfix expression: ");
    scanf("%s", postfix);
    NODE root = constructBinaryExpTree(postfix);
    printf("\nInorder:\n");
    inorderPrint(root);
    printf("\nPreorder:\n");
    preorderPrint(root);
    printf("\nPostorder:\n");
    postorderPrint(root);
    printf("\n");
    printf("The result of the expression is: %.2f\n", evaluateExpTree(root));
}